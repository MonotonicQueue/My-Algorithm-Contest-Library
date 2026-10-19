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
const int N = 5e5+10;
const int mod = 1e9+7;
int n,l[N],r[N];
ll a[N],R[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i] = read(); R[i] = read();
        l[i] = r[i] = i;
    }
    for(int i=1;i<=n;i++){
        while(l[i] > 1 && a[i]-a[l[i]-1] <= R[i]){
            R[i] = max(R[i],R[l[i]-1]-(a[i]-a[l[i]-1]));
            l[i] = l[l[i]-1];
        }
    }
    for(int i=n;i;i--)
        while(r[i] < n && a[r[i]+1]-a[i] <= R[i]){
            l[i] = min(l[i],l[r[i]+1]);
            r[i] = r[r[i]+1];
        }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans = (ans+1ll*i*(r[i]-l[i]+1))%mod;
    cout << ans;
    return 0;
}
