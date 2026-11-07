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
const int N = 1e5+10;
int n,m,ans;
int deg1[N],deg2[N],cnt1[N],cnt2[N];
int fa[N];
vector<int> G[N],E[N],V[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void topsort1(int *deg,int *cnt){
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!deg[i]) q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        cnt[x]++; deg[x] = E[x].size();
        ans++;
        // if(ans > 100*n) return ;
        for(int y : E[x]){
            if(--deg[y] == 0){
                q.push(y);
            }
        }
    }
}

void solve(){
    n = read(); m = read(); ans = 0;
    for(int i=1;i<=n;i++){
        fa[i] = i;
        G[i].clear(),deg1[i] = 0;
        E[i].clear(),deg2[i] = 0;
        cnt1[i] = cnt2[i] = 0;
        V[i].clear();
    }
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        fa[get(u)] = get(v);
        G[u].push_back(v);
        E[v].push_back(u);
        deg1[v]++; deg2[v]++;
    }
    for(int i=1;i<=n;i++){
        V[get(i)].push_back(i);
    }
    vector<int> z;
    for(int i=1;i<=n;i++){
        if(fa[i] != i) continue;
        queue<int> q;
        for(int x : V[i])
            if(!deg1[x]) q.push(x);
        int num = 0;
        while(!q.empty()){
            int x = q.front(); q.pop();
            cnt1[x]++; num++;
            for(int y : G[x]){
                if(--deg1[y] == 0){
                    q.push(y);
                }
            }
        }
        if(num == V[i].size()) return puts("-1"),void();
        for(int x : V[i])
            if(deg1[x]) z.push_back(x);
    }
    for(int i=1;i<=n;i++) cnt2[i] = 1e9;
    deque<int> q;
    for(int x : z) cnt2[x] = 0,q.push_back(x);
    while(!q.empty()){
        int x = q.front(); q.pop_front();
        // cout << x << "\n";
        for(int y : G[x]){
            if(cnt2[y] > cnt2[x]){
                cnt2[y] = cnt2[x];
                q.push_front(y);
            }
        }
        for(int y : E[x]){
            if(cnt2[y] > cnt2[x]+1){
                cnt2[y] = cnt2[x]+1;
                q.push_back(y);
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
        if(cnt2[i] > 100*n) return puts("-1"),void();
        else ans += cnt2[i];
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
