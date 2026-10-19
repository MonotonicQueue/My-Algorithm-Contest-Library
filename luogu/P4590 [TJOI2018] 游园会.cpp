#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1010;
const int S = 1<<15;
const int mod = 1e9+7;
int n,m,a[N],nxt[S][5];
char s[N];
map<char,int> mp;
int g[20],h[20],f[2][S][4],ans[20];
inline void add(int &x,int y){
	x = x+y >= mod ? x+y-mod : x+y;
}
int popcount(int S){
	int ans = 0;
	for(int i=1;i<=n;i++)
		ans += (S >> (i-1)) & 1;
	return ans;
}
void solve(){
	m = read(); n = read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i] = mp[s[i]];
	auto getnxt = [&](int S,int c)->int{
		for(int i=1;i<=n;i++)
			g[i] = g[i-1]+((S >> (i-1)) & 1);
		for(int i=1;i<=n;i++){
			if(a[i] == c) h[i] = g[i-1]+1;
			else h[i] = max(h[i-1],g[i]);
		}
		int T = 0;
		for(int i=1;i<=n;i++)
			T |= (h[i]-h[i-1]) << (i-1);
		return T;
	};
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=3;j++) nxt[i][j] = getnxt(i,j);
	f[0][0][0] = 1;
	for(int i=0;i<m;i++){
		int c = i & 1;
		for(int j=0;j<(1<<n);j++){
			for(int p=1;p<=3;p++)
				for(int q=0;q<=2;q++)
					if(q == p-1) add(f[c^1][nxt[j][p]][q+1],f[c][j][q]);
					else if(p != 1) add(f[c^1][nxt[j][p]][0],f[c][j][q]);
					else add(f[c^1][nxt[j][p]][1],f[c][j][q]);
			}
		memset(f[c],0,sizeof(f[c]));
	}
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<=2;j++)
			add(ans[popcount(i)],f[m&1][i][j]);
	for(int i=0;i<=n;i++) cout << ans[i] << "\n";
}
int main(){
	mp['N'] = 1; mp['O'] = 2; mp['I'] = 3;
	int T = 1;
	while(T--) solve();
	return 0;
}