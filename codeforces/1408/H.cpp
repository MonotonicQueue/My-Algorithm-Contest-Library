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
const int N = 5e5+10;
int n,m,z;
vector<int> v[N];
int b[N];
struct node{
	int l,r;
}a[N]; int tot;
bool cmp(node x,node y){
	return x.r != y.r ? x.r < y.r : x.l < y.l;
}
int fa[N];
int get(int x){
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
int main(){
	int T = read();
	while(T--){
		n = read();
		m = z = 0;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			int x = read();
			if(x == 0) b[++m] = i;
			else v[x].push_back(i);
		}
		z = m/2;
		int L,R; tot = 0;
		if(m & 1) L = R = b[m-z];
		else L = b[z],R = b[m-z];
		for(int k=1;k<=n;k++){
			if(v[k].empty()) continue;
			int mx = 0,mn = n+1;
			for(int i:v[k]){
				if(i > L) mn = min(mn,i);
				if(i < R) mx = max(mx,i);
			}
			int t1 = lower_bound(b+1,b+1+m,mx)-b-1,t2 = m-(lower_bound(b+1,b+1+m,mn)-b-1);
			a[++tot] = node{z-t2+1,t1+z};
		}
		sort(a+1,a+1+tot,cmp);
		m = z*2;
		for(int i=1;i<=m+1;i++) fa[i] = i;
		int ans = 0;
		for(int i=1;i<=tot;i++){
			int l = a[i].l,r = a[i].r;
			l = get(l);
			if(l <= r) ans++,fa[l] = l+1;
		}
		cout << min(ans,z) << "\n";
	}
	return 0;
}




