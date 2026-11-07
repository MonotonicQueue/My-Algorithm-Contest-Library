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
const int N = 2e5+10;
int n,L[N],R[N];
ll k,f[N],ans;
void solve(){
    n = read(); k = read();
    ans = 0;
    for(int i=1;i<=n;i++) f[i] = 0;
    f[1] = k;
    for(int i=1;i<n;i++){
        L[i] = read(),R[i] = read();
        ans += f[i];
        f[R[i]] += (f[i]+1)/2;
        f[L[i]] += f[i]/2;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
