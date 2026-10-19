#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const int N = 1e6+10;
int n,a[N],b[N];
map<int,int> t;
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = b[i] = read();
    sort(b+1,b+1+n);
    auto chk = [&](){
        for(int i=1;i<=n;i++)
            if(a[i] != b[i]) return false;
        return true;
    };
    if(chk()) return puts("0"),0;
    ll ans = 1ll*n*n;
    auto work = [&](){
        ll lst = 0;
        for(ll i=1,j=1;i<=n;i++){
            if(a[i] != b[i]) lst = i;
            t[a[i]]++;
            while(t[b[j]]) t[b[j]]--,j++;
            if(i == j-1) ans = min(ans,lst*lst+(n-j+1)*(n-j+1));
            else ans = min(ans,i*i+(n-j+1)*(n-j+1));
        }
    };
    work();
    reverse(a+1,a+1+n); reverse(b+1,b+1+n);
    work();
    cout << ans;
    return 0;
}