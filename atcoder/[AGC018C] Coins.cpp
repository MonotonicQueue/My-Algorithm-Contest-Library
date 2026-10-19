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
const int N = 1e5+10;
int n,x,y,z;
int a[N],b[N],c[N];
int vis[N];
priority_queue<pii> BC,B,C; 
int main(){
	x = read(); y = read(); z = read();
	n = x+y+z;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		a[i] = read();
		b[i] = read()-a[i];
		c[i] = read()-a[i];
		B.push(mk(b[i],i));
		C.push(mk(c[i],i));
		ans += a[i];
	}
	while(y--){
		int i = B.top().se;
		ans += b[i];
		vis[i] = 1;
		BC.push(mk(c[i]-b[i],i));
		B.pop();
	}
	while(z--){
		while(!B.empty() && vis[B.top().se]) B.pop();
		while(!C.empty() && vis[C.top().se]) C.pop();
		while(!BC.empty() && vis[BC.top().se] == 2) BC.pop();
		ll maxn = C.top().fi; int type = 1;
		if(BC.top().fi+B.top().fi > maxn) maxn = BC.top().fi+B.top().fi,type = 2;
		ans += maxn;
		if(type == 1) vis[C.top().se] = 1,C.pop();
		else{
			int i = B.top().se;
			vis[BC.top().se] = 2;
			BC.pop(); B.pop();
			vis[i] = 1;
			BC.push(mk(c[i]-b[i],i));
		}
	}
	cout << ans;
	return 0;
}