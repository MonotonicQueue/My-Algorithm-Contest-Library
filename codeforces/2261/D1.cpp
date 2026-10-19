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
const int N = 1e6+10;
int n,a[N];
void solve(){
    n = read(); read();
    if(n == 1) return puts("0"),void();
    vector<pii> ans;
    for(int i=1;i<=(n+1)/2;i++){
        ans.emplace_back(i+1,min(i+(n+1)/2,n));
    }
    cout << ans.size() << "\n";
    for(auto &[l,r] : ans) cout << l << " " << r << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}

