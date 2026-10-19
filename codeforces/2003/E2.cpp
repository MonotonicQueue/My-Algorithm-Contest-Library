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
const int N = 5100;
const int INF = 1e9;
int n,m,nxt[N],col[N];
struct Interval{
    int l,r;
    bool operator<(const Interval &o)const{
        return l == o.l ? r < o.r : l < o.l;
    }
}a[N];
int f[N][N];
void solve(){
    n = read(); m = read();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) f[i][j] = -INF;
    f[0][0] = 0;
    for(int i=1;i<=m;i++)
        a[i].l = read(),a[i].r = read();
    sort(a+1,a+1+m);
    for(int i=1;i<=n;i++) col[i] = -1,nxt[i] = 0;
    int mnl,mnr,mxl,mxr;
    mnl = mxl = a[1].l;
    mnr = mxr = a[1].r;
    for(int i=2;i<=m+1;i++){
        if(a[i].l > mxr || i == m+1){
            if(mxl >= mnr) return puts("-1"),void();
            for(int j=mnl;j<mxl;j++) col[j] = 0;
            for(int j=mnr+1;j<=mxr;j++) col[j] = 1;
            nxt[mxl] = mnr;
            mnl = mxl = a[i].l;
            mnr = mxr = a[i].r;
        }else{
            mnl = min(mnl,a[i].l); mxl = max(mxl,a[i].l);
            mnr = min(mnr,a[i].r); mxr = max(mxr,a[i].r);
        }
    }
    // for(int i=1;i<=n;i++) cout << col[i] << " " ;
    // cout << "\n";
    // for(int i=1;i<=n;i++) cout << nxt[i] << " " ;
    // cout << "\n"; 
    for(int i=1;i<=n;i++){
        if(nxt[i]){
            for(int j=0;j<=i;j++)
                for(int k=i;k<nxt[i];k++)
                    f[nxt[i]][j+nxt[i]-k] = max(f[nxt[i]][j+nxt[i]-k],f[i-1][j]+(k-i+1)*j);
            i = nxt[i];
        }else{
            for(int j=0;j<=i;j++){
                if(col[i] != 1) f[i][j] = max(f[i][j],f[i-1][j]+j);
                if(j && col[i] != 0) f[i][j] = max(f[i][j],f[i-1][j-1]); 
            }
        }
    }
    int ans = -1;
    for(int i=0;i<=n;i++)
        ans = max(ans,f[n][i]+i*(i-1)/2+(n-i)*(n-i-1)/2);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
8 3
1 4
2 5
7 8
*/