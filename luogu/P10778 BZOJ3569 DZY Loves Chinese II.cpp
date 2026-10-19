#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e5+10;
const int M = 1e6+10;
int n,m;
int head[N],to[M],nxt[M],tot=1;
inline void add_edge(int u,int v){
    to[++tot] = v; nxt[tot] = head[u];
    head[u] = tot;
}
mt19937_64 rnd(time(0));
ull w[M];
int dfn[N],cnt;
void dfs(int x,int fr){
    dfn[x] = ++cnt;
    ull sum = 0;
    for(int i=head[x];i;i=nxt[i]){
        if((i >> 1) == fr) continue;
        int y = to[i];
        if(dfn[y]){
            if(dfn[y] < dfn[x])
                w[i >> 1] = rnd();
        }else dfs(y,i>>1);
        sum ^= w[i >> 1];
    }
    w[fr] = sum;
}
ull bas[70];
void clear(){
    memset(bas,0,sizeof(bas));
}
bool ins(ull x){
    for(int i=63;~i;i--){
        if((x >> i) & 1){
            if(bas[i]) x ^= bas[i];
            else return bas[i] = x,true;
        }
    }
    return false;
}
signed main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        add_edge(u,v); add_edge(v,u);
    }
    dfs(1,0);
    int Q = read(),lst = 0;
    while(Q--){
        int k = read();
        clear();
        bool flag = true;
        for(int i=1;i<=k;i++){
            int x = read(); x ^= lst;
            flag &= ins(w[x]);
        }
        lst += flag;
        puts(flag ? "Connected" : "Disconnected");
    }
	return 0;
}
