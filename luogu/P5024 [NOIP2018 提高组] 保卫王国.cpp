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
const int N = 1e5+10;
const ll inf = 1e18;
int n,Q; string type;
vector<int> G[N];
ll f[N][2],g[N][2],p[N];
struct Matrix{
    ll mat[2][2];
    Matrix(){
        memset(mat,0x3f,sizeof(mat));
    }
    Matrix operator*(const Matrix o)const{
        Matrix res;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    res.mat[i][j] = min(res.mat[i][j],mat[i][k]+o.mat[k][j]);
        return res;
    }
}val[N],t[N<<2],Mat;
int siz[N],son[N],fa[N],top[N],dfn[N],tot,raw[N],ed[N];
void dfs0(int x,int ft){
    fa[x] = ft;
    siz[x] = 1;
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
    g[x][0] = p[x];
    if(son[x]) dfs1(son[x],topx);
    else ed[topx] = x;
    for(int y : G[x]){
        if(y == fa[x] || y == son[x]) continue;
        dfs1(y,y);
        g[x][0] += min(f[y][0],f[y][1]);
        g[x][1] += f[y][1];
    }
    f[x][0] = g[x][1]+f[son[x]][1];
    f[x][1] = min(f[son[x]][0],f[son[x]][1])+g[x][0];
    val[x].mat[0][0] = inf;
    val[x].mat[0][1] = g[x][1];
    val[x].mat[1][0] = val[x].mat[1][1] = g[x][0];
}
#define ls rt<<1
#define rs rt<<1|1
void push_up(int rt){
    t[rt] = t[ls]*t[rs];
}
void build(int rt,int l,int r){
    if(l == r){
        t[rt] = val[raw[l]];
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
void update(int rt,int l,int r,int pos){
    if(l == r){
        t[rt] = val[raw[pos]];
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid) update(ls,l,mid,pos);
    else update(rs,mid+1,r,pos);
    push_up(rt);
}
Matrix query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt];
    int mid = (l+r) >> 1;
    if(ql >  mid) return query(rs,mid+1,r,ql,qr);
    if(qr <= mid) return query(ls,l,mid,ql,qr);
    return query(ls,l,mid,ql,qr)*query(rs,mid+1,r,ql,qr);
}
void update_range(int x,int op,ll Val){
    if(op == 1) val[x].mat[0][1] = Val;
    else val[x].mat[1][0] = val[x].mat[1][1] = Val;
    while(x){
    	update(1,1,n,dfn[x]);
        int y = top[x];
        Matrix res = query(1,1,n,dfn[y],dfn[ed[y]])*Mat;
        val[fa[y]].mat[0][1] -= f[y][1];
        val[fa[y]].mat[1][0] -= min(f[y][0],f[y][1]);
        val[fa[y]].mat[1][1] -= min(f[y][0],f[y][1]);
        f[y][0] = res.mat[0][0];
        f[y][1] = res.mat[1][0];
        val[fa[y]].mat[0][1] += f[y][1];
        val[fa[y]].mat[1][0] += min(f[y][0],f[y][1]);
        val[fa[y]].mat[1][1] += min(f[y][0],f[y][1]);
        x = fa[y];
    }
}
int main(){
	Mat.mat[0][0] = Mat.mat[0][1] = Mat.mat[1][0] = Mat.mat[1][1] = 0;
    n = read(); Q = read(); cin >> type;
    for(int i=1;i<=n;i++) p[i] = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs0(1,0); dfs1(1,1);
    build(1,1,n);
    while(Q--){
        int a = read(),x = read(),b = read(),y = read();
        if(!x && !y && (fa[a] == b || fa[b] == a)){
            puts("-1");
            continue;
        }
        update_range(a,x,inf); update_range(b,y,inf);
        cout << min(f[1][0],f[1][1]) << "\n";
        if(x) update_range(a,x,g[a][1]);
        else update_range(a,x,g[a][0]);
        if(y) update_range(b,y,g[b][1]);
        else update_range(b,y,g[b][0]);
    }
    return 0;
}
