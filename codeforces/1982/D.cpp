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
const int N = 510;
int n,m,k,a[N][N];
char b[N][N];
int s[N][N];
void solve(){
    n = read(); m = read(); k = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j] = read();
    for(int i=1;i<=n;i++) scanf("%s",b[i]+1);

    ll sum = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(b[i][j] == '0') sum += a[i][j],s[i][j] = -1;
            else               sum -= a[i][j],s[i][j] = 1;
            s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    auto ask = [&](int l,int L,int r,int R){
        return abs(s[L][R]-s[L][r-1]-s[l-1][R]+s[l-1][r-1]);
    };
    int d = 0;
    for(int i=k;i<=n;i++)
        for(int j=k;j<=m;j++)
            d = __gcd(d,ask(i-k+1,i,j-k+1,j));
    if(!d) puts(sum ? "NO" : "YES");
    else if(sum % d) puts("NO");
    else puts("YES");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
