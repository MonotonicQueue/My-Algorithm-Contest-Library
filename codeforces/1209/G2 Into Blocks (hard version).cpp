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
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
int n,q,a[N];
set<int> s[N];
struct Segment{
	int mn,mx,lmx,rmx,tag,cnt;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	t[rt].mn = min(t[ls].mn,t[rs].mn);
	t[rt].mx = max(t[ls].mx,t[rs].mx);
	if(t[ls].mn < t[rs].mn){
		t[rt].cnt = t[ls].cnt;
		t[rt].lmx = t[ls].lmx;
		t[rt].rmx = max(t[ls].rmx,t[rs].mx);
	}else if(t[ls].mn > t[rs].mn){
		t[rt].cnt = t[rs].cnt;
		t[rt].rmx = t[rs].rmx;
		t[rt].lmx = max(t[ls].mx,t[rs].lmx);
	}else{
		t[rt].cnt = t[ls].cnt+t[rs].cnt+max(t[rs].lmx,t[ls].rmx);
		t[rt].lmx = t[ls].lmx;
		t[rt].rmx = t[rs].rmx;
	}
}
inline void change(int rt,int d){
	t[rt].mn += d;
	t[rt].tag += d;
}
inline void push_down(int rt){
	if(t[rt].tag){
		change(ls,t[rt].tag);
		change(rs,t[rt].tag);
		t[rt].tag = 0;
	}
}
void update1(int rt,int l,int r,int ql,int qr,int d){
	if(ql > qr) return ;
	if(ql <= l && r <= qr){
		change(rt,d);
		return ;
	}
	push_down(rt);
	int mid = (l+r)>>1;
	if(ql <= mid) update1(ls,l,mid,ql,qr,d);
	if(qr >  mid) update1(rs,mid+1,r,ql,qr,d);
	push_up(rt);
}
void update2(int rt,int l,int r,int pos,int d){
	if(l == r){
		t[rt].mx = t[rt].lmx = d;
		return ;
	}
	push_down(rt);
	int mid = (l+r)>>1;
	if(pos <= mid) update2(ls,l,mid,pos,d);
	else 		   update2(rs,mid+1,r,pos,d);
	push_up(rt);
}
void modify(int col,int d){
	int siz = s[col].size();
	if(!siz) return ;
	update1(1,1,n,*s[col].begin(),*s[col].rbegin()-1,d);
	update2(1,1,n,*s[col].begin(),d > 0 ? siz : 0);
}
int main(){
	n = read(); q = read();
	for(int i=1;i<=n;i++) a[i] = read(),s[a[i]].insert(i);
	for(int i=1;i<=200000;i++) modify(i,1);
	cout << n-t[1].cnt-t[1].lmx-t[1].rmx << "\n";
	while(q--){
		int x = read(),y = read();
		modify(a[x],-1); s[a[x]].erase(x); modify(a[x],1);
		modify(y,-1); s[y].insert(x); modify(y,1);
		a[x] = y;
		cout << n-t[1].cnt-t[1].lmx-t[1].rmx << "\n";
	}
	return 0;
}



