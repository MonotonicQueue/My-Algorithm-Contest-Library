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
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 8e5+10;
const int M = 1e6+10;
int n,m,S;
struct Gragh{
	int tot=1,head[N],to[M<<1],nxt[M<<1],edge[M<<1];
	inline void add_edge(int u,int v,int w){
		to[++tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
		edge[tot] = w;
	}
}G1,G2;
int dfn[N],low[N],num,stk[N],Top,cnt,estk[N],eTop;
int msk[N],typ[N];
int qu[N],len;
vector<int>vcc[N];
ll ans;
void tarjan(int x){
	dfn[x] = low[x] = ++num;
	stk[++Top] = x;
	for(int i=G1.head[x];i;i=G1.nxt[i]){
		int y = G1.to[i];
		if(!dfn[y]){
			
			estk[++eTop] = i;
			tarjan(y);
			low[x] = min(low[x],low[y]);
			if(dfn[x] == low[y]){
//				cout << x << " " << y << "\n";
				++cnt;
				int z = 0;
				len = 0;
				do{
					z = stk[Top--];
					vcc[cnt].push_back(z);
					qu[++len] = z;
				}while(z != y);
				qu[++len] = x; 
				vcc[cnt].push_back(x);
				for(int j=1;j<=len;j++) msk[qu[j]] = 0;
//				for(int j=1;j<=len;j++) cout << qu[j] << " ";
//				cout <<  endl;
				do{
					z = estk[eTop--];
					typ[cnt] |=	G1.edge[z];
					msk[G1.to[z]] |= G1.edge[z];
					msk[G1.to[z^1]] |= G1.edge[z];
				}while(z != i);
				int sum = 0;
				for(int j=1;j<=len;j++) sum += msk[qu[j]] == 3;
//				for(int j=1;j<=len;j++) cout << msk[qu[j]] << " ";
				if(sum == 2) ans--;
//				cout << sum << '\n';
			}
		}else{
			low[x] = min(low[x],dfn[y]);
			if(dfn[y] < dfn[x]) estk[++eTop] = i;
		}
	}
}
int fa[N],siz[N];
int get(int x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x,int y){
	x = get(x); y = get(y);
	fa[x] = y;
	siz[y] += siz[x];
}
int main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	S = read(); n = read(); m = read();
	ans = 1ll*n*(n-1)/2;
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		char ch[2]; scanf("%s",ch);
		G1.add_edge(u,v,ch[0] == 'd' ? 1 : 2);
		G1.add_edge(v,u,ch[0] == 'd' ? 1 : 2);
	}
	cnt = n;
	tarjan(1);
	for(int i=1;i<=cnt;i++) siz[i] = i <= n;
	for(int i=1;i<=cnt;i++) fa[i] = i;
	for(int i=n+1;i<=cnt;i++) if(typ[i] == 1) for(int j : vcc[i]) merge(i,j);
	for(int i=1;i<=cnt;i++) if(get(i) == i) ans -= 1ll*siz[i]*(siz[i]-1)/2;
	for(int i=1;i<=cnt;i++) siz[i] = i <= n;
	for(int i=1;i<=cnt;i++) fa[i] = i;
	for(int i=n+1;i<=cnt;i++) if(typ[i] == 2) for(int j : vcc[i]) merge(i,j);
	for(int i=1;i<=cnt;i++) if(get(i) == i) ans -= 1ll*siz[i]*(siz[i]-1)/2;
	cout << ans;
	
	return 0;
}
