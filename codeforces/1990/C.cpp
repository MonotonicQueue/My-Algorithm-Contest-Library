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
int n,m,a[N],cnt[N];
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read(),cnt[i] = 0;
        ll sum = 0; int mx = 0;
        for(int i=1;i<=n;i++){
            sum += a[i];
            cnt[a[i]]++;
            if(cnt[a[i]] == 2) mx = max(mx,a[i]);
            a[i] = mx;
        }
        for(int i=1;i<=n;i++) cnt[i] = 0;
        mx = 0;
        for(int i=1;i<=n;i++){
            sum += a[i];
            cnt[a[i]]++;
            if(cnt[a[i]] == 2) mx = max(mx,a[i]);
            a[i] = mx;
        }
        for(int i=n;i;i--) sum += 1ll*(n-i+1)*a[i];
        cout << sum << "\n";
    }
	return 0;
}