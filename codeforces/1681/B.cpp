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
int n,a[N],m,b[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    m = read();
    ll sum = 0;
    for(int i=1;i<=m;i++) b[i] = read(),sum += b[i];
    sum = sum%n+1;
    cout << a[sum] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
