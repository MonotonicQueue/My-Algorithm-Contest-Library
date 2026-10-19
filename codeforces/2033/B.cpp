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
const int N = 510;
int n;
ll a[N][N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) a[i][j] = read();
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll mn = 1e9;
        int x = 1,y = i;
        while(x <= n && y <= n){
            mn = min(mn,a[x][y]);
            x++; y++;
        }
        if(mn < 0) ans += -mn;
        if(i == 1) continue;
        mn = 1e9;
        x = i,y = 1;
        while(x <= n && y <= n){
            mn = min(mn,a[x][y]);
            x++; y++;
        }
        if(mn < 0) ans += -mn;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}
