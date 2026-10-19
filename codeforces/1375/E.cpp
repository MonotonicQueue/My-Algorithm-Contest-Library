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
const int N = 1e3+10;
int n,m,a[N],b[N],pos[N],c[N];
vector<pii> ans;
void work(int x,int y){
    ans.push_back(mk(y,x));
    swap(a[x],a[y]);
    pos[a[x]] = x;
    pos[a[y]] = y;
}
void solve(){
    n = m = read(); 
    for(int i=1;i<=n;i++) a[i] = b[i] = read();
    sort(b+1,b+1+m);
    m = unique(b+1,b+1+m)-b-1;
    int tot = 0;
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++) if(a[i] == b[j]) c[i] = ++tot;
    for(int i=1;i<=n;i++) a[i] = c[i];
    for(int i=1;i<=n;i++) pos[a[i]] = i;
    ans.clear();
    for(int i=n;i;i--)
        for(int j=a[i]+1;j<=i;j++)
            work(pos[j-1],pos[j]);
    cout << ans.size() << "\n";
    for(pii x : ans) cout << x.fi << " " << x.se << "\n";
}
int main(){
    int T = 1;
    while(T--) solve();
    return 0;
}
