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
const int N = 1e6+10;
int n,k;
vector<int> G[N];
int h[N],deg[N];
void topsort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        deg[i] = G[i].size(); h[i] = 1;
        if(deg[i] == 1) q.push(i);
    }
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : G[x]){
            deg[y]--;
            if(deg[y] == 1){
                q.push(y);
                h[y] = h[x]+1;
            }
        }
    }
}
bool chk(int mid){
    int cnt = 0;
    for(int i=1;i<=n;i++)
        cnt += h[i] > mid;
    if(cnt <= k) return true;
    cnt -= k;
    if(cnt > 2*mid) return false;
    for(int i=1;i<=n;i++){
        deg[i] = 0;
        if(h[i] <= mid) continue;
        for(int x : G[i])
            deg[i] += (h[x] > mid);
    }
    for(int i=1;i<=n;i++){
        if(deg[i] <= 0 || deg[i] == 2) continue;
        for(int j : G[i]){
            if(deg[j] != 2) continue;
            int x = j;
            vector<int> g;
            while(deg[x] == 2){
                deg[x] = -1; int val = 0;
                for(int y : G[x])
                    if(h[y] <= mid) val = max(val,h[y]);
                for(int y : G[x])
                    if(deg[y] == 2){
                        x = y;
                        break;
                    }
                g.push_back(val);
            }
            int m = g.size();
            if(m < cnt) continue;
            vector<int> d(m+1,0);
            for(int i=0;i<m;i++){
                /*
                对于合法区间 [l,r]，考虑每个点 i 的限制
                g_i+min(i-l,r-i) <= mid
                l < g_i+i-mid or r > mid+i-g_i
                对于包含 i 的区间，若不限制起点，其能到达最大右端点为 R = mid+i-g_i
                要使得删去区间长度 > cnt，起点位置 < R-cnt+1
                若起点位置 >= L = g_i+i-mid，对右端点无限制，只需起点到最大长度距离超过 cnt
                故只考虑 [0,m-cnt] 的起点，则对每个 i，st \in [mid+i-g_i-cnt+1,g_i+i-mid] 不合法
                */
                int l = max(mid+i-g[i]-cnt+1,0),r = min(m-cnt,g[i]+i-mid);
                if(l <= r) d[l]++,d[r+1]--;
            }
            for(int i=1;i<=m-cnt;i++) d[i] += d[i-1];
            for(int i=0;i<=m-cnt;i++)
                if(!d[i]) return true;
        }
    }
    return false;
}
void solve(){
    n = read(); k = read();
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
    for(int i=2;i<=n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    topsort();
    int l = 0,r = n,res = n;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(chk(mid)) res = mid,r = mid-1;
        else l = mid+1;
    }
    cout << res << "\n";
}
int main(){
    read(); int T = read();
    while(T--) solve();
    return 0;
}