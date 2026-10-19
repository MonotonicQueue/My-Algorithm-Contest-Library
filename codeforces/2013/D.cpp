#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pli pair<ll,int>
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
int n,top; ll a[N];
pli stk[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    top = 0;
    for(int i=1;i<=n;i++){
        ll sum = a[i],cnt = 1;
        while(top && stk[top].fi >= sum/cnt){
            sum += stk[top].fi*stk[top].se;
            cnt += stk[top].se;
            top--;
        }
        stk[++top] = mk(sum/cnt,cnt-sum%cnt);
        if(sum%cnt != 0) stk[++top] = mk(sum/cnt+1,sum%cnt);
    }
    cout << stk[top].fi-stk[1].fi << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
