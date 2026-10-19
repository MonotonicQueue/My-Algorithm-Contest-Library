#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') ch = getchar(),r = -1;
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 4e5+10;
int n;
struct node{
    int l1,r1,l2,r2;
}a[N];
int b[N],tot;
bool chk(ll x,ll y,ll z){
    return x < (x+y+z+1)/2 && (x+y) >= (x+y+z+1)/2;
}
void solve(){
    n = read();
    tot = 0;
    for(int i=1;i<=n;i++){
        a[i].l1 = read(); a[i].r1 = read();
        a[i].l2 = read(); a[i].r2 = read();
        b[++tot] = a[i].l2; b[++tot] = a[i].r2+1;
    }
    sort(b+1,b+1+tot);
    tot = unique(b+1,b+1+tot)-b-1;
    vector<pii> v;
    ll ans = 0;
    ll L1 = 0,R1 = 0,L2 = 0,R2 = 0,L3 = 0,R3 = 0;
    for(int i=1;i<=n;i++){
        v.emplace_back(a[i].l2,i);
        v.emplace_back(a[i].r2+1,i);
        L3 += a[i].l1; R3 += a[i].r1;
    }
    sort(v.begin(),v.end());
    bool flag = false;
    for(int i=1,j=0;i<=tot;i++){
        if(flag) ans += b[i]-b[i-1];
        flag = false;
        while(j < int(v.size()) && v[j].fi <= b[i]){
            int x = v[j].se;
            if(a[x].l2 == b[i]){
                L3 -= a[x].l1; R3 -= a[x].r1;
                L2 += a[x].l1; R2 += a[x].r1;
            }else{
                L2 -= a[x].l1; R2 -= a[x].r1;
                L1 += a[x].l1; R1 += a[x].r1;
            }
            j++;
        }
        ll l = L1,r = R1;
        while(l < r){
            ll mid = (l+r) >> 1;
            if(mid-R2-1 >= R3) r = mid;
            else if(mid+R2-1 < L3) l = mid+1;
            else{
                l = r = mid;
                break;
            }
        }
        for(ll p=max(l-5,L1);p<=min(l+5,R1);p++){
            ll x = p-R2;
            x = max(x,L3), x = min(x,R3);
            for(int i=-2;i<=2;i++){
                if(L3 <= x+i && x+i <= R3){
                    flag |= chk(p,R2,x+i);
                }
            }
        }
        for(ll p=max(l-5,L1);p<=min(l+5,R1);p++){
            ll x = p+R2;
            x = max(x,L3), x = min(x,R3);
            for(int i=-2;i<=2;i++){
                if(L3 <= x+i && x+i <= R3){
                    flag |= chk(p,R2,x+i);
                }
            }
        }
    }
    cout << ans << "\n";
}
int main(){
    int c = read(),T = read();
    while(T--) solve();
    return 0;
}