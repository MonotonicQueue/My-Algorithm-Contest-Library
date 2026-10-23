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
const int N = 5e2+10;
const int mod = 998244353;
int n,m,c[N],cnt[N],pre[N];
ll fac[N],inv[N];
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
void init(int n = 5e2){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
	if(x < y) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
inline void add(ll &x,ll y){
	x = (x+y)%mod;
}
string opp;
ll f[2][N][N];
void solve(){
    n = read(); m = read();
	cin >> opp;
    for(int i=1;i<=n;i++) c[i] = read();
	for(int i=1;i<=n;i++) cnt[c[i]]++;
	pre[0] = cnt[0];
	for(int i=1;i<=n;i++) pre[i] = pre[i-1]+cnt[i];
	// for(int i=0;i<=n;i++) cout << pre[i] << " ";
	// cout << "\n";
	f[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		int op = i & 1;
		memset(f[op],0,sizeof(f[op]));
		for(int j=0;j<i;j++){
			for(int k=0;k<i;k++){
				if(!f[op^1][j][k]) continue;
				if(opp[i-1] == '0'){
					for(int l=0;l<=cnt[j+1];l++){
						add(f[op][j+1][k+l],f[op^1][j][k]*C(i-k-1,l)%mod*C(cnt[j+1],l)%mod*fac[l]%mod);
						add(f[op][j+1][k+l+1],f[op^1][j][k]*C(i-k-1,l)%mod*C(cnt[j+1],l+1)%mod*fac[l+1]%mod);
						add(f[op][j+1][k+l+1],f[op^1][j][k]*C(i-k-1,l)%mod*C(cnt[j+1],l)%mod*fac[l]%mod*C(pre[j]-k,1));
					}
				}else{
					add(f[op][j][k],f[op^1][j][k]);
					for(int l=0;l<=cnt[j+1];l++){
						add(f[op][j+1][k+l+1],f[op^1][j][k]*C(i-k-1,l)%mod*C(cnt[j+1],l)%mod*fac[l]%mod*C(pre[j]-k,1));
					}
				}
			}
		}
		// for(int j=0;j<=i;j++,puts(""))
		// 	for(int k=0;k<=i;k++) cout << f[op][j][k] << " ";
		// cout << "\n\n";
	}
	ll ans = 0;
	for(int i=0;i<=n-m;i++)
		add(ans,f[n&1][i][pre[i]]*fac[n-pre[i]]%mod);
	cout << ans << "\n";
}
int main(){
    init();
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
