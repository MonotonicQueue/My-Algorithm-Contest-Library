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
const int N = 110;
int n,a[N],b[N],c[N];
bool chk(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i] < a[j] && b[j] < b[i]) return false;
    return true;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    if(!chk()) return puts("-1"),void();
    vector<pii> ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[j] > a[i] || b[j] > b[i]){
                swap(a[i],a[j]); swap(b[i],b[j]);
                ans.push_back(mk(i,j));
            }
    cout << ans.size() << "\n";
    for(auto it : ans) cout << it.fi << " " << it.se << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
