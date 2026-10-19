#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N = 55;
const int R = 12;
const int inf = 1e9;
int n,m,k;
char ch[N][N]; 
struct node{
	int x,y,p;
}a[N*N];
int cnt[N*N][R+5];
int calc(int x,int y,int r){
	int res = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ch[i][j] == '#' && (x-i)*(x-i)+(y-j)*(y-j) <= r*r) res++;
	return res;
}
int f[N*N][(1<<R)+5],pw[N];
signed main(){
	int T; cin >> T;
	pw[0] = 1;
	for(int i=1;i<=R;i++) pw[i] = pw[i-1]*3;
	while(T--){
		cin >> n >> m >> k;
		for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
		for(int i=1;i<=k;i++)
			cin >> a[i].x >> a[i].y >> a[i].p;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=R;j++) cnt[i][j] = calc(a[i].x,a[i].y,j);
		for(int i=1;i<=k;i++) for(int j=0;j<(1<<R);j++) f[i][j] = -inf;
		f[0][0] = 0;
		int ans = 0;
		for(int i=1;i<=k;i++){
			for(int S=0;S<(1<<R);S++){
				f[i][S] = f[i-1][S];
				for(int r=1;r<=R;r++){
					if(S & (1<<(r-1)))
						f[i][S] = max(f[i][S],f[i-1][S^(1<<(r-1))]+a[i].p*cnt[i][r]-pw[r]);
				}
				ans = max(ans,f[i][S]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
