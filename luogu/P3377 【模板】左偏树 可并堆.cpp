#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
int n,m;
int rt[N];
bool flag[N];
struct Tree{
	int val,ls,rs;
	int d;
}t[N];
int merge(int x,int y){
	if(!x || !y) return x+y;
	if(t[x].val > t[y].val || (t[x].val == t[y].val && x > y)) swap(x,y);
	t[x].rs = merge(t[x].rs,y);
	if(t[t[x].ls].d < t[t[x].rs].d) swap(t[x].ls,t[x].rs);
	t[x].d = t[t[x].rs].d+1;
	return x;
}
int get(int x){
	return rt[x] == x ? x : rt[x] = get(rt[x]);
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) t[i].val = read();
	for(int i=1;i<=n;i++) rt[i] = i;
	while(m--){
		int op = read();
		if(op == 1){
			int x = read(),y = read();
			if(flag[x] || flag[y]) continue;
			x = get(x); y = get(y);
			if(x == y) continue;
			rt[x] = rt[y] = merge(rt[x],rt[y]);
		}else{
			int x = read();
			if(flag[x]){
				puts("-1");
				continue;
			}
			x = get(x);
			cout << t[x].val << "\n"; 
			flag[x] = true;
			rt[t[x].ls] = rt[t[x].rs] = rt[x] = merge(t[x].ls,t[x].rs);
			
		}
	}
	return 0;
} 