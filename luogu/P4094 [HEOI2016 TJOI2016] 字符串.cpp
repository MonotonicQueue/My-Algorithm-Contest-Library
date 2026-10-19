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
const int N = 1e6+10;
int n,Q;
char s[N];
int t1[N],t2[N],cnt[N],sa[N],rk[N],height[N];
void getsa(int *x,int *y){
	int m = 127;
	for(int i=1;i<=m;i++) cnt[i] = 0;
	for(int i=1;i<=n;i++) cnt[x[i] = s[i]]++;
	for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
	for(int i=n;i;i--) sa[cnt[x[i]]--] = i;
	for(int k=1;k<=n;k*=2){
		int p = 0;
		for(int i=n-k+1;i<=n;i++) y[++p] = i;
		for(int i=1;i<=n;i++) if(sa[i] > k) y[++p] = sa[i]-k;

		for(int i=1;i<=m;i++) cnt[i] = 0;
		for(int i=1;i<=n;i++) cnt[x[i]]++;
		for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
		for(int i=n;i;i--) sa[cnt[x[y[i]]]--] = y[i];

		swap(x,y); p = 1;
		x[sa[1]] = 1;
		for(int i=2;i<=n;i++)
			x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k] ? p : ++p;
		m = p;
		if(m == n) break;
	}
}
void getheight(){
	for(int i=1;i<=n;i++) rk[sa[i]] = i;
	for(int i=1,k=0;i<=n;i++){
		if(rk[i] == 1) continue;
		if(k) k--;
		int j = sa[rk[i]-1];
		while(s[i+k] == s[j+k]) k++;
		height[rk[i]] = k;
	}
}
int st[N][20],Lg[N];
inline void init(){
	getsa(t1,t2); getheight();
	for(int i=1;i<=n;i++) st[i][0] = height[i];
	for(int j=1;j<=18;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=2;i<=n;i++) Lg[i] = Lg[i>>1]+1;
}
int lcp(int x,int y){
	if(x == y) return n-x+1;
	x = rk[x],y = rk[y];
	if(x > y) swap(x,y); x++;
	int t = Lg[y-x+1];
	return min(st[x][t],st[y-(1<<t)+1][t]);
}
int root[N],tot;
struct Segment{
	int cnt,ls,rs;
}t[N*20];
int update(int u,int l,int r,int pos){
	int rt = ++tot;
	t[rt] = t[u]; t[rt].cnt++;
	if(l == r) return rt;
	int mid = (l+r) >> 1;
	if(pos <= mid) t[rt].ls = update(t[rt].ls,l,mid,pos);
	else 		   t[rt].rs = update(t[rt].rs,mid+1,r,pos);
	return rt;
}
int pre(int u,int v,int l,int r,int pos){
	if(!(t[v].cnt-t[u].cnt)) return -1;
	if(l == r) return l;
	int mid = (l+r) >> 1;
	if(pos > mid){
		int res = pre(t[u].rs,t[v].rs,mid+1,r,pos);
		if(res != -1) return res;
	}
	return pre(t[u].ls,t[v].ls,l,mid,pos);
}
int nxt(int u,int v,int l,int r,int pos){
	if(!(t[v].cnt-t[u].cnt)) return -1;
	if(l == r) return l;
	int mid = (l+r) >> 1;
	if(pos <= mid){
		int res = nxt(t[u].ls,t[v].ls,l,mid,pos);
		if(res != -1) return res;
	}
	return nxt(t[u].rs,t[v].rs,mid+1,r,pos);
}
int main(){
	n = read(); Q = read();
	scanf("%s",s+1);
	init();
	for(int i=1;i<=n;i++)
		root[i] = update(root[i-1],1,n,rk[i]);
	while(Q--){
		int l1 = read(),r1 = read(),l2 = read(),r2 = read();
		int l = 1,r = min(r1-l1+1,r2-l2+1),res = 0;
		while(l <= r){
			int mid = (l+r) >> 1;
			int p = pre(root[l1-1],root[r1-mid+1],1,n,rk[l2]),
				q = nxt(root[l1-1],root[r1-mid+1],1,n,rk[l2]);
			int rs = -1;
			if(p != -1) rs = max(rs,lcp(sa[p],l2));
			if(q != -1) rs = max(rs,lcp(sa[q],l2));
			if(rs >= mid) res = mid,l = mid+1;
			else r = mid-1;
		}
		cout << res << "\n";
	}
	return 0;
}