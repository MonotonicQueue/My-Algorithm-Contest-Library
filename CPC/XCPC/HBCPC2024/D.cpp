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
const int N = 2e6+10;
int n,k,d,a[N];
ll cnt[N],now;
ll ask(int l,int r){
	static int L = 1,R = 0;
	auto add = [&](int x){
		now += cnt[a[x]^d];
		cnt[a[x]]++;
	};
	auto del = [&](int x){
		cnt[a[x]]--;
		now -= cnt[a[x]^d];
	};
	while(L < l) del(L++);
	while(L > l) add(--L);
	while(R < r) add(++R);
	while(R > r) del(R--);
	return now;
}
ll f[N],g[N];
void solve(int l,int r,int pl,int pr){
	if(l > r) return ;
	int mid = (l+r) >> 1,p = pl;
	f[mid] = g[pl]+ask(pl,mid);
	for(int i=pl+1;i<=min(pr,mid);i++){
		ll v = g[i]+ask(i,mid);
		if(f[mid] > v) f[mid] = v,p = i;
	}
	solve(l,mid-1,pl,p); solve(mid+1,r,p,pr);
}
int main(){
	n = read(); k = read(); d = read();
	for(int i=1;i<=n;i++) a[i] = read()^a[i-1];
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	while(k--){
		memcpy(g,f,sizeof(g));
		memset(f,0x3f,sizeof(f));
		solve(0,n,0,n);
	}
	cout << f[n];
	return 0;
}