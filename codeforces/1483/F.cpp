#include<bits/stdc++.h>
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
const int N = 1e6+10;
int n;
string s[N];
int son[N][26],ed[N],fail[N],tot,edp[N];
vector<int> G[N];
void insert(string &s,int id){
    int p = 0;
    for(char c : s){
        if(!son[p][c-'a']) son[p][c-'a'] = ++tot;
        p = son[p][c-'a'];
    }
    ed[p] = id; edp[id] = p;
}
void bfs(){
    queue<int> q;
    for(int i=0;i<26;i++) if(son[0][i]) q.push(son[0][i]);
    while(!q.empty()){
        int x = q.front(); q.pop();
        G[fail[x]].push_back(x);
        ed[x] = ed[x] ? ed[x] : ed[fail[x]];
        for(int i=0;i<26;i++)
            if(son[x][i]){
                q.push(son[x][i]);
                fail[son[x][i]] = son[fail[x]][i];
            }else son[x][i] = son[fail[x]][i];
    }
}
int dfn[N],cnt,siz[N];
void dfs(int x){
    dfn[x] = ++cnt; siz[x] = 1;
    for(int y : G[x])
        dfs(y),siz[x] += siz[y];
}
int t[N],ct[N];
inline void add(int x,int y){
    while(x <= cnt){
        t[x] += y;
        x += x&(-x);
    }
}
inline int ask(int x){
    int res = 0;
    while(x){
        res += t[x];
        x -= x&(-x);
    }
    return res;
}
inline int query(int l,int r){
    return ask(r)-ask(l-1);
}
int main(){
    n = read();
    for(int i=1;i<=n;i++) cin >> s[i];
    for(int i=1;i<=n;i++) insert(s[i],i);
    bfs(); dfs(0);
    int ans = 0;
    for(int i=1;i<=n;i++){
        vector<int> v1,v2;
        int p = 0;
        for(int j=0;j<(int)s[i].size();j++){
            v1.push_back(p = son[p][s[i][j]-'a']);
            add(dfn[p],1);
        }
        int pre = 1e9;
        for(int j=v1.size()-1;~j;j--){
            int id = j == (int)v1.size()-1 ? ed[fail[v1[j]]] : ed[v1[j]];
            if(!id) continue;
            int l = j-s[id].size();
            if(l < pre) pre = l,ct[id]++,v2.push_back(id);
        }
        for(int x : v2){
            if(!ct[x]) continue;
            if(ct[x] == query(dfn[edp[x]],dfn[edp[x]]+siz[edp[x]]-1)) ans++;
            ct[x] = 0;
        }
        for(int x : v1) add(dfn[x],-1);
    }
    cout << ans;
    return 0;
}
