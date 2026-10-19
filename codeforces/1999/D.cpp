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
const int N = 1e6+10;
int n,m;
char s[N],t[N];
int main(){
    int T = read();
    while(T--){
        cin >> (s+1) >> (t+1);
        n = strlen(s+1); m = strlen(t+1);
        int j = 1;
        for(int i=1;i<=n;i++){
            if(j > m) break;
            if(s[i] == '?' || s[i] == t[j]) s[i] = t[j],j++;
        }
        puts(j > m ? "YES" : "NO");
        if(j > m){
            for(int i=1;i<=n;i++){
                if(s[i] == '?') s[i] = 'a';
                cout << s[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
