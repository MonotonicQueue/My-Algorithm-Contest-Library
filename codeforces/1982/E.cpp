#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
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
const int N = 70;
const int mod = 1e9+7;
ll n,k;
ll pw[N];
struct node{
    ll ln,rn,len;
    ll sum;
}f[N][N];
ll calc(ll x){
    if(x & 1) return x%mod*((x+1)/2%mod)%mod;
    return x/2%mod*((x+1)%mod)%mod;
}
node operator+(const node &x,const node &y){
    if(!x.len) return y;
    if(!y.len) return x;
    node res = {0,0,0,0};
    res.len = x.len+y.len;
    res.sum = (x.sum+y.sum)%mod;
    if(x.rn == x.len){
        if(y.ln == y.len) res.ln = res.rn = res.len;
        else res.ln = x.len+y.ln,res.rn = y.rn;
    }else if(y.rn == y.len){
        res.rn = y.len+x.rn;
        res.ln = x.ln;
    }else{
        res.ln = x.ln; res.rn = y.rn;
        res.sum += calc(x.rn+y.ln);
    }
    res.sum %= mod;
    return res;
}
node solve1(int d,int k){
    if(k < 0) return node{0,0,1ll<<d,0};
    if(k >= d) return node{1ll<<d,1ll<<d,1ll<<d,0};
    if(f[d][k].len) return f[d][k];
    return f[d][k] = solve1(d-1,k)+solve1(d-1,k-1);
}
ll get(node &x){
    if(x.len != x.ln) return (x.sum+calc(x.ln)+calc(x.rn))%mod;
    return calc(x.len);
}
void init(){
    pw[0] = 1;
    for(int i=1;i<=60;i++) pw[i] = pw[i-1]*2;
    for(int i=0;i<=60;i++)
        for(int j=0;j<=60;j++) f[i][j] = solve1(i,j);
}
void solve(){
    n = read(); k = read();
    node res = {0,0,0,0};
    for(int i=60;~i;i--)
        if((n >> i) & 1) res = res+solve1(i,k),k--;
    cout << get(res) << "\n";
}
int main(){
    init();
    int T = read();
    while(T--) solve();
    return 0;
}
