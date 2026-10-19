#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 3e5+10;
const int mod = 1e9+7;
const ll inf = 1e18;
int n,m;
ll a[N],b[N],sum[N];
vector<ll> f[N],g[N];
#define ls rt<<1
#define rs rt<<1|1
ll mn[N<<2],cnt[N<<2];
void build(int rt,int l,int r){
	cnt[rt] = 0; mn[rt] = inf;
	if(l == r) return ;
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void change(int rt,ll d,ll c){
	if(mn[rt] >= d){
		if(mn[rt] == d) cnt[rt] = (cnt[rt]+c)%mod;
		else cnt[rt] = c;
		mn[rt] = d;
	}
}
void push_down(int rt){
	if(mn[rt] != inf){
		change(ls,mn[rt],cnt[rt]);
		change(rs,mn[rt],cnt[rt]);
		mn[rt] = inf; cnt[rt] = 0;
	}
}
void update(int rt,int l,int r,int ql,int qr,ll d,ll c){
	if(ql <= l && r <= qr) return change(rt,d,c);
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= mid) update(ls,l,mid,ql,qr,d,c);
	if(qr >  mid) update(rs,mid+1,r,ql,qr,d,c);
}
pair<ll,ll> query(int rt,int l,int r,int pos){
	if(l == r) return mk(mn[rt],cnt[rt]);
	push_down(rt);
	int mid = (l+r) >> 1;
	if(pos <= mid) return query(ls,l,mid,pos);
	else return query(rs,mid+1,r,pos);
}
void solve(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read(),sum[i] = sum[i-1]+a[i];
	for(int i=1;i<=m;i++) b[i] = read();
	for(int i=0;i<=n;i++){
		f[i].clear(); g[i].clear();
		f[i].resize(m+1); g[i].resize(m+1); 
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++) f[i][j] = inf,g[i][j] = 0;
	for(int i=1;i<=m;i++) g[0][i] = 1;
	for(int i=1;i<=m;i++){
		build(1,1,n);
		for(int j=1;j<=n;j++){
			int l = j,r = n,res = -1;
			if(j != n) update(1,1,n,j,j,f[j][i-1],g[j][i-1]);
			while(l <= r){
				int mid = (l+r) >>1;
				if(sum[mid]-sum[j-1] <= b[i]) res = mid,l = mid+1;
				else r = mid-1;
			}
			if(res != -1)
				update(1,1,n,j,res,f[j-1][i]+m-i,g[j-1][i]);
			auto it = query(1,1,n,j);
			f[j][i] = it.fi; g[j][i] = it.se;
		} 
	}
	ll ans = 1e18,cnt = 0;
	for(int i=1;i<=m;i++) ans = min(ans,f[n][i]);
	for(int i=1;i<=m;i++) if(ans == f[n][i]) cnt = (cnt+g[n][i])%mod;
	if(ans == 1e18) cout << "-1\n";
	else cout << ans << " " << cnt << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
} 

/*
1
3 4
2 2 2
6 4 2 1                                                                                                                    32 16 8 4 2 1 
*/