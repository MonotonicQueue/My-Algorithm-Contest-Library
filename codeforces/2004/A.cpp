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
int n,m,a[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    if(n > 2) {
        puts("NO");
        return ;
    }
    if(n == 1){
        puts("YES");
        return ;
    }
    if(abs(a[1]-a[2]) <= 1) puts("NO");
    else puts("YES");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
