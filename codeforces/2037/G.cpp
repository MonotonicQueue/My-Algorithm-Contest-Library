#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int mod = 998244353;
int n,a[N];
int pr[N],cnt,mu[N],vis[N];
void init(int n=1e6){
    mu[1] = 0;
    for(int i=2;i<=n;i++){
        if(!vis[i]) mu[i] = 1,pr[++cnt] = i;
        for(int j=1;j<=cnt&&pr[j]*i<=n;j++){
            vis[i*pr[j]] = true;
            if(i % pr[j] == 0) break;
            mu[i*pr[j]] = -mu[i];
        }
    }
}
ll d[N];
void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
    for(int j=1;j*j<=a[1];j++){
        if(a[1] % j == 0){
            d[j]++;
            if(j*j != a[1]) d[a[1]/j]++;
        }
    }
	for(int i=2;i<=n;i++){
        ll now = 0;
        for(int j=1;j*j<=a[i];j++){
            if(a[i] % j == 0){
                now += mu[j]*d[j];
                if(j*j != a[i]) now += mu[a[i]/j]*d[a[i]/j];
            }
        }
        now = (now%mod+mod)%mod;
        for(int j=1;j*j<=a[i];j++){
            if(a[i] % j == 0){
                add(d[j],now);
                if(j*j != a[i]) add(d[a[i]/j],now);
            }
        }
        if(i == n) cout << now << '\n';
	}
}
signed main(){
    init();
	int T = 1;
	while(T--) solve();
    return 0;
}
