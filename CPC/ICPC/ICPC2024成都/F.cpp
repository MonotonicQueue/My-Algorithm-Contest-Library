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
const int N = 2e5+10;
int n,m,g[N];
ll a[N],sum[N];
double f[N];
struct node{
    int l,r,id;
}t[N];
void solve(double k){
    int l = 1,r = 0;
    t[++r] = node{1,n,0};
    auto calc = [&](int x,int y){
        assert(x <= y);
        return f[x]+sqrt((y-x)*(sum[y]-sum[x]));
    };
    for(int i=1;i<=n;i++){
        g[i] = g[t[l].id]+1; f[i] = calc(t[l].id,i)+k;
        if(i == n) break;
        if(t[l].l == t[l].r) l++;
        else t[l].l = i+1;
        while(l <= r && calc(i,t[r].l) <= calc(t[r].id,t[r].l)) r--;
        if(l <= r){
            int L = t[r].l,R = n,res = n+1;
            while(L <= R){
                int mid = (L+R) >> 1;
                if(calc(i,mid) <= calc(t[r].id,mid)) res = mid,R = mid-1;
                else L = mid+1;
            }
            t[r].r = res-1;
            if(res <= n) t[++r] = node{res,n,i};
        }else t[++r] = node{i+1,n,i};
    }
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    double l = 0,r = 1e8;
    int T = 50;
    while(T--){
        double mid = (l+r)/2;
        solve(mid);
        if(g[n] >= m) l = mid;
        else r = mid;
    }
    solve(l);
    printf("%.13lf",f[n]-l*m);
    return 0;
}
