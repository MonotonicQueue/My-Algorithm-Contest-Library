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
const int N = 20;
const int S = 1<<18;
const int mod = 998244353;
ll fpow(ll x,ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
int n,Q,st,deg[N];
vector<int> G[N];
int cnt;
ll f[S],k[N],b[N];
void dfs(int x,int fa,int state){
    k[x] = b[x] = 0;
    ll sumk = 0,sumb = 0;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x,state);
        sumk = (sumk+k[y])%mod;
        sumb = (sumb+b[y])%mod;
    }
    if(!((state>>x) & 1)){
        ll p = (deg[x]-sumk+mod)%mod;
        p = fpow(p,mod-2);
        k[x] = p; b[x] = (sumb+deg[x])%mod*p%mod;
    }else cnt++;
}
int main(){
    n = read(); Q = read(); st = read()-1;
    for(int i=1;i<n;i++){
        int u = read()-1,v = read()-1;
        deg[u]++; deg[v]++;
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int s=0;s<(1<<n);s++){
        cnt = 0;
        dfs(st,-1,s);
        f[s] = b[st]*((cnt & 1) ? 1 : -1);
    }
    for(int i=0;i<n;i++)
        for(int s=1;s<(1<<n);s++)
            if((s >> i) & 1) f[s] = (f[s]+f[s^(1<<i)])%mod;
    while(Q--){
        int q = read(),x,s=0;
        while(q--) x = read(),s |= 1<<(x-1);
        cout << (f[s]%mod+mod)%mod << "\n";
    }
	return 0;
}
