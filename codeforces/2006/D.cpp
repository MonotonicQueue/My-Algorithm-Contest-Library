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
int n,k,q,a[N],l[N],r[N];
int sum1[N],sum2[N],ans[N];
void solve(){
    n = read(); q = read(); k = read();
    for(int i=1;i<=q;i++) ans[i] = 0;
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=q;i++) l[i] = read(),r[i] = read();
    int B = sqrt(k);
    for(int i=1;i<=B;i++){
        for(int j=1;j<=n;j++){
            sum1[j] = sum1[j-1]+(a[j] <= i);
            sum2[j] = sum2[j-1]+(a[j] > k/(i+1));
        }
        for(int j=1;j<=q;j++){
            int len = r[j]-l[j]+1,cnt1 = sum1[r[j]]-sum1[l[j]-1],cnt2 = sum2[r[j]]-sum2[l[j]-1];
            ans[j] = max(ans[j],min(len/2-cnt1,(cnt2-cnt1+1)/2));
        }
    }
    for(int i=1;i<=q;i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
