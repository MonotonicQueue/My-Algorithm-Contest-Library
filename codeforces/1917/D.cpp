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
const int N = 4e5+10;
const int mod = 998244353;
int n,k,p[N],q[N],m;
ll t[N];
void add(int x,int y){
    while(x <= m){
        t[x] = (t[x]+y)%mod;
        x += x&(-x);
    }
}
ll ask(int x){
    ll res = 0;
    x = min(x,m);
    while(x){
        res = (res+t[x])%mod;
        x -= x&(-x);
    }
    return res;
}
int main(){
    int T = read();
    while(T--){
        n = read(); k = read();
        for(int i=1;i<=n;i++) p[i] = read();
        for(int i=1;i<=k;i++) q[i] = read()+1;
        m = max(2*n-1,k);
        auto clear = [&](){
            for(int i=1;i<=m;i++) t[i] = 0;
        };
        clear();
        ll ans = 0;
        for(int i=k;i;i--){
            ans = (ans+ask(q[i]))%mod;
            add(q[i],1);
        }
        clear();
        // cout << ans << "\n";
        ans = ans*n%mod;
        for(int i=1;i<=n;i++) add(p[i],1);
        for(int i=1;i<=n;i++){
            int x = p[i],d = 1;
            while(x < 2*n){
                int y = x*2;
                ll res = ask(y)-ask(x);
                ll l = max(0,k-d);
                ans = (ans+(l+1)*l/2%mod*res%mod)%mod;
                x = y; d++;
            }
            x = p[i]; d = 1;
            while(x > 1){
                int y = (x+1)/2;
                ll res = ask(x-1)-ask(y-1),l = min(d,k);
                ans = (ans+((l+k-1)*(k-l)/2%mod+k*l%mod)%mod*res%mod)%mod;
                x = y; d++;
            }
            add(p[i],-1);
            // cout << ans << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}
