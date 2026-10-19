#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int D = 5e5;
int n,Q,s,a[N];
vector<pii> G[N];
#define ls (rt<<1)
#define rs (rt<<1|1)
void build(int rt,int l,int r){
	if(l == r) return a[l] = rt,void();
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	G[rt].emplace_back(ls,0);
	G[rt].emplace_back(rs,0);
	G[ls+D].emplace_back(rt+D,0);
	G[rs+D].emplace_back(rt+D,0);
}
void update(int rt,int l,int r,int v,int ql,int qr,int w,int op){
	if(ql <= l && r <= qr){
		if(!op) G[v].emplace_back(rt,w);
		else 	G[rt+D].emplace_back(v,w);
		return ;
	}
	int mid = (l+r) >> 1;
	if(ql <= mid) update(ls,l,mid,v,ql,qr,w,op);
	if(qr >  mid) update(rs,mid+1,r,v,ql,qr,w,op);
}
ll dis[N];
bool vis[N];
int main(){
	n = read(); Q = read(); s = read();
	build(1,1,n);
	for(int i=1;i<=n;i++){
		G[a[i]].emplace_back(a[i]+D,0);
		G[a[i]+D].emplace_back(a[i],0);
	}
	while(Q--){
		int op = read(),v = read();
		if(op == 1){
			int u = read(),w = read();
			G[a[v]].emplace_back(a[u],w);
		}else{
			int l = read(),r = read(),w = read();
			update(1,1,n,a[v],l,r,w,op&1);
		}
	}
	priority_queue<pair<ll,int>> q;
	q.push(mk(0,a[s]));
	memset(dis,0x3f,sizeof(dis));
	dis[a[s]] = 0;
	while(!q.empty()){
		auto [d,x] = q.top(); q.pop();
		if(vis[x]) continue;
		vis[x] = true;
		for(auto [y,w] : G[x]){
			if(dis[y] > dis[x]+w){
				dis[y] = dis[x]+w;
				q.push(mk(-dis[y],y));
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(dis[a[i]] < 1e18) cout << dis[a[i]] << " ";
		else  cout << "-1 ";
    return 0;
}