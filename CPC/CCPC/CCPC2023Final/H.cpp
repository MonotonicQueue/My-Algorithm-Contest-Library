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
const int N = 2e6+10;
int n,a[N],cnt[N];
void solve(){
    n = read();
    for(int i=1;i<=2*n;i++) a[i] = read();
    for(int i=1;i<=2*n;i++) cnt[a[i]] = 0;
    for(int i=1;i<=2*n;i++) cnt[a[i]]++;
    int sum = 0;
    for(int i=1;i<=2*n;i++)
        if(cnt[a[i]]) sum += cnt[a[i]]-1,cnt[a[i]] = 0;
    if(sum >= n) puts("Qingyu");
    else puts("Kevin");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
