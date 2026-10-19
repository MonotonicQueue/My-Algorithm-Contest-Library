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
int n,Q,a[N],sum[N];
int main(){
    n = read(); Q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    while(Q--){
        int l = read(),r = read(),k = read();
        int len = r-l+1;
        if(k >= len) puts("-1");
        else if(k == len-1) cout << min(len-(sum[r]-sum[l-1]),abs(k-(sum[r]-sum[l-1]))) << "\n";
        else cout << abs(k-(sum[r]-sum[l-1])) << "\n";
    }
    return 0;
}