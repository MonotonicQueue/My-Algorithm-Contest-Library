#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2e5+10;
const int B = 18;
int n,mask;
int a[N],sum[N],c[N],L[N],R[N];
int stk[N],top,root;
int son[N][2],siz[N];
int vis[1<<B];
bool FLAG;
void dfs(int x){
    if(son[x][0]) dfs(son[x][0]);
    if(son[x][1]) dfs(son[x][1]);
    siz[x] = 1+siz[son[x][0]]+siz[son[x][1]];
}
void dfs1(int x,bool flag){
    if(siz[son[x][0]] < siz[son[x][1]]){
        if(son[x][0]) dfs1(son[x][0],0);
        if(son[x][1]) dfs1(son[x][1],1); 
        if(c[x] == mask){
            vis[sum[x]]++;
            for(int i=L[x]-1;i<=x-2;i++)
                if(vis[sum[i]^mask]) FLAG = true;
            vis[sum[x]]--;
            if(vis[sum[x-1]^mask]) FLAG = true;
        }
        if(!flag) for(int i=x;i<=R[x];i++) vis[sum[i]] = 0;
        else for(int i=L[x];i<=x;i++) vis[sum[i]]++;
    }else{
        if(son[x][1]) dfs1(son[x][1],0); 
        if(son[x][0]) dfs1(son[x][0],1);
        if(c[x] == mask){
            vis[sum[L[x]-1]]++;
            for(int i=x+1;i<=R[x];i++)
                if(vis[sum[i]^mask]) FLAG = true;
            vis[sum[x-1]]--;
            if(vis[sum[x]^mask]) FLAG = true;
            vis[sum[L[x]-1]]--; vis[sum[x-1]]++;
        }
        if(!flag)  for(int i=L[x];i<=x;i++) vis[sum[i]] = 0;
        else for(int i=x;i<=R[x];i++) vis[sum[i]]++;
    }
}
bool chk(){
    FLAG = false;
    for(int i=1;i<=n;i++) c[i] = a[i]&mask;
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]^c[i];
    dfs1(root,0);
    return FLAG;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) son[i][0] = son[i][1] = 0,siz[i] = 0;
    for(int i=1;i<=n;i++) a[i] = read();
    top = 0;
    for(int i=1;i<=n;i++){
        int now = top;
        while(top && a[stk[top]] < a[i]) R[stk[top]] = i-1,top--;
        son[stk[top]][1] = i;
        L[i] = stk[top]+1;
        if(now != top) son[i][0] = stk[top+1];
        stk[++top] = i;
    }
    while(top) R[stk[top--]] = n;
    root = stk[1];
    dfs(root);
    int ans = 0;
    for(int b=B-1;~b;b--){
        mask = ans|1<<b;
        if(chk()) ans = mask;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
3
3 5 2

5
*/