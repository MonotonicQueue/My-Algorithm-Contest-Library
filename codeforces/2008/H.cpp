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
int n,q,a[N],cnt[N];
bool chk(int mid,int x){
    int sum = 0;
    for(int i=0;i<=n;i+=x)
        sum += cnt[min(i+mid,n)]-cnt[max(i-1,0)];
    return sum >= n/2+1;
}
int ans[N];
void solve(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++) a[i] = read(),cnt[a[i]]++;
    for(int i=1;i<=n;i++) cnt[i] += cnt[i-1];
    for(int i=1;i<=n;i++){
        int l = 0,r = i-1;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(chk(mid,i)) ans[i] = mid,r = mid-1;
            else l = mid+1;
        }
    }
    while(q--){
        int x = read();
        cout << ans[x] << " ";
    }
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
