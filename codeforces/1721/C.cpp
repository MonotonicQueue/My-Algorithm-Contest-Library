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
int n;
int a[N],b[N],mn[N];
int ans2[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    // for(int i=0;i<=n;i++) cnt[i] = 0;
    for(int i=1,j=1;i<=n;i++){
        while(j < n && b[j] < a[i]) j++;
        cout << b[j]-a[i] << " ";
    }
    cout << "\n";
    mn[n] = n;
    for(int i=n-1;i;i--){
        mn[i] = mn[i+1];
        if(b[i] < a[i+1]) mn[i] = i;
    }
    for(int i=1;i<=n;i++) cout << b[mn[i]]-a[i] << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}