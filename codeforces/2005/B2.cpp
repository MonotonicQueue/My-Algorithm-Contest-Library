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
int n,m,a[N],q;
void solve(){
    n = read(); m = read(); q = read();
    for(int i=1;i<=m;i++) a[i] = read();
    sort(a+1,a+1+m);
    while(q--){
        int x = read();
        if(x < a[1]) cout << a[1]-1 << "\n";
        else if(x > a[m]) cout << n-a[m] << "\n";
        else{
            int v = upper_bound(a+1,a+1+m,x)-a;
            int u = v-1;
            cout << (a[v]-a[u])/2 << "\n";
        }
    }
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
