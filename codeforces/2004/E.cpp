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
const int N = 1e7+10;
int n,m,a[N];
int pr[N],cnt;
int sg[N]; bool vis[N];
void init(int n = 1e7){
    sg[1] = 1;
    for(int i=2;i<=n;i++){
        if(!vis[i]) pr[++cnt] = i,sg[i] = cnt;
        if(i == 2) sg[i] = 0;
        for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
            sg[i*pr[j]] = sg[pr[j]];
            vis[i*pr[j]] = 1;
            if(i % pr[j] == 0) break;
        }
    }
}
void solve(){
    n = read();
    int ans = 0;
    for(int i=1;i<=n;i++) a[i] = read(),ans ^= sg[a[i]];
    puts(ans ? "Alice" : "Bob");
}
int main(){
    init();
    int T = read();
    while(T--) solve();
    return 0;
}
