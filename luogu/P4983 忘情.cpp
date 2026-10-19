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
const int N = 1e5+10;
int n,m;
ll a[N],ans,f[N],sum[N];
int cnt[N],q[N];
ll Y(int x){
    return f[x]+(sum[x]-1)*(sum[x]-1);
}
ll X(int x){
    return sum[x];
}
double slope(int l,int r){
    return 1.0*(Y(r)-Y(l))/(X(r)-X(l));
}
int chk(ll mid){
    for(int i=0;i<=n;i++) cnt[i] = f[i] = 0;
    int l = 1,r = 0;
    q[++r] = 0;
    for(int i=1;i<=n;i++){
        while(l < r && slope(q[l],q[l+1]) < 2*sum[i]) l++;
        f[i] = f[q[l]]+(sum[i]-sum[q[l]]+1)*(sum[i]-sum[q[l]]+1)+mid;
        cnt[i] = cnt[q[l]]+1;
        while(l < r && slope(q[r-1],q[r]) > slope(q[r-1],i)) r--;
        q[++r] = i;
    }
    return cnt[n] <= m;
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    ll l = 0,r = 1e16,res = 0;
    ll ans = 0;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(chk(mid)) res = mid,r = mid-1;
        else l = mid+1;
    }
    chk(res);
    cout << f[n]-res*m;
    return 0;
}