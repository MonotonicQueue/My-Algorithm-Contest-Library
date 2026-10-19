#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
int n,Q;
vector<int> G[N];
int dfn[N],pos[N],tot,fa[N],siz[N];
int t[N];
inline void add(int x,int y){
    while(x <= n){
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
int query(int l,int r){
    return ask(r)-ask(l-1);
}
void dfs(int x,int ft){
    dfn[++tot] = x; pos[x] = tot;
    siz[x] = 1; fa[x] = ft;
    for(int y : G[x]){
        if(y == ft) continue;
        dfs(y,x);
        siz[x] += siz[y];
    }
}
int a[N],stk[N],top;
int main(){
    n = read(); Q = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    while(Q--){
        int k = read();
        for(int i=1;i<=k;i++) a[i] = read();
        bool flag = true;
        int i;
        top = 0;
        stack<int> sss;
        for(i=1;i<=k;i++){
            if(!flag) break;
            int x = a[i];
            if(query(pos[x],pos[x]+siz[x]-1)){
                // cout << "111\n";
                flag = false;
                break;
            }
            add(pos[x],1);
            sss.push(pos[x]);
            if(top && fa[x] != stk[top]){
                while(top && fa[x] != stk[top]){
                    if(query(pos[stk[top]],pos[stk[top]]+siz[stk[top]]-1) != siz[stk[top]]){
                        // cout << "111\n";
                        flag = false;
                        break;
                    }
                    top--;
                }
                if(!top){
                    // cout << x << "\n";
                    if(pos[fa[x]] <= pos[stk[1]] && pos[stk[1]] <= pos[fa[x]]+siz[fa[x]]-1){
                    }else{
                        flag = false;
                        break;
                    }
                }
                stk[++top] = x;
            }else{
                stk[++top] = x;
            }
        }
        while(!sss.empty()) add(sss.top(),-1),sss.pop();
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
