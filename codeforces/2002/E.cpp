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
const int N = 1e6+10;
int n,b[N];
ll a[N];
int stk[N],top;
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read(),b[i] = read();
    top = 0;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll mx = 0;
        while(top){
            if(b[i] == b[stk[top]])
                a[i] += a[stk[top--]]-mx;
            else if(a[stk[top]] <= a[i])
                mx = max(mx,a[stk[top--]]);
            else break;
        }
        stk[++top] = i;
        ans = max(ans,a[i]);
        cout << ans << " ";
    }
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
