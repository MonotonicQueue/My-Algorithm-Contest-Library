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
const int N = 1010;
const int M = 65;
int n,k;
ll a[N],b[N];
struct Bas{
    ll b[M];
    bool flag;
    void init(){
        for(int i=0;i<=62;i++) b[i] = 0;
        flag = 0;
    }
    void insert(ll x){
        if(!x) return flag = 1,void();
        for(int i=60;~i;i--)
            if((x >> i) & 1){
                if(!b[i]) return b[i] = x,void();
                else x ^= b[i];
            }
    }
    bool find(ll x){
        if(!x) return flag;
        for(int i=60;~i;i--)
            if((x >> i) & 1)  x ^= b[i];
        return x == 0;
    }
};

int main(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i] = read(),b[i] = read();
    ll ans = -1;
    for(int i=29;i>=-1;i--){
        if((i >= 0) && !((k >> i) & 1)) continue;
        ll K = i >= 0 ? (((k >> i)^1) << i) : k,tmp = 0;
        int ii = max(i,0);
        for(int j=29;~j;j--){
            Bas B; B.init();
            for(int h=1;h<=n;h++){
                ll x = (((a[h] >> ii) << ii)<<30) | ((b[h] >> j) << j);
                B.insert(x);
            }
            if(B.find((K<<30)|tmp|(1<<j))) tmp |= 1<<j;
        }
        Bas B; B.init();
        for(int h=1;h<=n;h++){
            ll x = (((a[h] >> ii) << ii)<<30) | b[h];
            B.insert(x);
        }
        if(B.find((K<<30)|tmp)) ans = max(ans,tmp);
    }
    cout << ans;
    return 0;
}
