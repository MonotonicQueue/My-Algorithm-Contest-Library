#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
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
const int N = 3e5+10;
int n,a[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    ll ans = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
    for(int i=1;i<=n;i++){
        cnt3 += a[i]/3;
        cnt1 += a[i] % 3 == 1;
        cnt2 += a[i] % 3 == 2;
        a[i] %= 3;
    }
    ll tmp = min(cnt1,cnt3);
    ans += tmp; cnt1 -= tmp; cnt3 -= tmp;
    tmp = min(cnt2,cnt3/2);
    ans += tmp*2; cnt2 -= tmp; cnt3 -= 2*tmp;
    if(cnt2 && cnt3) ans+=2,cnt3--,cnt2--;
    ans += cnt2+cnt1;
    ans += cnt3/4*3; cnt3 %= 4;
    if(cnt3 == 1) ans += 2;
    else if(cnt3 == 2) ans += 2;
    else if(cnt3 == 3) ans += 3;
    cout << ans << "\n";
}
int main(){
    // freopen("card.in","r",stdin);
    // freopen("card.out","w",stdout);
    int T = read();
    while(T--) solve();
	return 0;
}
