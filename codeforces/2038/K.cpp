#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e6+10;
int n,A,B;
ll f[N],g[N],dx[N],dy[N];
void solve(){
	n = read();
	A = read(); B = read();
	ll X = 0,Y = 0;
	for(int i=1;i<=n;i++){
		dx[i] = __gcd(A,i);
		dy[i] = __gcd(B,i);
	}
	for(int i=n;i>=1;i--)
		if(dx[i] == 1){
			X = i;
			break;
		}
	for(int i=n;i>=1;i--)
		if(dy[i] == 1){
			Y = i;
			break;
		}
	ll ans = 0;
	for(int i=1;i<=X;i++) ans += dx[i];
	for(int i=1;i<=Y;i++) ans += dy[i];
	ans += X+Y-2;
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	f[Y] = ans;
	for(int j=Y+1;j<=n;j++) f[j] = f[j-1]+dy[j]+dx[X];
	for(int i=X+1;i<=n;i++){
		for(int j=Y;j<=n;j++)
			g[j] = min(g[j-1],f[j])+dy[j]+dx[i];
		for(int j=Y;j<=n;j++) f[j] = g[j];
	}
	cout << f[n] << "\n";
}
int main(){
	solve();
    return 0;
}