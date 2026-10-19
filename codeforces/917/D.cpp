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
const int N = 110;
const int mod = 1e9+7;
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
int n;
ll M[N][N],a[N][N];
vector<pii> vec;
ll val[N];
ll det(){
    ll res = 1;
    for(int i=1;i<n;i++){
        if(!a[i][i]){
            for(int j=i+1;j<n;j++)
                if(a[j][i]){
                    swap(a[i],a[j]);
                    res = mod-res;
                    break;
                }
        }
        ll inv = fpow(a[i][i],mod-2);
        for(int j=i+1;j<n;j++){
            ll t = inv*a[j][i]%mod;
            for(int k=1;k<n;k++)
                a[j][k] = (a[j][k]-t*a[i][k]%mod+mod)%mod;
        }
    }
    for(int i=1;i<n;i++) res = res*a[i][i]%mod;
    return res;
}
ll solve(int x){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) a[i][j] = -1;
    for(int i=1;i<=n;i++) a[i][i] = n-1;
    for(auto it : vec){
        int u = it.fi,v = it.se;
        a[u][v] = a[v][u] = -x;
        a[u][u] += x-1;
        a[v][v] += x-1;
    }
    return det();
}
ll ans[N];
void guass(){
    for(int i=1;i<=n;i++){
        a[i][0] = i-1;
        a[i][1] = 1;
        for(int j=2;j<=n;j++)
            a[i][j] = a[i][j-1]*(i-1)%mod;
        a[i][n+1] = val[i-1];
    }
    for(int i=1;i<=n;i++){
        if(!a[i][i]){
            for(int j=i+1;j<=n;j++)
                if(a[j][i]){
                    swap(a[i],a[j]);
                    break;
                }
        }
        ll inv = fpow(a[i][i],mod-2);
        for(int j=1;j<=n+1;j++) a[i][j] = a[i][j]*inv%mod;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            ll t = a[j][i];
            for(int k=i;k<=n+1;k++)
                a[j][k] = (a[j][k]-t*a[i][k]%mod+mod)%mod;
        }
    }
    // for(int i=1;i<=n;i++,puts(""))
    //     for(int j=1;j<=n+1;j++) cout << a[i][j] << " ";
    for(int i=1;i<=n;i++) ans[a[i][0]] = a[i][n+1];
    for(int i=0;i<n;i++) cout << ans[i] << " ";
}
int main(){
    n = read();
	for(int i=1;i<n;i++){
        int u = read(),v = read();
        vec.push_back(mk(u,v));
    }
    for(int i=0;i<n;i++) val[i] = solve(i);
    guass();
    return 0;
}