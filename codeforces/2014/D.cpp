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
const int N = 1e6+10;
int n,d,k;
int sum[N],a[N];
void solve(){
    n = read(); d = read(); k = read();
    for(int i=1;i<=n;i++) sum[i] = a[i] = 0;
    for(int i=1;i<=k;i++){
        int l = read(),r = read();
        sum[l]++; sum[r+1]--;
        a[l]++;
    }
    for(int i=1;i<=n;i++) sum[i] += sum[i-1],a[i] += a[i-1];
    int mn = 1e9,pmn = 0,mx = 0,pmx = 0;
    for(int i=1;i+d-1<=n;i++){
        if(sum[i]+a[i+d-1]-a[i] < mn) mn = sum[i]+a[i+d-1]-a[i],pmn = i;
        if(sum[i]+a[i+d-1]-a[i] > mx) mx = sum[i]+a[i+d-1]-a[i],pmx = i;
    }
    cout << pmx << " " << pmn << "\n";
    // cout << mx << " " << mn << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
