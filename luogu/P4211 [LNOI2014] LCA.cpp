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
const int mod = 201314;
int n,m,fa[N],tot;
vector<int> G[N];
struct Ques{
    int x,z,op,id;
}q[N];
bool cmp(Ques x,Ques y){
    return x.x < y.x;
}
int siz[N],son[N];
int top[N],dfn[N],cnt,raw[N];
void dfs1(int x){
    siz[x] = 1;
    for(int y : G[x]){
        dfs1(y);
        siz[x] += siz[y];
        if(siz[y] > siz[son[x]]) son[x] = y;
    }
}
void dfs2(int x,int topx){
    top[x] = topx;
    dfn[x] = ++cnt;
    raw[cnt] = x;
    if(!son[x]) return ;
    dfs2(son[x],topx);
    for(int y : G[x])
        if(y != son[x]) dfs2(y,y);
}
ll t[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt] = (t[ls]+t[rs])%mod;
}
inline void change(int rt,int l,int r,ll d){
    t[rt] = (t[rt]+(r-l+1)*d)%mod;
    tag[rt] = (tag[rt]+d)%mod;
}
void push_down(int rt,int l,int r){
    if(tag[rt]){
        int mid = (l+r) >> 1;
        change(ls,l,mid,tag[rt]);
        change(rs,mid+1,r,tag[rt]);
        tag[rt] = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,ll d){
    if(ql <= l && r <= qr) return change(rt,l,r,d);
    int mid = (l+r) >> 1;
    push_down(rt,l,r);
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt];
    push_down(rt,l,r);
    int mid = (l+r) >> 1,res = 0;
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res%mod;
}
void update_range(int x){
    while(x){
        update(1,1,n,dfn[top[x]],dfn[x],1);
        x = fa[top[x]];
    }
}
int query_range(int x){
    int res = 0;
    while(x){
        res = (res+query(1,1,n,dfn[top[x]],dfn[x]))%mod;
        x = fa[top[x]];
    }
    return res;
}
int ans[N];
int main(){
    n = read(); m = read();
    for(int i=2;i<=n;i++){
        fa[i] = read()+1;
        G[fa[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int l = read()+1,r = read()+1,z = read()+1;
        if(l > 1) q[++tot] = Ques{l-1,z,-1,i};
        q[++tot] = Ques{r,z,1,i};
    }
    sort(q+1,q+1+tot,cmp);
    dfs1(1); 
    dfs2(1,1);
    for(int i=1,j=1;i<=n;i++){
        update_range(i);
        while(j <= tot && q[j].x <= i){
            ans[q[j].id] += q[j].op*query_range(q[j].z);
            j++;
        }
    }
    for(int i=1;i<=m;i++) cout << (ans[i]%mod+mod)%mod << "\n";
    return 0;
}