#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
int n,k,a[N];
int main(){
    int T = read();
    while(T--){
        n = read(); k = read();
        for(int i=1;i<=n;i++) a[i] = read();
        sort(a+1,a+1+n);
        int ans = 0;
        for(int l=1,r=1;l<=n;l++){
            r = max(l,r);
            while(r < n && a[r+1]-a[r] <= 1 && a[r+1]-a[l] < k) r++;
            ans = max(ans,r-l+1);
        }
        cout << ans << "\n";
    }
    return 0;
}