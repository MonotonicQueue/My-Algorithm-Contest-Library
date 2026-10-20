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
const int N = 1e4+10;
int n,m;
bool a[N][N],b[N];
void solve(){
    n = read(); m = read();
    vector<pii> ans;
    if((n-1)*n/2-m <= n-1){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++) a[i][j] = 0;
        for(int i=1;i<=m;i++){
            int u = read(),v = read();
            if(u > v) swap(u,v);
            a[u][v] = 1;
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++) if(!a[i][j]) ans.push_back(mk(i,j));
    }else{
        for(int i=1;i<=n;i++) b[i] = 0;
        for(int i=1;i<=m;i++){
            int u = read(),v = read();
            if(u > v) swap(u,v);
            if(u == 1) b[v] = 1;
        }
        for(int i=2;i<=n;i++)
            if(!b[i]) ans.push_back(mk(1,i));
    }
    cout << ans.size() << "\n";
    for(auto [u,v] : ans) cout << u << " " << v << "\n";
    
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}

