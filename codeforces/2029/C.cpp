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
const int N = 3e5+10;
int n,a[N];
int f[N];
bool chk(int mid){
    f[n+1] = mid;
    for(int i=n;i;i--){
        if(a[i] >= mid) f[i] = mid-1,mid--;
        else if(a[i] < mid) f[i] = mid+1,mid++;
    }
    for(int i=n;i;i--) f[i] = min(f[i],f[i+1]);
    int now = 0;
    for(int i=0;i<n;i++){
        if(a[i] > now) now++;
        if(a[i] < now) now--;
        if(now >= f[i+2]) return true;
    }
    return false;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int l = 0,r = n,res = 0;
    // chk(4);
    while(l <= r){
        int mid = (l+r) >> 1;
        if(chk(mid)) res = mid,l = mid+1;
        else r = mid-1;
    }
    cout << res << "\n";
}
int main(){
	int T = read();
    while(T--) solve();
    return 0;
}
