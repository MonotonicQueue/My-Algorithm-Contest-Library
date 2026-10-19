#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 3e5+10;
int n,m,deg[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) deg[i] = 0;
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        deg[u]++; deg[v]++;
    }
    sort(deg+1,deg+1+n);
    if(deg[1] == 0) puts("Brain Melt");
    else if(deg[n] == n-1 && deg[n-2] == 1) puts("2");
    else puts("Many");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
