#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
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
int n,pos[N];
char ch[N];
int son[N][26],fa[N],fail[N],tot;
bool vis[N][26];
vector<int> ed[N];
inline void insert(){
    int len = strlen(ch+1),p = 0;
    for(int i=1;i<=len;i++){
        if(ch[i] == 'B') p = fa[p];
        else if(ch[i] == 'P') pos[++n] = p,ed[p].push_back(n);
        else{
            int c = ch[i]-'a';
            if(!son[p][c]) son[p][c] = ++tot,fa[tot] = p,vis[p][c] = true;
            p = son[p][c];
        }
    }
}
vector<int> G[N];
inline void getFail(){
    queue<int> q;
    for(int i=0;i<26;i++) if(son[0][i]) q.push(son[0][i]);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0;i<26;i++)
            if(son[x][i]){
                fail[son[x][i]] = son[fail[x]][i];
                q.push(son[x][i]);
            }else son[x][i] = son[fail[x]][i];
    }
    for(int i=1;i<=tot;i++) G[fail[i]].push_back(i);
}
int dfn[N],cnt,siz[N];
void dfs(int x){
    dfn[x] = ++cnt; siz[x] = 1;
    for(int y : G[x]){
        dfs(y);
        siz[x] += siz[y];
    }
}
int t[N];
void add(int x,int y){
    while(x <= cnt){
        t[x] += y;
        x += x&(-x);
    }
}
int ask(int x){
    int res = 0;
    while(x){
        res += t[x];
        x -= x&(-x);
    }
    return res;
}
int m,ans[N];
struct Ques{
    int x,y;
}q[N];
vector<int> a[N];
void calc(int x){
    for(int y : ed[x]){
        for(int i : a[y]){
            ans[i] = ask(dfn[pos[q[i].x]]+siz[pos[q[i].x]]-1)-ask(dfn[pos[q[i].x]]-1);
        }
    }
}
void solve(int x){
    add(dfn[x],1);
    calc(x);
    for(int i=0;i<26;i++)
        if(vis[x][i]) solve(son[x][i]);
    add(dfn[x],-1);
}
signed main(){
	cin >> ch+1;
    insert(); getFail();
    dfs(0);
    m = read();
    for(int i=1;i<=m;i++){
        q[i].x = read(); q[i].y = read();
        a[q[i].y].push_back(i);
    }
    solve(0);
    for(int i=1;i<=m;i++) cout << ans[i] << "\n";
	return 0;
}

