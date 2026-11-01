#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,k,a[N];
int son[N*31][2],siz[N*31],tot;
void insert(int x){
	int p = 0;
	for(int i=30;~i;i--){
		int c = (x >> i) & 1;
		if(!son[p][c]) son[p][c] = ++tot;
		p = son[p][c]; siz[p]++;
	}
}
int kth(int x,int k){
	int p = 0,res = 0;
	for(int i=30;~i;i--){
		int c = (x >> i) & 1;
		if(siz[son[p][c]] >= k) p = son[p][c];
		else k -= siz[son[p][c]],res += (1<<i),p = son[p][c^1];
	}
	// cout << k << "\n";
	return res;
}
struct node{
	int x,k,id;
};
bool operator<(const node x,const node y){
	return x.x > y.x;
}
priority_queue<node> q;
int main(){
	n = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) insert(a[i]);
	for(int i=1;i<=n;i++) q.push(node{kth(a[i],2),2,i});
	for(int i=1;i<=2*k;i++){
		node it = q.top(); q.pop();
		if(i & 1) cout << it.x << " ";
		if(it.k == n) continue;
		q.push(node{kth(a[it.id],it.k+1),it.k+1,it.id});
	}
	return 0;
}