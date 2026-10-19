#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int N = 510;
const int mod = 998244353;
ll fac[N],inv[N];
ll fpow(ll x,ll k){
    x %= mod;
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
void init(int n = 501){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
ll pow_mod(ll a, ll b) {
    ll ans = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
    return ans;
}
template <int a>
struct Sq { // x + y*sqrt(a) (mod 998244353)
typedef Sq<a> sq;
    ll x, y;
    Sq(ll x = 0, ll y = 0) : x(x % mod), y(y % mod) {}
    inline sq conj() const { return sq(x, -y); }
    friend inline sq operator+(const sq &l, const sq &r) { return sq(l.x + r.x, l.y + r.y); }
    friend inline sq operator-(const sq &l, const sq &r) { return sq(l.x - r.x, l.y - r.y); }
    friend inline sq operator*(const sq &l, const sq &r) { return sq(l.x * r.x + a * l.y * r.y, l.x * r.y + l.y * r.x); }
    friend inline sq operator/(const sq &l, const sq &r) { return sq(l.x * r.x - a * l.y * r.y, l.y * r.x - l.x * r.y) * pow_mod(r.x * r.x - a * r.y * r.y, mod - 2); }
    inline sq& operator+=(const sq &t) { x = (x + t.x) % mod; y = (y + t.y) % mod; return *this; }
    inline sq& operator-=(const sq &t) { x = (x - t.x) % mod; y = (y - t.y) % mod; return *this; }
    inline sq& operator*=(const sq &t) { return *this = *this * t; }
    sq operator^(ll t) const {
    sq ans = 1, x = *this;
    for (; t; t >>= 1, x *= x) if (t & 1) ans *= x;
    return ans;
    }
    inline sq sum_pow(ll t) { return (1 + this->pow(t + 1)) / (1 + *this); } // (x^(t+1)-1) / (x-1)
    inline void put() { printf("%lld+%llds%d", (x + mod) % mod, (y + mod) % mod, a); }
};
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
typedef vector<ll> poly;
poly operator*(const poly &x,const poly &y){
    poly res(x.size()+y.size()-1);
    for(int i=0;i<x.size();i++)
        for(int j=0;j<y.size();j++) add(res[i+j],x[i]*y[j]%mod);
    return res;
}
int k;
poly s;
int main(){
    init();
    int T = read(),type = read();
    while(T--){
        ll l = read(),r = read(); k = read();
        s = {0,1};
        for(int i=1;i<=k-1;i++) s = s*poly{mod-i,1};
        if(type == 2){
            l++; r++;
            Sq<5> ans = 0;
            for(int i=0;i<=k;i++){
                Sq<5> res = 0;
                for(int j=0;j<=i;j++){
                    Sq<5> A = Sq<5>(0,1)/5,B = Sq<5>(0,mod-1)/5,
                        x = Sq<5>(1,1)/2,y = Sq<5>(1,mod-1)/2;
                    A = A^j,B = B^(i-j);
                    x = x^j,y = y^(i-j);
                    x = x*y;
                    Sq<5> p = 0;
                    if(x.x != 1 || x.y != 0) p = (x^l)*((x^(r-l+1))-1)/(x-1);
                    else p = Sq<5>(r-l+1,0);
                    p = p*A*B;
                    res = res+p*C(i,j);
                }
                res = res*s[i];
                ans = (ans+res);
            }
            cout << (ans.x*inv[k]%mod+mod)%mod*fpow(r-l+1,mod-2)%mod << "\n";    
        }else{
            ll iv = fpow(r-l+1,mod-2);
            Sq<3> ans = 0;
            r /= 2; l = (l+1)/2;
            for(int i=0;i<=k;i++){
                Sq<3> res = 0;
                for(int j=0;j<=i;j++){
                    Sq<3> A = Sq<3>(3,1)/6,B = Sq<3>(3,mod-1)/6,
                        x = Sq<3>(2,1),y = Sq<3>(2,mod-1);
                    A = A^j,B = B^(i-j);
                    x = x^j,y = y^(i-j);
                    x = x*y;
                    Sq<3> p = 0;
                    if(x.x != 1 || x.y != 0) p = (x^l)*((x^(r-l+1))-1)/(x-1);
                    else p = Sq<3>(r-l+1,0);
                    p = p*A*B;
                    res = res+p*C(i,j);
                }
                res = res*s[i];
                ans = (ans+res);
            }
            cout << (ans.x*inv[k]%mod+mod)%mod*iv%mod << "\n";  
        }
    }
    
    return 0;
}