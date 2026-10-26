#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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
// const int 
ull r,k;
double p;
double calc(ull s,ull x){
    // cout << s << " " << x << "\n";
    if(s == 1) return (x == 1);
    if(x <= s/2) return p*calc(s/2,x);
    return p+(1-p)*calc(s/2,x-s/2);
}
void solve(){
    cin >> r >> k >> p;
    if(p < 0.5) p = 1-p,k = (1ull<<r)-k+1;
    ull x = k-1;
    double ans = 1;
    for(int i=r-1;~i;i--){
        ull q = min(x,(1ull<<i));
        x -= q;
        double t = calc((1ull<<i),q);
        ans *= (1-p)*t+p*(1-t);
    }
    printf("%.6f\n",ans);
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
