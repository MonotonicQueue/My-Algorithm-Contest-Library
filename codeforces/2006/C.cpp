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
int n,m,a[N];
bool chk(int l,int r){
    vector<int> v;
    for(int i=l;i<=r;i++) v.push_back(a[i]);
    // sort(v.begin(),v.end());
    int d = 0;
    for(int i=1;i<v.size();i++){
        d = __gcd(d,abs(v[i]-v[i-1]));
    }
    if(!d) return true;
    for(int i=0;i<=30;i++)
        if(d == (1 << i)) return true;
    return false;
}
struct node{
    int l,r,v;
};
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    vector<node> V;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int x = abs(a[i]-a[i-1]);
        while(x && x % 2 == 0) x /= 2;
        for(node &y : V) y.v = __gcd(y.v,x);
        V.push_back(node{i,i,0});
        vector<node> now;
        for(node y : V){
            if(now.empty() || now.back().v != y.v) now.push_back(y);
            else now.back().r = y.r;
        }
        V = now;
        for(node y : V)
            if(y.v <= 1) ans += y.r-y.l+1;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
