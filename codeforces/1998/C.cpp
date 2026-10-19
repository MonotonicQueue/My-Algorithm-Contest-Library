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
const int N = 1e6+10;
int n,k;
struct node{
    ll a,b;
}a[N];
bool chk(ll mid){
    ll kk = k,cnt = 0;
    for(int i=n;i;i--){
        if(a[i].a >= mid){
            cnt++;
            continue;
        }
        if(a[i].a < mid)
            if(kk >= (mid-a[i].a) && a[i].b)
                kk -= mid-a[i].a,cnt++;
    }
    return cnt >= (n+2)/2;
}
void solve(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i].a = read();
    for(int i=1;i<=n;i++) a[i].b = read();
    sort(a+1,a+1+n,[](node x,node y){return x.a < y.a;});
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int mid = n/2;
        if(i <= mid) mid++;
        if(a[i].b) ans = max(ans,a[i].a+k+a[mid].a);
    }
    for(int i=n;i;i--){
        if(!a[i].b){
            swap(a[i],a[n]);
            n--;
            sort(a+1,a+n+1,[](node x,node y){return x.a < y.a;});
            ll l = 0,r = 2e9,res = 0;
            while(l <= r){
                ll mid = (l+r) >> 1;
                if(chk(mid)) l = mid+1,res = mid;
                else r = mid-1;
            }
            ans = max(ans,a[n+1].a+res);
            break;
        }
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
5 4
7 5 2 5 4
0 0 1 0 1
*/