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
const int M = 6e5+10;
int n,m,q;
int a[N][3],b[N][3];
ull P = 13131;
ull val[N],pw[N];
mt19937_64 rnd(time(0));
vector<pii> v[N];
bool ans[1010100];
unordered_map<ull,int> mp;
int cnt;
ull hsh[M][2];
bool add(int x,int y){
	for(int k=0;k<=2;k++){
		if(mp[hsh[a[x][k]][0]] == 1) cnt--;
		mp[hsh[a[x][k]][0]]--;
		if(mp[hsh[a[x][k]][0]] == -1) cnt++;
		hsh[a[x][k]][0] += val[x]*pw[x]*y;
		if(mp[hsh[a[x][k]][0]] == -1) cnt--;
		mp[hsh[a[x][k]][0]]++;
		if(mp[hsh[a[x][k]][0]] == 1) cnt++;
	}
	for(int k=0;k<=2;k++){
		if(mp[hsh[b[x][k]][1]] == -1) cnt--;
		mp[hsh[b[x][k]][1]]++;
		if(mp[hsh[b[x][k]][1]] == 1) cnt++;
		hsh[b[x][k]][1] += val[x]*pw[x]*y;
		if(mp[hsh[b[x][k]][1]] == 1) cnt--;
		mp[hsh[b[x][k]][1]]--;
		if(mp[hsh[b[x][k]][1]] == -1) cnt++;
	}
	return (!cnt);
}
signed main(){
	n = read(); m = read(); q = read();
	for(int i=1;i<=n;i++){
		a[i][0] = read();
		a[i][1] = read();
		a[i][2] = read();
	}
	for(int i=1;i<=n;i++){
		b[i][0] = read();
		b[i][1] = read();
		b[i][2] = read();
	}
	for(int i=1;i<=q;i++){
		int l = read(),r = read();
		v[l].push_back(mk(r,i));
	}
	pw[0] = 1;
	for(int i=1;i<=n;i++) pw[i] = pw[i-1]*P;
	for(int i=1;i<=n;i++) val[i] = rnd();
	for(int l=1,r=0;l<=n;l++){
		if(r < l) add(l,1),r = l;
		while(r <= n && add(++r,1));
		if(r <= n) add(r--,-1);
		for(auto it : v[l])
			ans[it.se] = it.fi <= r;
		add(l,-1);
	}
	for(int i=1;i<=q;i++) puts(ans[i] ? "Yes" : "No");
	return 0;
}

