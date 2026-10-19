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
const int N = 1e5+10;
int n,a[N];
int cnt[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    if(n == 1){puts("1"); return ;}
    for(int i=1;i<=n;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    sort(cnt+1,cnt+1+n,greater<int>());
    int ans = cnt[1]|cnt[2],sum = cnt[1]&cnt[2];
    for(int i=0;i<20;i++){
        if(sum >= 1<<i) ans |= (1<<i)-1;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
	return 0;
}