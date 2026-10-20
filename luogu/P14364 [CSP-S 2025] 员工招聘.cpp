#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int> 
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 510;
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
ll fac[N],inv[N];
inline void init(int n = 500){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	inv[n] = fpow(fac[n],mod-2);
	for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
	if(x < y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n,m;
string opp;
int c[N],s[N],cnt[N],pre[N],suf[N];
ll f[2][N][N];
inline void add(ll &x,ll y){
	x = (x+y)%mod;
}
void solve(){
	n = read(); m = read();
	cin >> opp;
	for(int i=1;i<=n;i++) c[i] = read();
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++) cnt[c[i]]++;
	pre[0] = cnt[0];
	for(int i=1;i<=n;i++) pre[i] = pre[i-1]+cnt[i];
	for(int i=n;i>=0;i--) suf[i] = suf[i+1]+cnt[i];
//	for(int i=1;i<=n;i++) cout << cnt[i] <<" " << pre[i] << " " << suf[i] << "\n";
	for(int i=1;i<=n;i++) s[i] = (opp[i-1] == '0');
	f[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		int op = (i & 1);
		memset(f[op],0,sizeof(f[op]));
		for(int j=0;j<i;j++){
			for(int k=0;k<i;k++){
				int d = i-1-k;
				if(s[i]){
					for(int l=0;l<=cnt[j+1];l++){
						add(f[op][j+1][k+l],f[op^1][j][k]*C(i-1-k,l)%mod*C(cnt[j+1],l)%mod*fac[l]%mod);
						add(f[op][j+1][k+l+1],f[op^1][j][k]*C(i-1-k,l)%mod*C(cnt[j+1],l)%mod*fac[l]%mod*C(pre[j]-k,1)%mod);
						add(f[op][j+1][k+l+1],f[op^1][j][k]*C(i-1-k,l)%mod*C(cnt[j+1],l+1)%mod*fac[l+1]%mod);
					}
					
				}else{
//					cout << i << "\n";
//					cout << suf[j+1] << "\n";
					add(f[op][j][k],f[op^1][j][k]);
					for(int l=0;l<=cnt[j+1];l++){
						add(f[op][j+1][k+l+1],f[op^1][j][k]*C(i-1-k,l)%mod*C(cnt[j+1],l)%mod*fac[l]%mod*C(pre[j]-k,1)%mod);
					}
				}
			}
		}
//		for(int j=0;j<=i;j++,puts(""))
//			for(int k=0;k<=i;k++) cout << f[op][j][k] << " ";
//		cout << "\n\n";
	}
	ll ans = 0;
	for(int i=0;i<=n-m;i++){
		add(ans,f[n&1][i][pre[i]]*fac[n-pre[i]]%mod);
//		for(int k=0;k<=n;k++) add(ans,f[n&1][i][k]);
	}
	cout << ans << "\n";
}
int main(){
	init();
	int T = 1;
	while(T--) solve(); 
	return 0;
}
