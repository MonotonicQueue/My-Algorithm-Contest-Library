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
const int N = 3e5+10;
int n,Q;
ll a[N],suma[N],ssum[N];
ll sumb[N];
ll cnt[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++)
        suma[i] = suma[i-1]+a[i],
        ssum[i] = ssum[i-1]+suma[i];
    for(int i=1;i<=n;i++){
        cnt[i] = n-i+1;
        cnt[i] += cnt[i-1];
        sumb[i] = ssum[n]-ssum[i-1]-(n-i+1)*suma[i-1];
        sumb[i] += sumb[i-1];
    }
    int Q = read();
    while(Q--){
        ll L = read(),R = read();
        int l = lower_bound(cnt+1,cnt+1+n,L)-cnt,
            r = lower_bound(cnt+1,cnt+1+n,R)-cnt;
        if(l == r){
            L -= cnt[l-1]; R -= cnt[r-1];
            L += l-1; R += r-1;
            cout << ssum[R]-ssum[L-1]-(R-L+1)*suma[l-1] << "\n";
        }else{
            ll ans = 0;
            L -= cnt[l-1]; R -= cnt[r-1];
            L += l-1; R += r-1;
            ans += sumb[r-1]-sumb[l];
            ans += ssum[n]-ssum[L-1]-(n-L+1)*suma[l-1];
            ans += ssum[R]-ssum[r-1]-(R-r+1)*suma[r-1];
            cout << ans << "\n";
        }
    }
    return 0;
}
