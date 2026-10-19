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
int n,m;
struct node{int l,r,s;};
int a[N],ans[N];
int t[N];
void add(int x,int y){
	while(x <= 200000){
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
int query(int l,int r){
	return ask(r)-ask(l-1);
}
void solve(int l,int r,vector<node> &q){
	if(q.empty()) return ;
	if(l == r) return ans[l] = q.size(),void();
	int mid = (l+r) >> 1;
	for(int i=l;i<=mid;i++) add(a[i],1);
	vector<node> ql,qr;
	for(node &it : q){
		int k = query(it.l,it.r);
		if(k < it.s){
			it.s -= k;
			qr.push_back(it);
		}else ql.push_back(it);
	}
	for(int i=l;i<=mid;i++) add(a[i],-1);
	solve(l,mid,ql); solve(mid+1,r,qr);
}
int main(){
	n = read(); m = read();
	vector<node> q;
	for(int i=1;i<=n;i++){
		int l = read(),r = read(),s = read();
		q.push_back(node{l,r,s});
	}
	for(int i=1;i<=m;i++) a[i] = read();
	solve(1,m+1,q);
	for(int i=1;i<=m;i++) cout << ans[i] << "\n";
    return 0;
}

