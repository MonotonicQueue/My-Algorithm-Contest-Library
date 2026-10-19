#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
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
int n,p[N],siz[N];
vector<int> G[N],c;
ll res;
template<int len = 1>
void solve(int n){
    if(n >= len){
        solve<min(len*2,N)>(n);
        return ;
    }
    bitset<len> b;
    b[0] = 1;
    for(int y : c)
        b |= b << y;
    res = 0;
    for(int i=0;i<=n;i++)
        if(b[i]) res = max(res,1ll*i*(n-1-i));
}
ll calc(int x){
    vector<int> v;
    for(int y : G[x]) v.push_back(siz[y]);
    if(v.empty()) return 0;
    sort(all(v));
    if(v.back() > siz[x]/2) return 1ll*v.back()*(siz[x]-1-v.back());
    int m = v.size(),cnt = 1;
    v.push_back(0);
    c.clear();
    for(int i=1;i<=m;i++){
        if(v[i] != v[i-1]){
            for(int j=0;j<=20;j++)
                if(cnt >= (1<<j)) c.push_back((1<<j)*v[i-1]),cnt -= (1<<j);
            if(cnt) c.push_back(cnt*v[i-1]);
            cnt = 1;
        }else cnt++;
    }
    solve(siz[x]);
    return res;
}
ll ans;
void dfs(int x){
    siz[x] = 1;
    for(int y : G[x]){
        dfs(y);
        siz[x] += siz[y];
    }
    ans += calc(x);
}
int main(){
    n = read();
    for(int i=2;i<=n;i++){
        p[i] = read();
        G[p[i]].push_back(i);
    }
    dfs(1);
    cout << ans ;
    return 0;
}
