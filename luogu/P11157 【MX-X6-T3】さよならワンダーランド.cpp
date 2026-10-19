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
int n,a[N],b[N],suf[N],pos[N];
signed main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = a[i]-i;
    suf[n+1] = -2e9;
    for(int i=n;i;i--){
        if(b[i] > suf[i+1]) suf[i] = b[i],pos[i] = i;
        else suf[i] = suf[i+1],pos[i] = pos[i+1];
    }
    for(int i=1;i<=n;i++){
        int mn = max(1-i,a[i]);
        if(i+mn <= n && suf[i+mn]+i >= 0){
            cout << "1 " << pos[i+mn]-i << "\n";
        }else cout << "0\n";
    }
    return 0;
}
