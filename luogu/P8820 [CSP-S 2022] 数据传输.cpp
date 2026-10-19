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
const int N = 2e5+10;
const ll inf = 1e18;
int n,Q,k;
ll val[N];
vector<int> G[N];
int siz[N],son[N],top[N],dep[N];
int fa[N],dfn[N],raw[N],tot,fat[N][20];
void dfs0(int x,int ft){
    siz[x] = 1; fa[x] = ft;
    dep[x] = dep[ft]+1;
    fat[x][0] = fa[x];
    for(int i=1;i<=18;i++) fat[x][i] = fat[fat[x][i-1]][i-1];
    for(int y : G[x]){
        if(y == ft) continue;
        dfs0(y,x);
        siz[x] += siz[y];
        if(siz[y] > siz[son[x]]) son[x] = y;
    }
}
void dfs1(int x,int topx){
    dfn[x] = ++tot; raw[tot] = x;
    top[x] = topx;
    if(!son[x]) return ;
    dfs1(son[x],topx);
    for(int y : G[x]){
        if(y == fa[x] || y == son[x]) continue;
        dfs1(y,y);
    }
}
int lca(int u,int v){
    while(top[u] != top[v]){
        if(dep[top[u]] > dep[top[v]]) swap(u,v);
        v = fa[top[v]];
    }
    return dep[u] < dep[v] ? u : v;
}
namespace Sub1{
    ll sum[N];
    void dfs(int x){
        sum[x] += val[x];
        for(int y : G[x]){
            if(y == fa[x]) continue;
            sum[y] += sum[x];
            dfs(y);
        }
    }
    inline void solve(){
        dfs(1);
        while(Q--){
            int u = read(),v = read();
            int d = lca(u,v);
            cout << sum[u]+sum[v]-sum[d]-sum[fa[d]] << "\n";
        }
    }
}
namespace Sub2{
    struct Matrix{
        ll mat[3][3];
        Matrix(){
            memset(mat,0x3f,sizeof(mat));
        }
        Matrix operator*(const Matrix &o)const{
            Matrix res;
            for(int i=0;i<k;i++)
                for(int j=0;j<k;j++)
                    for(int h=0;h<k;h++)
                        res.mat[i][j] = min(res.mat[i][j],mat[i][h]+o.mat[h][j]);
            return res;
        }
    }a[N],Mat,pre[N],suf[N],t1[N<<2],t2[N<<2];
    #define ls rt<<1
    #define rs rt<<1|1
    inline void push_up(int rt){
        t1[rt] = t1[ls]*t1[rs];
        t2[rt] = t2[rs]*t2[ls];
    }
    void build(int rt,int l,int r){
        if(l == r){
            t1[rt] = t2[rt] = a[raw[l]];
            return ;
        }
        int mid = (l+r) >> 1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(rt);
    }
    Matrix query1(int rt,int l,int r,int ql,int qr){
        if(ql <= l && r <= qr) return t1[rt];
        int mid = (l+r) >> 1;
        if(qr <= mid) return query1(ls,l,mid,ql,qr);
        if(ql >  mid) return query1(rs,mid+1,r,ql,qr);
        return query1(ls,l,mid,ql,qr)*query1(rs,mid+1,r,ql,qr);
    }
    Matrix query2(int rt,int l,int r,int ql,int qr){
        if(ql <= l && r <= qr) return t2[rt];
        int mid = (l+r) >> 1;
        if(qr <= mid) return query2(ls,l,mid,ql,qr);
        if(ql >  mid) return query2(rs,mid+1,r,ql,qr);
        return query2(rs,mid+1,r,ql,qr)*query2(ls,l,mid,ql,qr);
    }
    void dfs(int x,int ft){
        if(top[x] == x) pre[x] = suf[x] = a[x];
        else pre[x] = a[x]*pre[ft],suf[x] = suf[ft]*a[x];
        for(int y : G[x]){
            if(y == fa[x]) continue;
            dfs(y,x);
        }
    }
    Matrix query_range(int u,int v){
        Matrix L,R;
        int d = lca(u,v);
        if(dep[d] < dep[u]){
            R.mat[0][0] = val[u];
            u = fa[u];
        }else{
            R.mat[0][0] = val[v];
            v = fa[v];
            swap(u,v);
        }
        L.mat[0][0] = 0;
        while(top[u] != top[v]){
            if(dep[top[u]] > dep[top[v]]){
                R = suf[u]*R;
                u = fa[top[u]];
            }else{
                L = L*pre[v];
                v = fa[top[v]];
            }
        }
        // for(int i=0;i<k;i++,puts(""))
        //     for(int j=0;j<k;j++) cout << (L*query1(1,1,n,dfn[v],dfn[u])).mat[i][j] << " ";
        if(dep[u] > dep[v]) return L*query1(1,1,n,dfn[v],dfn[u])*R;
        else return L*query2(1,1,n,dfn[u],dfn[v])*R;
    }
    inline void solve(){
        for(int i=0;i<k;i++) Mat.mat[i][0] = 0;
        if(k == 2){
            for(int i=1;i<=n;i++){
                a[i].mat[0][0] = a[i].mat[0][1] = val[i];
                a[i].mat[1][0] = 0; a[i].mat[1][1] = inf;
            }
        }else{
            for(int i=1;i<=n;i++){
                a[i].mat[0][0] = a[i].mat[0][1] = a[i].mat[0][2] = val[i];
                a[i].mat[1][0] = a[i].mat[2][1] = 0;
                for(int y : G[i]) a[i].mat[1][1] = min(a[i].mat[1][1],val[y]);
                a[i].mat[1][2] = a[i].mat[2][0] = a[i].mat[2][2] = inf;
            }
        }
        dfs(1,0);
        build(1,1,n);
        while(Q--){
            int u = read(),v = read();
            Matrix res = query_range(u,v);
            // for(int i=0;i<k;i++,puts(""))
            //     for(int j=0;j<k;j++) cout << res.mat[i][j] << " ";
            cout << res.mat[0][0] << "\n";
        }
    }
}
int main(){
    // freopen("transmit.in","r",stdin);
    // freopen("transmit.out","w",stdout);
    n = read(); Q = read(); k = read();
    for(int i=1;i<=n;i++) val[i] = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs0(1,0); dfs1(1,1);
    if(k == 1) Sub1::solve();
    else       Sub2::solve();
    return 0;
}