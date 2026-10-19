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
int n,m,f[N];
vector<int> G[N];
void clear(){
    for(int i=1;i<=n;i++) G[i].clear(),f[i] = 1e9;
}
void solve(){
    n = read(); m = read();
    clear();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
    }
    string ans = "1";
    int maxn = 0;
    f[1] = 0;
    for(int st=2;st<n;st++){
        f[st-1] = min(f[st-1],f[st-2]+1);
        for(int y : G[st-1]){
            f[y] = min(f[y],f[st-1]+1);
            maxn = max(maxn,y-f[y]);
        }
        if(st < maxn) ans += "0";
        else ans += "1";
    }
    cout << ans << "\n";
    /*
    st
    i f_i < i-st
    st < i-f_i
    */
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
