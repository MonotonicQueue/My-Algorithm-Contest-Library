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
const int N = 2e5+10;
int n,m,h[N];
ll t[N];
void add(int x,int y){
	while(x <= n){
		t[x] += y;
		x += x&(-x);
	}
}
ll ask(int x){
	ll res = 0;
	while(x){
		res += t[x];
		x -= x&(-x);
	}
	return res;
}
int l[N],r[N];
vector<int> v[N];
vector<pii> s[N];
int getl(int x){
	return x == l[x] ? x : l[x] = getl(l[x]);
}
int getr(int x){
	return x == r[x] ? x : r[x] = getr(r[x]);
}
int main(){
	n = read();
	for(int i=1;i<=n;i++) h[i] = read();
	for(int i=1;i<=n;i++) v[h[i]].push_back(i);
	m = read();
	for(int i=1;i<=m;i++){
		int x = read(),y = read(),c = read();
		s[y].push_back(mk(x,c));
	}
	ll ans = 0;
	for(int i=1;i<=n+1;i++) l[i] = r[i] = i;
	for(int i=1;i<=n;i++){
		for(auto it : s[i]){
			ll res = ask(it.fi);
			if(res > it.se) ans += it.se;
			else{
				ans += res;
				add(getl(it.fi)+1,it.se-res);
				add(getr(it.fi),res-it.se);
			}
		}
		for(auto x : v[i]) l[x] = x-1,r[x] = x+1;
	}
	cout << ans;
    return 0;
}
