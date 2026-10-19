#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int S = 1<<16;
const int N = 20;
int n,cnt;
string a[N],b[N];
int c[N],d[N];
int f[S][N];
map<string,int> mp;
signed main(){
	int T = read();
	while(T--){
		n = read();
		mp.clear(); cnt = 0;
		for(int i=0;i<n;i++){
			cin >> a[i] >> b[i];
			if(!mp[a[i]]) mp[a[i]] = ++cnt;
			if(!mp[b[i]]) mp[b[i]] = ++cnt;
			c[i] = mp[a[i]]; d[i] = mp[b[i]];
		}
		for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) f[i][j] = -1e9;
		for(int i=0;i<n;i++) f[(1<<i)][i] = 1;
		int ans = 1;
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				ans = max(ans,f[i][j]);
				if(f[i][j] < 0) continue;
				for(int k=0;k<n;k++){
					if((i & (1<<k)) || (c[j] != c[k] && d[j] != d[k])) continue;
					f[i|(1<<k)][k] = max(f[i|(1<<k)][k],f[i][j]+1);
				}
			}
		}
		cout << n-ans << "\n";
	}
	return 0;
}
