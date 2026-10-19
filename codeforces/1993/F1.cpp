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
const int N = 1e6+10;
int n,k,w,h;
char s[N];
map<pii,int> mp;
int main(){
	int T = read();
	while(T--){
		n = read(); k = read();
		w = read()*2; h = read()*2;
		cin >> (s+1);
		mp.clear();
		int x = 0,y = 0;
		for(int i=1;i<=n;i++){
			if(s[i] == 'U') y++;
			if(s[i] == 'D') y--;
			if(s[i] == 'L') x--;
			if(s[i] == 'R') x++;
			x = (x+w)%w;
			y = (y+h)%h;
			mp[mk(x,y)]++;
		}
		ll ans = 0;
		x = w-x; y = h-y;
		for(int i=0;i<k;i++){
			int nx = 1ll*i*x%w,
				ny = 1ll*i*y%h;
			ans += mp[mk(nx,ny)];
		}
		cout << ans << "\n";
	}
	return 0;
}
