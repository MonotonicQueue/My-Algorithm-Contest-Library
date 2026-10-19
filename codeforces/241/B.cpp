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
const int N = 5e4+10;
const int mod = 1e9+7;
int n; ll m;
int a[N];
int t[N*32][2],siz[N*32][2],cnt=1;
void insert(int x,int y){
    int p = 1;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1;
        if(!t[p][c]) t[p][c] = ++cnt;
        p = t[p][c]; siz[p][0] += y;
    }
}
void insert2(int x,int y,int k){
    int p = 1;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1;
        if(!t[p][c]) t[p][c] = ++cnt;
        p = t[p][c]; siz[p][(x >> k) & 1] += y;
    }
}
ll ask(int x,int y){
    ll res = 0; int p = 1;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1,d = (y >> i) & 1;
        if(!d){
            res += siz[t[p][c^1]][0];
            p = t[p][c];
        }else p = t[p][c^1];
    }
    return res;
}
ll ask2(int x,int y,int k){
    ll res = 0; int p = 1;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1,d = (y >> i) & 1;
        if(!d){
            res += siz[t[p][c^1]][k];
            p = t[p][c];
        }else p = t[p][c^1];
    }
    return res;
}
ll chk(int x){
    ll k = 0;
    for(int i=1;i<=n;i++){
        k += ask(a[i],x);
        insert(a[i],1);
    }
    for(int i=1;i<=n;i++) insert(a[i],-1);
    return k;
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    ll l = 0,r = 2e9,res = 0;
    while(l <= r){
        ll mid = (l+r)>>1;
        if(chk(mid) <= m) r = mid-1,res = mid;
        else l = mid+1;
    }
    // cout << res << "\n";
    ll ans = (m-chk(res))*res%mod;
    for(int i=0;i<=30;i++){
        ll k = 0;
        for(int j=1;j<=n;j++){
            k += ask2(a[j],res,((a[j] >> i) & 1)^1);
            insert2(a[j],1,i);
        }
        for(int j=1;j<=n;j++) insert2(a[j],-1,i);
        k %= mod;
        ans = (ans+k*(1ll<<i))%mod;
    }
    cout << ans;
	return 0;
}
