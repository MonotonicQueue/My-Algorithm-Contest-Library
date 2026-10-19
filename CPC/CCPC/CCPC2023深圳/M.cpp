#include<bits/stdc++.h>
#define int long long
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
const int N = 510;
const int M = 2e4+10;
int n,k;
struct BigNum{
    int num[M],len;
    void init(){
        string s;
        cin >> s;
        len = s.size();
        for(int i=0;i<len;i++) num[len-i] = s[i]-'0';
        while(len > k){
            for(int i=k;i<=len;i+=k)
                for(int j=1;j<=k&&i+j<=len;j++){
                    num[j] += num[i+j];
                    num[i+j] = 0;
                }
            len = k;
            for(int i=1;i<=len;i++){
                if(num[i] >= 10){
                    num[i+1] += num[i]/10;
                    num[i] %= 10;
                    if(i == len) len++;
                }
            }
        }
        // for(int i=1;i<=len;i++) cout << num[i];
        // cout << "\n";
        for(int i=1;i<=k;i++)
            if(num[i] != 9) return ;
        for(int i=1;i<=k;i++) num[i] = 0;
        len = 1;
    }
    ll get(int mod){
        ll res = 0;
        for(int i=len;i>=1;i--) res = (res*10+num[i])%mod;
        return res;
    }
}a[N],c[2];
int mod1 = 998244353,mod2 = 1e9+7,mod3 = 1e9+9;
struct modint{
    long long x1,x2,x3;
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
    bool operator == (const modint x)const{
        return x1 == x.x1 && x2 == x.x2 && x3 == x.x3;
    }
    bool operator != (const modint x)const{
        return x1 != x.x1 || x2 != x.x2 || x3 != x.x3;
    }
}b[N],d[2];
mt19937 rnd(time(0));
ll getrnd(int l,int r){
    return rnd()%(r-l+1)+l;
}
signed main(){
    // mod1 = getrnd(5e8,1e9); mod2 = getrnd(5e8,1e9); mod3 = getrnd(5e8,1e9);
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i].init();
    c[0].len = k;
    for(int i=1;i<=k;i++) c[0].num[i] = 9;
    c[1].len = k+1;
    c[1].num[1] = 8;
    for(int i=2;i<=k;i++) c[1].num[i] = 9;
    c[1].num[k+1] = 1;
    for(int i=1;i<=n;i++)
        b[i] = modint{a[i].get(mod1),a[i].get(mod2),a[i].get(mod3)};
    // for(int i=1;i<=n;i++) cout << b[i].x1 << "\n";

    d[0] = modint{c[0].get(mod1),c[0].get(mod2),c[0].get(mod3)};
    d[1] = modint{c[1].get(mod1),c[1].get(mod2),c[1].get(mod3)};
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            for(int k=j;k<=n;k++) ans += (b[i]+b[j]+b[k] == modint{0,0,0}) || (b[i]+b[j]+b[k] == d[0]) || (b[i]+b[j]+b[k] == d[1]);
    cout << ans;
	return 0;
} 
/*

*/