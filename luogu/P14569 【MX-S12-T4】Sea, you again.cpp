#include<bits/stdc++.h>
#define ull unsigned long long
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
const int N = 1e7+10;
const int M = 1e6+10;
const int mod = 998244353;
int B;
int nl,nr,L[N],R[N];
ll f[2][M][2],g[2][M][2];
ll sf[M][2],sg[M][2],sum[M][2];
inline void add(ll &x,ll y){
	x = ((x+y)%mod+mod)%mod;
}
ll work(int n,int *a){
	for(int c=0;c<=1;c++)
		for(int j=0;j<=B;j++) f[c][j][0] = f[c][j][1] = g[c][j][0] = g[c][j][1] = 0;
	f[0][0][0] = 0; g[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		int c = i & 1;
		for(int j=0;j<=B;j++) f[c][j][0] = f[c][j][1] = g[c][j][0] = g[c][j][1] = 0;
		for(int k=0;k<=1;k++){
			sf[0][k] = f[c^1][0][k];
			sg[0][k] = g[c^1][0][k];
			sum[0][k] = 0;
		}
		for(int j=1;j<=B;j++){
			for(int k=0;k<=1;k++){
				sf[j][k] = (f[c^1][j][k]+sf[j-1][k])%mod;
				sg[j][k] = (g[c^1][j][k]+sg[j-1][k])%mod;
				sum[j][k] = (g[c^1][j][k]*j+sum[j-1][k])%mod;
			}
		}
		int x = a[i];
		for(int j=0;j<B;j++){
			add(g[c][j][0],(sg[j][0]-(j >= x ? sg[j-x][0] : 0)+
						  	sg[j][1]-(j >= x ? sg[j-x][1] : 0)));
			if(j >= x){
				add(g[c][j][0],g[c^1][j-x][0]);
				add(g[c][j][1],g[c^1][j-x][1]);
			}
			if(j > x){
				add(g[c][j][1],sg[j-x-1][0]+sg[j-x-1][1]);
			}

			if(j < x){
				add(g[c][j][0],(sg[B-1][0]-sg[B-j-1][0])*B+(sg[B-1][1]-sg[B-j-1][1])*B);
			}
			if(j == x){
				add(g[c][j][0],(sg[B-1][0]-sg[B-j-1][0])*B);
				add(g[c][j][1],(sg[B-1][1]-sg[B-j-1][1])*B);
			}
			if(j > x){
				add(g[c][j][1],(sg[B-1][0]-sg[B-j-1][0])*B+(sg[B-1][1]-sg[B-j-1][1])*B);
			}



			add(f[c][j][0],(sf[j][0]-(j >= x ? sf[j-x][0] : 0)+
						  	sf[j][1]-(j >= x ? sf[j-x][1] : 0)));
			if(j >= x){
				add(f[c][j][0],f[c^1][j-x][0]);
				add(f[c][j][1],f[c^1][j-x][1]);
			}
			if(j > x){
				add(f[c][j][1],sf[j-x-1][0]+sf[j-x-1][1]);
			}
			if(j < x){
				add(f[c][j][0],(sf[B-1][0]-sf[B-j-1][0])+(sf[B-1][1]-sf[B-j-1][1]));
				add(f[c][j][0],(sum[B-1][0]-sum[B-j-1][0])+(sum[B-1][1]-sum[B-j-1][1]));
			}
			if(j == x){
				add(f[c][j][0],(sf[B-1][0]-sf[B-j-1][0]));
				add(f[c][j][1],(sf[B-1][1]-sf[B-j-1][1]));
				add(f[c][j][0],(sum[B-1][0]-sum[B-j-1][0]));
				add(f[c][j][1],(sum[B-1][1]-sum[B-j-1][1]));
			}
			if(j > x){
				add(f[c][j][1],(sf[B-1][0]-sf[B-j-1][0])+(sf[B-1][1]-sf[B-j-1][1]));
				add(f[c][j][1],(sum[B-1][0]-sum[B-j-1][0])+(sum[B-1][1]-sum[B-j-1][1]));
			}
		}
	}
	ll res = 0;
	for(int i=0;i<B;i++){
		add(res,(f[n&1][i][0]+g[n&1][i][0]*i)%mod);
	}
	return res;
}
ll get(){
	ll now = 0,x = 1,res = 0;
	for(int i=1;i<=nl;i++){
		if(now+L[i] < B) now += L[i];
		else{
			res = (res+now*x)%mod;
			x = x*B%mod;
			now = L[i];
		}
	}
	res = (res+now*x)%mod;
	return res;
}
void solve(){
	B = read();
	nl = read();
	for(int i=1;i<=nl;i++) L[i] = read();
	nr = read();
	for(int i=1;i<=nr;i++) R[i] = read();
	cout << (work(nr,R)-work(nl,L)+get()+mod)%mod << "\n";
} 
int main(){
	// freopen("pocket.in","r",stdin);
	// freopen("pocket.out","w",stdout);
	int T = read();
	while(T--) solve(); 
	return 0;
}