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
const int N = 3100;
int n,k,t[N];
ll a[N][N],f[N],ans,tmp[N][N];
void solve(int l,int r,int d){
//    cout << l << " " << r << " " << d << "\n";
    if(l == r){
        for(int i=0;i<=min(t[l],k);i++)
            ans = max(ans,f[k-i]+a[l][i]);
        return ;
    }
    int mid = (l+r)>>1;
    for(int i=0;i<=k;i++) tmp[d][i] = f[i];
    for(int i=l;i<=mid;i++)
        for(int j=k;j>=t[i];j--) f[j] = max(f[j],f[j-t[i]]+a[i][t[i]]);
    solve(mid+1,r,d+1);
    for(int i=0;i<=k;i++) f[i] = tmp[d][i];
    for(int i=mid+1;i<=r;i++)
        for(int j=k;j>=t[i];j--) f[j] = max(f[j],f[j-t[i]]+a[i][t[i]]);
    solve(l,mid,d+1);
    for(int i=0;i<=k;i++) f[i] = tmp[d][i];
}
int main(){
    n = read(); k = read();
    for(int i=1;i<=n;i++){
        t[i] = read();
        for(int j=1;j<=t[i];j++)
            if(j <= k) a[i][j] = a[i][j-1]+read();
            else read();
    }
    solve(1,n,0);
    cout << ans;
	return 0;
}
