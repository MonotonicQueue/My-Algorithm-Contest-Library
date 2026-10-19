#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}
const int N = 2e3+10;
const int M = 5e3+10;
int n,m; 
int fa[N];
int get(int x){
	if(x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
signed main(){
	n =  read(); m = read();
	for(int i=1;i<=n*2;i++) fa[i] = i;
	while(m--){
		char op; cin >> op;
		int p,q; p = read(); q = read();
		if(op == 'E'){
			fa[get(p+n)] = get(q);
			fa[get(q+n)] = get(p);
		}else fa[get(p)] = get(q);
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		if(fa[i] == i) ans++; 
	cout << ans;
	return 0;
}