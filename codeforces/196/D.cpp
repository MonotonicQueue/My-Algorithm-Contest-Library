#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 4e5+10;
const ull P = 13131;
int n,d;
char s[N];
ull hsh1[N],hsh2[N],pw[N];
bool chk(int x,int y){
    ull h1 = hsh1[y]-hsh1[x-1]*pw[y-x+1],h2 = hsh2[y]-hsh2[x-1];
    return h1*pw[x-1] == h2;
}
int main(){
    d = read();
    scanf("%s",s+1);
    n = strlen(s+1);
    pw[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*P;
    int bad = n;
    for(int i=1;i<=n;i++){
        hsh1[i] = hsh1[i-1]*P+s[i];
        hsh2[i] = hsh2[i-1]+s[i]*pw[i-1];
        if((i >= d+1 && chk(i-d,i)) || (i >= d && chk(i-d+1,i))){
            bad = i;
            break;
        }
    }
    // cout << bad << "\n";
    bool flag = false;
    for(int i=bad;i;i--){
        for(char c=s[i]+1;c<='z';c++){
            hsh1[i] = hsh1[i-1]*P+c;
            hsh2[i] = hsh2[i-1]+c*pw[i-1];
            if((i >= d+1 && chk(i-d,i)) || (i >= d && chk(i-d+1,i)))
                continue;
            s[i] = c;
            bad = i;
            flag = true;
            break;
        }
        if(flag) break;
    }
    if(!flag){
        puts("Impossible");
        return 0;
    }
    for(int i=bad+1;i<=n;i++){
        for(char c='a';c<='z';c++){
            hsh1[i] = hsh1[i-1]*P+c;
            hsh2[i] = hsh2[i-1]+c*pw[i-1];
            if((i >= d+1 && chk(i-d,i)) || (i >= d && chk(i-d+1,i)))
                continue;
            s[i] = c;
            bad = i;
            break;
        }
    }
    for(int i=1;i<=n;i++) cout << s[i];
	return 0;
}