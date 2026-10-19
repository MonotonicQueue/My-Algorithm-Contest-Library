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
const int N = 4e5+10;
int n,m,Q;
struct Edge{int u,v;}e[N];
int fa[N],sz[N],ans[N];
int get(int x){
    return fa[x] == x ? x : get(fa[x]);
}
struct node{int u,v,ti;};
stack<node>st; int ti;
void merge(int x,int y){
    x = get(x); y = get(y);
    if(x == y) return ;
    if(sz[x] > sz[y]) swap(x,y);
    fa[x] = y;
    sz[y] += sz[x];
    st.emplace(node{x,y,ti});
}
bool chk(int x,int y){
    ti++;
    if(get(x) == get(y)) return false;
    merge(x,y+n); merge(x+n,y);
    return true; 
}
inline void undo(){
    while(!st.empty() && st.top().ti == ti){
        int x = st.top().u,y = st.top().v;
        fa[x] = x; sz[y] -= sz[x];
        st.pop();
    }
    ti--;
}

void solve(int l,int r,int L,int R){
    if(L == R){
        for(int i=l;i<=r;i++) ans[i] = L;
        return ;
    }
    if(l > r || L > R) return ;
    int i,mid = (l+r)>>1;
    for(i=mid;i<=R;i++){
        if(i == r+1) i = max(i,L);
        if(!chk(e[i].u,e[i].v)) break;
    }
    ans[mid] = i;
    for(;i>=L&&i>=mid;i--) undo();
    solve(l,mid-1,L,ans[mid]);
    for(i=mid;i<=r&&i<L;i++) undo();
    for(i=max(r+1,L);i<ans[mid];i++) chk(e[i].u,e[i].v);
    solve(mid+1,r,ans[mid],R);
    for(i=max(r+1,L);i<ans[mid];i++) undo();
}
int main(){
    n = read(); m = read(); Q = read();
    for(int i=1;i<=m;i++)
        e[i].u = read(),e[i].v = read();
    for(int i=1;i<=m;i++) e[i+m] = e[i];
    for(int i=1;i<=2*n;i++) fa[i] = i,sz[i] = 1;
    e[2*m+1] = Edge{1,1};
    solve(1,m+1,1,2*m+1);
    while(Q--){
        int l = read(),r = read();
        puts(ans[r+1] <= m+l-1 ? "YES" : "NO");
    }
	return 0;
}
