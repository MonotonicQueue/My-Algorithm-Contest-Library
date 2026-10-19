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
int n,a[N];
int cnt[32];
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++)
        for(int j=0;j<20;j++)
            if((a[i] >> j) & 1) cnt[j]++;
    ll ans = 0;
    while(true){
        ll x = 0;
        for(int i=0;i<20;i++)
            if(cnt[i]) x += 1<<i,cnt[i]--;
        if(!x) break;
        ans += x*x;
    }
    cout << ans;
    return 0;
}