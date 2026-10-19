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
const int N = 3e5+10;
const ll inf = 2e18;
int n,a[N];
vector<int> G[N];
ll f[N],g[N],s;
priority_queue<pii> q[N];
void calc(int st){
    q[st].push(mk(0,st));
    ll now = 0;
    while(!q[st].empty()){
        int x = q[st].top().se; q[st].pop();
        if(f[x] == inf){
            break;
        }
        if(now < f[x]){
            f[st] += f[x]-now;
            now = f[x];
        }
        if(x == st){
            now += a[x];
            for(int y : G[x])
                q[x].push(mk(-f[y],y));
        }else{
            now += g[x];
            if(q[x].size() > q[st].size()) swap(q[st],q[x]);
            while(!q[x].empty()) q[st].push(q[x].top()),q[x].pop();
        }
        if(now > f[st]){
            g[st] = now-f[st];
            return ;
        }
    }
    f[st] = inf;
}
void dfs(int x){
    for(int y : G[x]) dfs(y);
    calc(x);
}
void work(){
    priority_queue<pii> Q;
    Q.push(mk(-f[0],0));
    ll now = s;
    while(!Q.empty()){
        int x = Q.top().se; Q.pop();
        if(f[x] > now) break;
        now += a[x];
        for(int y : G[x]) Q.push(mk(-f[y],y));
    }
    cout << now-s;
}
int main(){
    n = read(); s = read();
    for(int i=1;i<=n;i++){
        a[i] = read();
        int x = read();
        G[x].push_back(i);
    }
    dfs(0);
    work();
    return 0;
}
