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
int n,m,a[N],nxt[S][6];
char s[N];
map<char,int> mp;
int g[20],h[20],f[N][S],ans[20];
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
	scanf("%s",s+1);
	m = read();
	n = strlen(s+1);
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
		for(int j=1;j<=4;j++) nxt[i][j] = getnxt(i,j);
	memset(f,0,sizeof(f));
	f[0][0] = 1;
	for(int i=0;i<m;i++)
		for(int j=0;j<(1<<n);j++)
			for(int k=1;k<=4;k++)
				add(f[i+1][nxt[j][k]],f[i][j]);
	memset(ans,0,sizeof(ans));
	for(int i=0;i<(1<<n);i++)
		add(ans[popcount(i)],f[m][i]);
	for(int i=0;i<=n;i++) cout << ans[i] << "\n";
}
int main(){
	mp['A'] = 1; mp['G'] = 2;
	mp['C'] = 3; mp['T'] = 4;
	int T = read();
	while(T--) solve();
	return 0;
}