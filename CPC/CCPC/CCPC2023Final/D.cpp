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
const int N = 1e5+10;
int n,m,a[N],b[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=m;i++) b[i] = read();
    int i,j;
    for(i=1,j=1;i<=n&&j<=m;i++)
        if(a[i] == b[j]) j++;
    puts(j == m+1 ? "Yes" : "No");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
