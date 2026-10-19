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
const int N = 1e5+10;
int n,m;
int head[N],to[N<<1],nxt[N<<1],tot=1;
double edge[N<<1],deg[N];
inline void add_edge(int u,int v,double w){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
	edge[tot] = w;
	deg[u] += 1;
}
bool ban[N<<1];
double f[N],g[N];
void dfs1(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fa || ban[i]) continue;
		dfs1(y,x);
		if(x != 1) f[x] += (f[y]+edge[i])/(deg[x]-1);
		else f[x] += (f[y]+edge[i])/deg[x];
	}
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fa || ban[i]) continue;
		if(deg[x] != 1) g[y] = (f[y]*(deg[y]-1)+(g[x]*deg[x]-f[y]-edge[i])/(deg[x]-1)+edge[i])/deg[y];
		else g[y] = (f[y]*(deg[y]-1)+(g[x]-f[y]))/deg[y];
		dfs2(y,x);
	}
}
int vis[N],stk[N],top,pos;
bool flag[N],End;
int dfn[N],disl[N],disr[N],path[N],num;
int son[N],fath[N];
void find(int x,int fa){
	vis[x]++;
	if(vis[x] == 2){
		pos = x;
		int z = 0;
		do{
			z = stk[top--];
			flag[z] = 1;
			fath[z] = 2;
		}while(z != x);
		End = 1;
		return ;
	}
	stk[++top] = x;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fa) continue;
		find(y,x);
		if(End) return ;
	}
	top--;
}

void dfs3(int x,int fa){
	dfn[x] = ++num; path[num] = x;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y != fa && flag[y]){
			if(!dfn[y]) dfs3(y,x);
			disr[dfn[x]] = disl[dfn[y]] = edge[i];
			break;
		}
	}
}
double ans;
void dfs4(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y != fa && !flag[y]){
			fath[y] = 1;
			dfs4(y,x);
			son[x]++;
			f[x] += f[y]+edge[i];
		}
	}
	if(son[x]) f[x] /= son[x];
}
void dfs5(int x,int fa,int w){
	g[x] = w;
	if(fath[fa]+son[fa]-1) g[x] += (g[fa]*fath[fa]+f[fa]*son[fa]-f[x]-w)/(fath[fa]+son[fa]-1);
	for(int i=head[x];i;i=nxt[i])
		if(to[i] != fa) dfs5(to[i],x,edge[i]);
}
int main(){
// 	freopen("park6.in","r",stdin);
// 	freopen("park.out","w",stdout);
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		double w = read();
		add_edge(u,v,w); add_edge(v,u,w);
	}
	if(n == m+1){
		dfs1(1,0);
		g[1] = f[1];
		dfs2(1,0);
		for(int i=1;i<=n;i++) ans += g[i]/n;
		printf("%.5lf",ans);
	}else{
		find(1,0);
		dfs3(pos,0);
		for(int i=1;i<=num;i++)
			dfs4(path[i],0);
		#define nxt(x) (x==num?1:x+1)
		#define pre(x) (x==1?num:x-1) 
		for(int i=1;i<=num;i++){
			int x = path[i];
			double P = 0.5;
			for(int j=nxt(i);j!=i;j=nxt(j)){
				int y = path[j];
				if(nxt(j) == i) g[x] += P*(disl[j]+f[y]);
				else g[x] += P*(f[y]*son[y]/(son[y]+1)+disl[j]);
				P /= son[y]+1;
			}
			P = 0.5;
			for(int j=pre(i);j!=i;j=pre(j)){
				int y = path[j];
				if(pre(j) == i) g[x] += P*(disr[j]+f[y]);
				else g[x] += P*(f[y]*son[y]/(son[y]+1)+disr[j]);
				P /= son[y]+1;
			}
			#undef nxt(x)
			#undef pre(x)
			for(int j=head[x];j;j=nxt[j]){
				if(!flag[to[j]]) dfs5(to[j],x,edge[j]);
			}
		}
//		for(int i=1;i<=n;++i) cout  << g[i] <<"\n";
		for(int i=1;i<=n;++i)
			ans += (f[i]*son[i]+g[i]*fath[i])/(son[i]+fath[i]);
		printf("%.5lf",ans/n);
	}
	return 0;
}