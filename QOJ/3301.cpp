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
const int M = 1<<18;
const ll inf = 1e18;
int n;
ll a[N][N];
ll g[M][N][N],f[M];
void solve(){
	n = read();
	ll sum = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) a[i][j] = read();
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(a[i][j] == -1) continue;
			ll t = min(a[i][j],a[j][i]);
			a[i][j] -= t; a[j][i] -= t;
			sum += t;
		}
	for(int s=0;s<(1<<n);s++){
		f[s] = inf;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) g[s][i][j] = inf;
	}
	for(int i=0;i<n;i++) f[1<<i] = 0;
	auto chkmn = [&](ll &x,ll y)->void{
		x = x < y ? x : y;
	};
	for(int s=0;s<(1<<n);s++){
		for(int i=0;i<n;i++){
			if(!((s >> i) & 1)) continue;
			for(int j=0;j<n;j++){
				if(!((s >> j) & 1)) continue;
				for(int k=0;k<n;k++){
					if((s >> k) & 1) continue;
					if(a[i][k] == -1) continue;
					if(i != j) chkmn(g[s][k][j],f[s]+a[i][k]);
					else chkmn(g[s|(1<<k)][k][j],f[s]+a[i][k]);
				}
			}
		}//加入一个耳
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!((s >> j) & 1)) continue;
				for(int k=0;k<n;k++){
					if((s >> k) & 1) continue;
					if(a[i][k] == -1) continue;
					chkmn(g[s|(1<<i)][k][j],g[s][i][j]+a[i][k]);
				}
			}
		}
		for(int i=0;i<n;i++){
			if((s >> i) & 1) continue;
			for(int j=0;j<n;j++){
				if(!((s >> j) & 1)) continue;
				if(a[i][j] == -1) continue;
				chkmn(f[s|(1<<i)],g[s][i][j]+a[i][j]);
			}
		}
	}
	if(f[(1<<n)-1] < inf) cout << f[(1<<n)-1]+sum << "\n";
	else cout << "-1\n";
}
int main(){
	int T = 1;
	while(T--) solve();
    return 0;
}