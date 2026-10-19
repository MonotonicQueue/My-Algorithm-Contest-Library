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
const int N = 2e5+10;
int n,a[N],x;
ll sum[N],f[N];
int main(){
    int T = read();
    while(T--){
        n = read(); x = read();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
        for(int i=1;i<=n+2;i++) f[i] = 0;
        for(int i=n;i;i--){
            int l = i,r = n,rs = l-1;
            while(l <= r){
                int mid = (l+r)>>1;
                if(sum[mid]-sum[i-1] <= x) l = mid+1,rs = mid;
                else r = mid-1;
            }
            // cout << rs << "\n";
            f[i] = (rs-i+1)+f[rs+2];
        }
        ll ans = 0;
        for(int i=1;i<=n;i++) ans += f[i];
        cout << ans << "\n";
    }
	return 0;
}
