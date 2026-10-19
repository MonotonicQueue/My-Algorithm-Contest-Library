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
const int N = 1e6+10;
int n;
struct node{
	int l,r,x;
}a[N];
bool cmp(node x,node y){
	return x.x < y.x;
}
int tmp[N],tot;
vector<int> lt[N],rt[N];
vector<node> G;
int fa[N];
int get(int x){
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
int main(){
	int T = read();
	while(T--){
		n = read();
		tot = 0;
		for(int i=1;i<=n;i++){
			a[i].l = read(); a[i].r = read(); a[i].x = read();
			tmp[++tot] = a[i].l; tmp[++tot] = a[i].r;
		}
		sort(tmp+1,tmp+1+tot); tot = unique(tmp+1,tmp+1+tot)-1-tmp;
		for(int i=1;i<=n;i++){
			a[i].l = lower_bound(tmp+1,tmp+1+tot,a[i].l)-tmp;
			a[i].r = lower_bound(tmp+1,tmp+1+tot,a[i].r)-tmp;
		}
		for(int i=1;i<=tot;i++) lt[i].clear(),rt[i].clear();
		for(int i=1;i<=n;i++){
			lt[a[i].l].push_back(i);
			rt[a[i].r].push_back(i);
		}
		set<pii> s;
		G.clear();
		for(int i=1;i<=tot;i++){
			for(int x : lt[i]){
				auto it = s.upper_bound(mk(a[x].x,x));
				if(it != s.end()){
					G.push_back(node{x,(it->se),(it->fi)-a[x].x});
				}
				if(it != s.begin()){
					it--;
					G.push_back(node{x,(it->se),a[x].x-(it->fi)});
				}
				s.insert(mk(a[x].x,x));
			}
			for(int x : rt[i]) s.erase(mk(a[x].x,x));
		}
		for(int i=1;i<=n;i++) fa[i] = i;
		sort(G.begin(),G.end(),cmp);
		int cnt = 0; ll ans = 0;
		for(node it : G){
			int l = it.l,r = it.r;
			if(get(l) == get(r)) continue;
			fa[get(l)] = fa[get(r)];
			cnt++; ans += it.x;
			if(cnt == n-1) break;
		}
		if(cnt != n-1) puts("-1");
		else cout << ans << "\n";
	}
	return 0;
}