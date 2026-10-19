#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
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
int n,q,a[N],pre[N];
vector<pii> v[N];
set<int> s[N<<2];
void init(){
	for(int i=1;i<=n;i++) pre[i] = 0;
	for(int i=1;i<=n;i++) v[i].clear();
}
//维护每个数要输的最大左端点
int mx[N<<2],f[N];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	mx[rt] = max(mx[ls],mx[rs]);
}
void build(int rt,int l,int r){
	mx[rt] = 0; s[rt].clear();
	if(l == r) return ;
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void update(int rt,int l,int r,int pos,int d){
	if(l == r) return mx[rt] = d,void();
	int mid = (l+r) >> 1;
	if(pos <= mid) update(ls,l,mid,pos,d);
	else 		   update(rs,mid+1,r,pos,d);
	push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return mx[rt];
	int mid = (l+r) >> 1,res = 0;
	if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
	if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
	return res;
}

void insert(int rt,int l,int r,int pos,int d){
    s[rt].insert(d);
    if(l == r) return ;
    int mid = (l+r) >> 1;
	if(pos <= mid) insert(ls,l,mid,pos,d);
	else 		   insert(rs,mid+1,r,pos,d);
}
int ask(int rt,int l,int r,int ql,int qr,int d){
    if(ql > qr) return 0;
    if(ql <= l && r <= qr){
        auto it = s[rt].lower_bound(d);
        if(it == s[rt].begin()) return 0;
        it--;
        return *it;
    }
    int mid = (l+r) >> 1,res = 0;
	if(ql <= mid) res = max(res,ask(ls,l,mid,ql,qr,d));
	if(qr >  mid) res = max(res,ask(rs,mid+1,r,ql,qr,d));
	return res;
}
int ans[N];
int main(){
	int T = read();
	while(T--){
		n = read(); q = read();
		init();
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=q;i++){
			int l = read(),r = read();
			v[r].push_back(mk(l,i));
		}
        build(1,1,n);
		for(int i=1;i<=n;i++){
			if(pre[a[i]]){
                f[i] = ask(1,1,n,pre[a[i]]+1,i-1,pre[a[i]]);
                update(1,1,n,i,f[i]);
            }
            insert(1,1,n,i,pre[a[i]]);
			pre[a[i]] = i;
            for(auto it : v[i]){
                ans[it.se] = query(1,1,n,it.fi,i) < it.fi;
            }
		}
        for(int i=1;i<=q;i++) puts(ans[i] ? "YES" : "NO");
	}
    return 0;
}