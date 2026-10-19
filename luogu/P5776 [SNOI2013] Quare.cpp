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
const int N = 15;
const int M = 1<<12;
const ll inf = 1e18;
int n,m;
ll d[N][N][2],g[M][N][N],f[M];
void solve(){
	n = read(); m = read();
	memset(d,0x1f,sizeof(d));
	memset(f,0x1f,sizeof(f));
	memset(g,0x1f,sizeof(g));
	for(int i=1;i<=m;i++){
		int x = read(),y = read(),w = read();
		x--; y--;
		if(w < d[x][y][0]) d[x][y][1] = d[x][y][0],d[x][y][0] = w;
		else if(w < d[x][y][1]) d[x][y][1] = w;
		swap(x,y);
		if(w < d[x][y][0]) d[x][y][1] = d[x][y][0],d[x][y][0] = w;
		else if(w < d[x][y][1]) d[x][y][1] = w;
	}
	for(int i=0;i<n;i++) f[1<<i] = 0;
	auto chkmn = [&](ll &x,ll y)->void{
		x = x < y ? x : y;
	};
	for(int S=1;S<(1<<n);S++){
		for(int i=0;i<n;i++){
			if(!((S >> i) & 1)) continue;
			for(int j=0;j<n;j++){
				if((S >> j) & 1) continue;
				chkmn(f[S|(1<<j)],f[S]+d[i][j][0]+d[i][j][1]);
			}
		}
		for(int i=0;i<n;i++){
			if(!((S >> i) & 1)) continue;
			for(int j=0;j<n;j++){
				if(!((S >> j) & 1)) continue;
				for(int k=0;k<n;k++){
					if((S >> k) & 1) continue;
					if(i == j) chkmn(g[S|(1<<k)][k][j],f[S]+d[i][k][0]);
					else chkmn(g[S][k][j],f[S]+d[i][k][0]);
				}
			}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(!((S >> j) & 1) || i == j) continue;
				for(int k=0;k<n;k++){
					if((S >> k) & 1) continue;
					chkmn(g[S|(1<<i)][k][j],g[S][i][j]+d[i][k][0]);
				}
			}
		for(int i=0;i<n;i++){
			if((S >> i) & 1) continue;
			for(int j=0;j<n;j++){
				if(!((S >> j) & 1)) continue;
				chkmn(f[S|(1<<i)],g[S][i][j]+d[i][j][0]);
			}
		}
	}
	if(f[(1<<n)-1] < inf) cout << f[(1<<n)-1] << "\n";
	else cout << "impossible\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}