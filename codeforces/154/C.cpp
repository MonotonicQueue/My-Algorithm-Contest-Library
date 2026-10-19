#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define ll long long 
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
mt19937_64 rnd(time(0));
int n,m,q;
ull val[N],hsh1[N],hsh2[N];
unordered_map<ull,int> t1,t2;
inline void change(int x,int y){
	hsh1[x] ^= val[y];
	hsh1[y] ^= val[x];
	hsh2[x] ^= val[y];
	hsh2[y] ^= val[x];
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) hsh2[i] = val[i] = rnd();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		change(u,v);
	}
    for(int i=1;i<=n;i++) t1[hsh1[i]]++,t2[hsh2[i]]++;
    ll ans = 0;
    for(auto it : t1) ans += 1ll*(it.se-1)*(it.se)/2;
    for(auto it : t2) ans += 1ll*(it.se-1)*(it.se)/2;
    cout << ans;
    return 0;
}
