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
const int N = 1e5+10;
int n,m,k,q;
void solve(){
    n = read(); k = read(); q = read();
    vector<vector<int>> a;
    a.resize(n+1);
    a[0].resize(k+1);
    for(int i=1;i<=n;i++){
        a[i].resize(k+1);
        for(int j=1;j<=k;j++) a[i][j] = read();
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++) a[i][j] |= a[i-1][j];
    while(q--){
        int mn = 1,mx = n; m = read();
        while(m--){
            int R = read();
            char o; cin >> o;
            int c = read();
            if(o == '<'){
                int l = 1,r = n,res = 0;
                while(l <= r){
                    int mid = (l+r) >> 1;
                    if(a[mid][R] < c) res = mid,l = mid+1;
                    else r = mid-1;
                }
                mx = min(mx,res);
            }else{
                int l = 1,r = n,res = n+1;
                while(l <= r){
                    int mid = (l+r) >> 1;
                    if(a[mid][R] > c) res = mid,r = mid-1;
                    else l = mid+1;
                }
                mn = max(mn,res);
            }
        }
        if(mn <= mx) cout << mn << "\n";
        else cout << "-1\n";
    }
}
int main(){
	int T = 1;
	while(T--) solve();
    return 0;
}