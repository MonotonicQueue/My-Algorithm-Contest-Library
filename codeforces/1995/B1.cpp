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
ll n,m,a[N];
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        for(int i=1;i<=n;i++) a[i] = read();
        sort(a+1,a+1+n);
        ll ans = 0,sum = 0;
        for(int l=1,r=0;l<=n;){
            if(a[l] > m) break;
            if(r <= l) r = l,sum = 0;
            while(a[r]-a[l] <= 1 && r <= n && sum+a[r] <= m) sum += a[r],r++;
            ans = max(sum,ans);
            sum -= a[l]; l++;
        }
        cout << ans << "\n";
    }
	return 0;
}