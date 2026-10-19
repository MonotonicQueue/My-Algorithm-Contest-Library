#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
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
int n,len,Q;
char s[N],t[N];
int sa[N],rk[N],t1[N],t2[N],cnt[N];

void getsa(int *x,int *y){
	int m = 127;
	for(int i=1;i<=m;i++) cnt[i] = 0;
	for(int i=1;i<=len;i++) cnt[x[i] = s[i]]++;
	for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
	for(int i=len;i;i--) sa[cnt[x[i]]--] = i;
	for(int k=1;k<=len;k<<=1){
		int p = 0;
		for(int i=len-k+1;i<=len;i++) y[++p] = i;
		for(int i=1;i<=len;i++)
			if(sa[i] > k) y[++p] = sa[i]-k;
		for(int i=1;i<=m;i++) cnt[i] = 0;
		for(int i=1;i<=len;i++) cnt[x[i]]++;
		for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
		for(int i=len;i;i--) sa[cnt[x[y[i]]]--] = y[i];

		swap(x,y); p = 1; x[sa[1]] = 1;
		for(int i=2;i<=len;i++)
			x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k] ? p : ++p;
		m = p;
	}
	for(int i=1;i<=len;i++) rk[sa[i]] = i;
}
struct BIT{
	int t[N];
	void init(){
		for(int i=1;i<=len;i++) t[i] = 0;
	}
	void add(int x,int y){
		while(x <= len){
			t[x] += y;
			x += x&(-x);
		}
	}
	int ask(int x){
		int res = 0;
		while(x){
			res += t[x];
			x -= x&(-x);
		}
		return res;
	}
}T[2];
vector<pii> q[N];
int ans[N];
void work1(){
	len = n;
	s[++len] = 30;
	for(int i=n;i;i--) s[++len] = s[i];
	s[++len] = 29;
	getsa(t1,t2);
	T[0].init(); T[1].init();
	vector<pii> v1,v2;
	for(int i=1;i<=n;i++)
		v1.emplace_back(rk[i],i),
		v2.emplace_back(rk[2*n+2-i],i);
	sort(v1.begin(),v1.end(),greater<pii>());
	sort(v2.begin(),v2.end(),greater<pii>());
	int j = 0;
	for(auto [val,x] : v1){
		while(j < n && v2[j].fi > val){
			T[v2[j].se & 1].add(v2[j].se,1);
			j++;
		}
		for(auto [id,r] : q[x]){
			ans[id] = T[(x&1)^1].ask(x+2*r-1)-T[(x&1)^1].ask(x);
		}
	}
}
int P[N];
void manacher(){
	t[0] = '&';
	int m = 0;
	t[m = 1] = '|';
	for(int i=1;i<=n;i++){
		t[++m] = s[i];
		t[++m] = '|';
	}
	t[++m] = '^';
	int R = 0,C = 0;
	for(int i=1;i<=m;i++){
		if(i < R) P[i] = min(P[2*C-i],P[C]+C-i);
		else P[i] = 1;
		while(t[i+P[i]] == t[i-P[i]]) P[i]++;
		if(i+P[i] > R){
			R = i+P[i];
			C = i;
		}
	}
}
vector<int> v[N];
void work2(){
	manacher();
	T[0].init(); T[1].init();
	s[n+1] = s[0] = 0;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=2;i<=n;i++){
		int r = (P[2*i-1]-1)/2;
		if(s[i+r] < s[i-r-1]){
			v[i-r].emplace_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int x : v[i]) T[0].add(x,1);
		for(auto [id,r] : q[i]){
			ans[id] -= T[0].ask(i+r)-T[0].ask(i);
		}
	}
}
void solve(){
	n = read(); Q = read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) q[i].clear();
	for(int i=1;i<=Q;i++){
		int l = read(),r = read();
		q[l].emplace_back(i,r);
	}
	work1(); work2();
	for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
}
int main(){
	int C = read(),T = read();
	while(T--) solve();
	return 0;
}