#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int n,m,a[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int ans = 0,sum = 0;
    for(int i=1;i<=n;i++){
        sum += a[i];
        ans += a[i]/2;
    }
    sum -= ans*2; m -= ans;
    ans *= 2;
    int res = ans;
    for(int i=1;i<=min(m,sum);i++)
        if(i+(m-i)*2 >= sum) res = max(res,ans+i);
    cout << res << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}