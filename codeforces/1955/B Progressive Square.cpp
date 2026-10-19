#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 3e5+10;
int a[N],m;
int b[1010][1010];
map<int,int> mp;
signed main(){
	int T = read();
	while(T--){
		int n = read(),c = read(),d = read();
		m = n*n;
		mp.clear();
		for(int i=1;i<=n*n;i++) a[i] = read(),mp[a[i]]++;
		sort(a+1,a+1+m);
		b[1][1] = a[1];
		for(int i=2;i<=n;i++) b[i][1] = b[i-1][1]+c;
		for(int i=1;i<=n;i++)
			for(int j=2;j<=n;j++)
				b[i][j] = b[i][j-1]+d;
		bool flag = false;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
			mp[b[i][j]]--;
			if(mp[b[i][j]] < 0) flag = true;
		}
		puts(flag ? "NO" : "YES");
	}
	return 0;
}