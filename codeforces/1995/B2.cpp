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
ll n,m;
struct node{
    ll x,c;
}a[N];
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        for(int i=1;i<=n;i++) a[i].x = read();
        for(int i=1;i<=n;i++) a[i].c = read();
        auto cmp = [&](node x,node y){
            return x.x < y.x;
        };
        sort(a+1,a+1+n,cmp);
        ll ans = 0;
        for(int i=1;i<=n;i++) ans = max(ans,min(m/a[i].x,a[i].c)*a[i].x);
        for(int i=1;i<n;i++){
            if(a[i].x == a[i+1].x-1){
                ll k = m/a[i].x,x = m-k*a[i].x;
                ll kk = min(x,min(k,a[i+1].c));
                if(k-kk <= a[i].c){
                    ans = max(ans,(k-kk)*a[i].x+kk*a[i+1].x);
                }else{
                    x = m-a[i].c*a[i].x; k = min(x/a[i+1].x,a[i+1].c);
                    ll s = m-a[i].x*a[i].c-k*a[i+1].x;
                    ll d = min(a[i+1].c-k,min(s,a[i].c));
                    ans = max(ans,(a[i].c-d)*a[i].x+(d+k)*a[i+1].x);
                }
            }
        }
        cout << ans << "\n";
    }
	return 0;
}

/*
1
2 10000000000
11 12
87312315 753297050
*/