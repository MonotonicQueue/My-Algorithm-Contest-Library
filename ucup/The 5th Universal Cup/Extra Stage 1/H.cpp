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
const int N = 5e5+10;
int n,q,p[N];
int ans[N],R[N];
vector<int> v[N];
int t[N],f[N],mn[N][20];
inline void add(int x,int y){
    while(x <= n){
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
int stk[N],top;
int get(int x,int val){
    // cout << x << " " << val << "\n";
    for(int i=19;~i;i--)
        if(mn[x][i] > val) x += (1<<i);
    return x;
}
void solve(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) p[i] = read();
    for(int i=1;i<=n;i++){
        v[i].clear(),t[i] = 0;
        for(int j=0;j<=19;j++) mn[i][j] = 0;
    }
    for(int i=1;i<=q;i++){
        int l = read(),r = read();
        R[i] = r;
        v[l].emplace_back(i);
    }
    for(int i=1;i<=n;i++) mn[i][0] = p[i];
    for(int j=1;j<=19;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            mn[i][j] = min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
    top = 0;
    for(int i=n;i;i--){
        while(top && p[stk[top]] < p[i]){
            add(stk[top],-1); add(f[stk[top]],1);
            top--;
        }
        if(!top) f[i] = n+1;
        else f[i] = get(stk[top],p[i]);
        add(i,1); add(f[i],-1);
        stk[++top] = i;
        for(int id : v[i])
            ans[id] = ask(R[id]);
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
