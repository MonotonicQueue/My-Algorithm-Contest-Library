#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') ch = getchar(),r = -1;
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,m;
char a[N],s[N];
int head[N],to[N<<1],nxt[N<<1],tot;
inline void add_edge(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
const ull P = 131;
bool vis[N];
ull pre[N],suf[N];
int siz[N],root,Siz,Max;
void getroot(int x,int fa){
	siz[x] = 1;
	int maxpart = 0;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fa || vis[y]) continue;
		getroot(y,x);
		siz[x] += siz[y];
		maxpart = max(maxpart,siz[y]);
	}
	maxpart = max(maxpart,Siz-siz[x]);
	if(maxpart < Max){
		Max = maxpart;
		root = x;
	}
}
ll ans;
int sum[N][2],num[N][2],Dep[N];
void dfs(int x,int fa,ull h,int dep){
	h = h*P+a[x];
	if(h == pre[dep]) num[(dep-1)%m+1][0]++,ans += sum[m-(dep-1)%m][1];
	if(h == suf[dep]) num[(dep-1)%m+1][1]++,ans += sum[m-(dep-1)%m][0];
	Dep[x] = dep;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(vis[y] || y == fa) continue;
		dfs(y,x,h,dep+1);
		Dep[x] = max(Dep[x],Dep[y]);
	}
}
void solve(int x){
	vis[x] = true;
	sum[1][0] = sum[1][1] = 1;
	int Maxdep = 0;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(vis[y]) continue;
		dfs(y,x,a[x],2);
		int k = min(Dep[y],m);
		Maxdep = max(Maxdep,k);
		for(int j=1;j<=k;j++) sum[j][0] += num[j][0],sum[j][1] += num[j][1],num[j][0] = num[j][1] = 0;
	}
	for(int i=1;i<=Maxdep;i++) sum[i][0] = sum[i][1] = 0;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(vis[y]) continue;
		Siz = Max = siz[y];
		root = 0;
		getroot(y,x);
		solve(root);
	}
}
int main(){
	int C = read();
	while(C--){
		n = read(); m = read();
		scanf("%s",a+1);
		memset(vis,0,sizeof(vis));
		tot = 0; memset(head,0,sizeof(head));
		for(int i=1;i<n;i++){
			int u = read(),v = read();
			add_edge(u,v); add_edge(v,u);
		}
		scanf("%s",s+1);
		ans = 0;
		ull pw = 1;
		for(int i=1;i<=n;i++){
			pre[i] = pre[i-1]+s[(i-1)%m+1]*pw;
			suf[i] = suf[i-1]+s[m-(i-1)%m]*pw;
			pw *= P;
		}
		Siz = Max = n; root = 0;
		getroot(1,0);
		solve(root);
		cout << ans <<"\n";
	}
	return 0; 
}
