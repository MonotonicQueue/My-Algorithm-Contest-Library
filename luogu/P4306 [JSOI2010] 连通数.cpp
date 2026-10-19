#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	char ch = getchar();
	while(ch != '0' && ch != '1') ch = getchar();
	return ch - '0';
}
const int N = 2100;
const int M = 4e6+10;
int n;
int dfn[N],low[N],num,ans;
int stk[N],top,c[N];
bool ins[N];
vector<int> scc[N];
int cnt;
bitset<2100> s[N];
struct Gragh2 {
	int head[N],to[M],nxt[M],in[N],tot;
	int siz[N];
	inline void add_edge(int u,int v) {
		to[++tot] = v;
		in[v]++;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	void init() {
		for(int i=1; i<=cnt; i++)
			siz[i] = scc[i].size(),s[i][i] = 1;
	}
	void work(){
		init();
		queue<int> q;
		for(int i=1;i<=cnt;i++)
			if(!in[i]) q.push(i);
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int i=head[x];i;i=nxt[i]){
				int y = to[i];
				in[y]--;
				s[y] = s[y]|s[x];
				if(!in[y]) q.push(y);
			}
		}
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				if(s[i][j]) ans += siz[i]*siz[j];
			}
		}
		printf("%d",ans);
	}
} G2;
struct Gragh1 {
	int head[N],to[M],nxt[M],tot;
	inline void add_edge(int u,int v) {
		to[++tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	void tarjan(int x) {
		dfn[x] = low[x] = ++num;
		stk[++top] = x;
		ins[x] = true;
		for(int i=head[x]; i; i=nxt[i]) {
			int y = to[i];
			if(!dfn[y]) {
				tarjan(y);
				low[x] = min(low[x],low[y]);
			} else if(ins[y]) low[x] = min(low[x],dfn[y]);
		}
		if(dfn[x] == low[x]) {
			cnt++;
			int y;
			do {
				y = stk[top--];
				ins[y] = 0;
				c[y] = cnt;
				scc[cnt].push_back(y);
			} while(x != y);
		}
	}
	void build() {
		for(int x=1; x<=n; x++)
			for(int i=head[x]; i; i=nxt[i]) {
				int y = to[i];
				if(c[x] != c[y]) G2.add_edge(c[y],c[x]);
			}
	}
} G1;
int main() {
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			int flag = read();
			if(flag) G1.add_edge(i,j);
		}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) G1.tarjan(i);
	G1.build(); G2.work();
	return 0;
}