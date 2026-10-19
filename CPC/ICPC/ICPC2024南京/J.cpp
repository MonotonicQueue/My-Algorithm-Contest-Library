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
int k,n,m,f[N];
bool flag[N];
map<int,int> G[N];
void clear(){
    for(int i=1;i<=k;i++){
        flag[i] = false;
        f[i] = 0;
        G[i].clear();
    }
}
void solve(){
    n = read(); m = read(); k = read();
    clear();
    for(int i=1;i<=n;i++){
        int x = read();
        flag[x] = true;
    }
    int ans = 0,sum = 0;
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        sum += (flag[u] && flag[v]);
        if(u != v) G[u][v]++,G[v][u]++;
        else G[u][u]++;
    }
    for(int i=1;i<=k;i++){
        if(flag[i]) continue;
        for(auto [x,y] : G[i]) f[i] += flag[x]*y;
        if(G[i].count(i)) f[i] += G[i][i];
    }
    // for(int i=1;i<=k;i++){
    //     if(flag[i]) continue;
    //     cout << i << " " << f[i] << "\n";
    // }
    int mx = 0,smx = 0;
    for(int i=1;i<=k;i++){
        if(flag[i]) continue;
        if(f[i] > mx) smx = mx,mx = f[i];
        else if(f[i] > smx) smx = f[i];
    }
    ans = sum+mx+smx;
    // cout << sum << " " << mx << " " << smx << "\n";
    for(int i=1;i<=k;i++){
        if(flag[i]) continue;
        for(auto &[x,y] : G[i]){
            if(!flag[x] && x != i){
                ans = max(ans,sum+f[i]+f[x]+y);
            }
        }
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
4 12 7
5 7 3 6
3 6
2 2
1 4
2 4
1 3
7 6
4 1
5 4
1 1
1 1
2 1
3 7
*/