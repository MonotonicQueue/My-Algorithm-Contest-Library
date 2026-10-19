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
const int N = 6e5+10;
int n;
int v[N];
vector<int> G[N];
int t[N*22][2],cnt,sum[N*22],rt[N],val[N*22];
void insert(int p,int x,int d){
    if(d == 21) return ;
    int c = x & 1;
    if(!t[p][c]) t[p][c] = ++cnt;
    sum[t[p][c]]++;
    insert(t[p][c],x>>1,d+1);
    val[p] = ((val[t[p][0]]^val[t[p][1]])<<1)^(sum[t[p][1]] & 1);
}
int merge(int x,int y){
    if(!x || !y) return x+y;
    val[x] ^= val[y];
    sum[x] += sum[y];
    t[x][0] = merge(t[x][0],t[y][0]);
    t[x][1] = merge(t[x][1],t[y][1]);
    return x;
}
void add(int p){
    if(!p) return ;
    swap(t[p][0],t[p][1]);
    add(t[p][0]);
    val[p] = ((val[t[p][0]]^val[t[p][1]])<<1)^(sum[t[p][1]] & 1);
}
ll ans;
void dfs(int x){
    for(int y : G[x]){
        dfs(y);
        rt[x] = merge(rt[x],rt[y]);
    }
    if(!rt[x]) rt[x] = ++cnt;
    add(rt[x]);
    insert(rt[x],v[x],0);
    ans += val[rt[x]];
}
int main(){
    n = read();
    for(int i=1;i<=n;i++) v[i] = read();
    for(int i=2;i<=n;i++){
        int x = read();
        G[x].push_back(i);
    }
    dfs(1);
    cout << ans;
    return 0;
}