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
const int mod = 998244353;
int n,m,ans=1;
int main(){
    n = read();
    for(int i=1;i<=n;i++) m += read();
    for(int i=1;i<=m;i++) ans = (1ll*ans*(i == m-n+1 ? 1 : i))%mod;
    cout << ans;
    return 0;
}
