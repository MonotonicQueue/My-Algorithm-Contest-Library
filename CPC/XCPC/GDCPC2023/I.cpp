#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define mk make_pair
#define pii pair<ll,ll>
#define ull unsigned ll
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch)) ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e6+10;
int n,m;
pii a[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int x = read();
            a[x] = mk(i,j);
        }
    set<pii> s;
    s.insert(mk(1,1)); s.insert(mk(n,m));
    for(int k=0;k<n*m;k++){
        auto it = s.upper_bound(a[k]);
//        cout << k << "\n";
        if(it == s.end()) continue;
        int nx = it->fi,ny = it->se;
        it--;
        if(a[k].fi <= nx && a[k].fi >= it->fi && a[k].se <= ny && a[k].se >= it->se) s.insert(a[k]);
        else{
            cout << k << "\n";
            return ;
        }
    }
    cout << n*m << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
1 5
1 3 0 4 2
*/