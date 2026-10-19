#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 3100;
int n,x,y;
int vis[N],a[N],b[N];
priority_queue<pii> A,B,C;
int main(){
	n = read();
	x = read(); y = read();
	for(int i=1;i<=n;i++){
		a[i] = read(); A.push(mk(a[i],i));
	} 
	for(int i=1;i<=n;i++){
		b[i] = read(); B.push(mk(b[i],i));
	}
	ll ans = 0;
	while(x--){
		int i = A.top().se;
		ans += a[i];
		vis[i] = 1;
		C.push(mk(b[i]-a[i],i));
		A.pop();
	}
//	cout << ans << "\n";
	while(y--){
		while(!A.empty() && vis[A.top().se]) A.pop();
		while(!B.empty() && vis[B.top().se]) B.pop();
		while(!C.empty() && vis[C.top().se] == 2) C.pop();
		ll maxn = 0; int type = 0;
		if(B.top().fi > maxn) maxn = B.top().fi,type = 1;
		if(C.top().fi+A.top().fi > maxn) maxn = C.top().fi+A.top().fi,type = 2;
		ans += maxn;
//		cout << type << "\n";
		if(type == 1) vis[B.top().se] = 2,B.pop();
		else{
			vis[C.top().se] = 2; vis[A.top().se] = 1;
			C.push(mk(b[A.top().se]-a[A.top().se],A.top().se));
			A.pop(); C.pop();
		} 
	}
	cout << ans << "\n";
	for(int i=1;i<=n;i++) if(vis[i] == 1) cout << i << " ";
	cout << "\n";
	for(int i=1;i<=n;i++) if(vis[i] == 2) cout << i << " ";
	return 0;
}