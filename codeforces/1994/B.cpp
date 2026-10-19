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
const int N = 2e5+10;
int n;
char s[N],t[N];
bool chk(){
    cin >> s+1 >> t+1;
    bool flag = true;
    for(int i=1;i<=n;i++)
        if(s[i] != t[i]) flag = false;
    if(flag) return true;
    int ct1 = 0;
    for(int i=1;i<=n;i++) if(s[i] == '1'){
        ct1 = i; break;
    }
    if(!ct1) return false;
    for(int i=1;i<ct1;i++)
        if(s[i] != t[i]) return false;
    return true;
}
int main(){
    int T = read();
    while(T--){
        n = read();
        puts(chk() ? "YES" : "NO");
    }
	return 0;
}
