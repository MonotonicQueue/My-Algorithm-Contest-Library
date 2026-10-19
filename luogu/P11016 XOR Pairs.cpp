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
int n,q,a[N];
int t[40][40],d[40];
int main(){
    n = read(); q = read();
    auto calc = [&](int x) -> int{
        for(int i=30;~i;i--)
            if((x >> i) & 1) return i;
        return -1;
    };
    ll ans = 0;
    for(int i=1;i<=n;i++){
        a[i] = read();
        int v = calc(a[i]);
        d[v]++;
        for(int j=30;~j;j--) t[v][j] += ((a[i] >> j) & 1)^1;
        for(int j=0;j<v;j++)
            if(((a[i] >> j) & 1)^1) ans += d[j];
        for(int j=v+1;j<=30;j++) ans += t[j][v];
    }
    while(q--){
        int x = read(),y = read();
        int v = calc(a[x]);
        d[v]--;
        for(int j=30;~j;j--) t[v][j] -= ((a[x] >> j) & 1)^1;
        for(int j=0;j<v;j++)
            if(((a[x] >> j) & 1)^1) ans -= d[j];
        for(int j=v+1;j<=30;j++) ans -= t[j][v];
        a[x] = y;
        v = calc(a[x]);
        d[v]++;
        for(int j=30;~j;j--) t[v][j] += ((a[x] >> j) & 1)^1;
        for(int j=0;j<v;j++)
            if(((a[x] >> j) & 1)^1) ans += d[j];
        for(int j=v+1;j<=30;j++) ans += t[j][v];
        cout << ans << "\n";
    }
    return 0;
}