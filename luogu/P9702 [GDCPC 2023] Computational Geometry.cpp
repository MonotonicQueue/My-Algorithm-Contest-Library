#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
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
const int N = 5e3+10;
int n;
struct Point{
	ll x,y;
}a[N];
ll dis(Point x,Point y){
	return 1ll*(x.x-y.x)*(x.x-y.x)+1ll*(x.y-y.y)*(x.y-y.y);
}
ll line(Point x,Point y,Point z){
	return (y.x-x.x)*(z.y-y.y)-(z.x-y.x)*(y.y-x.y);
}
ll f[N][N];
void solve(){
	n = read();
    for(int i=0;i<n;i++){
		a[i].x = read();
		a[i].y = read();
	}
	for(int len=2;len<=n;len++){
		for(int x=0;x<n;x++){
			int y = (x+len-1) % n;
			f[x][y] = max(max(f[(x+1)%n][y],f[x][(y-1+n)%n]),dis(a[x],a[y]));
		}
	}
	ll ans = 9e18;
	for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
			if(line(a[(x-1+n)%n],a[x],a[y]) && line(a[x],a[(x+1)%n],a[y]))
				ans = min(ans,f[x][y]+f[y][x]);
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    
	return 0;
}