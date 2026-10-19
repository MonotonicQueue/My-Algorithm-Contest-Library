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
const int M = 1e7+10;
const int mod = 1e9+7;
int n,m,a[N];
ll pw[M],b[N],sum[N];
pair<ll,ll> s[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    ll ans = a[1];
    cout << a[1] << " ";
    for(int i=1;i<=n;i++){
        b[i] = 0;
        while(a[i] % 2 == 0) a[i] /= 2,b[i]++;
        sum[i] = a[i];
    }
    int top = 0;
    s[++top] = mk(a[1],b[1]);
    for(int i=2;i<=n;i++){
        while(top && (b[i] >= 30 || a[i]*pw[b[i]] >= s[top].fi)){
            ans = (ans-s[top].fi*pw[s[top].se]%mod+mod)%mod;
            b[i] += s[top].se;
            ans = (ans+s[top].fi)%mod;
            top--;
        }
        ans = (ans+a[i]*pw[b[i]])%mod;
        cout << ans << " ";
        s[++top] = mk(a[i],b[i]);
    }
    cout << "\n";
}
int main(){
    pw[0] = 1;
    for(int i=1;i<=M-10;i++) pw[i] = pw[i-1]*2%mod;
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}
