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
const int M = 1e7;
const int mod1 = 998244353,mod2 = 1e9+7,mod3 = 1e9+9;
const long double s5 = sqrt(5),pi = (1+s5)/2.0;
const long double lgs = log10l(1/s5),lgp = log10l(pi);
int n;
string s[N];
struct modint{
    ll x1,x2,x3;
    modint operator+(const int &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1+x < mod1 ? res.x1+x : res.x1+x-mod1;
        res.x2 = res.x2+x < mod2 ? res.x2+x : res.x2+x-mod2;
        res.x3 = res.x3+x < mod3 ? res.x3+x : res.x3+x-mod3;
        return res;
    }
    modint operator-(const int &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1-x > 0 ? res.x1-x : res.x1-x+mod1;
        res.x2 = res.x2-x > 0 ? res.x2-x : res.x2-x+mod2;
        res.x3 = res.x3-x > 0 ? res.x3-x : res.x3-x+mod3;
        return res;
    }
    modint operator*(const int &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1*x%mod1;
        res.x2 = res.x2*x%mod2;
        res.x3 = res.x3*x%mod3;
        return res;
    }
    modint operator+(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1+x.x1 < mod1 ? res.x1+x.x1 : res.x1+x.x1-mod1;
        res.x2 = res.x2+x.x2 < mod2 ? res.x2+x.x2 : res.x2+x.x2-mod2;
        res.x3 = res.x3+x.x3 < mod3 ? res.x3+x.x3 : res.x3+x.x3-mod3;
        return res;
    }
    modint operator-(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1-x.x1 > 0 ? res.x1-x.x1 : res.x1-x.x1+mod1;
        res.x2 = res.x2-x.x2 > 0 ? res.x2-x.x2 : res.x2-x.x2+mod2;
        res.x3 = res.x3-x.x3 > 0 ? res.x3-x.x3 : res.x3-x.x3+mod3;
        return res;
    }
    modint operator*(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1*x.x1%mod1;
        res.x2 = res.x2*x.x2%mod2;
        res.x3 = res.x3*x.x3%mod3;
        return res;
    }
    bool operator<(const modint x)const{
        if(x1 != x.x1) return x1 < x.x1;
        if(x2 != x.x2) return x2 < x.x2;
        return x3 < x.x3;
    }
}a[N],F[M+10];
bool cmp(string &a,string &b){
    return a.size() != b.size() ? a.size() < b.size() : a < b;
}
modint change(string &t){
    modint res = {0,0,0};
    for(int i=0;i<t.size();i++)
        res = res*10+t[i]-'0';
    return res;
}
ll f[N];
long double ff[M+10];
map<modint,int> mp;
int main(){
    F[1] = {1,1,1};
    for(int i=2;i<=M;i++){
        F[i] = F[i-1]+F[i-2];
    }
    f[1] = 1;
    for(int i=2;i<=80;i++){
        f[i] = f[i-1]+f[i-2];
        ff[i] = log10l(f[i]);
    }
    for(int i=81;i<=M;i++) ff[i] = lgs+i*lgp;
    n = read();
    for(int i=1;i<=n;i++) cin >> s[i];
    sort(s+1,s+1+n,cmp);
    ll ans = 0;
    for(int i=1,j=2;i<=n;i++){
        a[i] = change(s[i]);
        int len = s[i].size();
        long double pp = len;
        while(ff[j] < pp) j++;
        for(int k=max(j-5,2);k<=j+5;k++){
            ans += mp[F[k]-a[i]];
        }
        mp[a[i]]++;
    }
    cout << ans;
    return 0;
}
