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
const int N = 5e5+10;
const int inf = 1e9;
int n,k,s[N],cnt[N];
vector<int> G[N];
pii a[N],b[N],h[N];
void dfs(int x,int fa){
	a[x] = a[fa]; b[x] = b[fa];
	if(h[x] < a[x]) b[x] = a[x],a[x] = h[x];
	else if(h[x] < b[x]) b[x] = h[x];
	for(int y : G[x]) if(y != fa) dfs(y,x);
}
int find(int x){
	int l = 1,r = k,res = k+1;
	while(l <= r){
		int mid = (l+r)>>1;
		if(s[mid] <= x) r = mid-1,res = mid;
		else l = mid+1;
	}
	return res;
}
int mn[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	mn[rt] = min(mn[ls],mn[rs]);
}
inline void push_down(int rt){
	if(!tag[rt]) return ;
	mn[ls] += tag[rt]; tag[ls] += tag[rt];
	mn[rs] += tag[rt]; tag[rs] += tag[rt];
	tag[rt] = 0;
}
void update(int rt,int l,int r,int ql,int qr,int c){
	if(ql <= l && r <= qr){
		tag[rt] += c; mn[rt] += c;
		return ;
	}
	push_down(rt);
	int mid = (l+r)>>1;
	if(ql <= mid) update(ls,l,mid,ql,qr,c);
	if(qr >  mid) update(rs,mid+1,r,ql,qr,c);
	push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return mn[rt];
	push_down(rt);
	int mid = (l+r)>>1,res = inf;
	if(ql <= mid) res = min(res,query(ls,l,mid,ql,qr));
	if(qr >  mid) res = min(res,query(rs,mid+1,r,ql,qr));
	return res;
}
vector<int> V[N];
int main(){
    n = read();
	for(int i=1;i<=n;i++) h[i] = mk(read(),i);
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	k = read();
	for(int i=1;i<=k;i++) s[i] = read();
	for(int i=0;i<=n;i++) a[i] = b[i] = mk(1e18,i);
	dfs(1,0);
	sort(s+1,s+1+k,greater<int>());
	for(int i=1;i<=n;i++){
		cnt[find(a[i].fi)]++;
		V[a[i].se].push_back(i);
	}
	ll lim = 0;
	for(int i=1;i<=k;i++) cnt[i] += cnt[i-1];
	for(int i=1;i<=k;i++){
		cnt[i] -= i;
		update(1,1,k,i,i,cnt[i]);
		if(cnt[i] < 0 && !lim) lim = s[i];
	}
	if(!lim){
		cout << 0;
		return 0;
	}
	ll ans = 1e18;
	for(int i=1;i<=n;i++){
		if(h[i].fi >= lim) continue;
		for(int y : V[i]) update(1,1,k,find(min(lim,b[y].fi)),find(a[i].fi)-1,1);
		if(mn[1] >= 0) ans = min(lim-h[i].fi,ans);
		for(int y : V[i]) update(1,1,k,find(min(lim,b[y].fi)),find(a[i].fi)-1,-1);
	}
	if(ans < 1e18) cout << ans ;
	else cout << "-1";
    return 0;  
}