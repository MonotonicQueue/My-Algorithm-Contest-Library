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
int n,q,a[N],num[N];
void solve(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int ans = 0;
    for(int i=1;i<=n;i++)
        if(num[a[i]] % 2 == 0) ans++;
    cout << ans << " ";
    while(q--){
        int i = read(),x = read();
        if(num[a[i]] % 2 == 0) ans--;
        a[i] = x;
        if(num[a[i]] % 2 == 0) ans++;
        cout << ans << " ";
    }
    cout << "\n";
}
int main(){
    for(int i=0;i<16;i++)
        for(int k=0;k<4;k++) num[i] += (i >> k)&1;
    int T = read();
    while(T--) solve();
    return 0;
}

