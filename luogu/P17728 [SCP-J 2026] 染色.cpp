#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2e5+10;
int n,a[N],mn;
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int ans = a[n]-a[1];
    mn = 1e9;
    for(int i=2;i<n;i++){
        ans = max(ans,a[n]-a[1]+a[i]-mn);
        mn = min(mn,a[i]);
    }
    for(int i=2;i<=n;i++)
        ans = max(ans,a[n]-a[i]+a[i-1]-a[1]);
    cout << ans << "\n";
    return 0;
}
