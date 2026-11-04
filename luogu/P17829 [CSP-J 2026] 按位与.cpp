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
int n,m,a[N];
void solve(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	int ans = 0;
	for(int j=30;~j;j--){
		int cnt = 0;
		for(int i=1;i<=n;i++) cnt += (a[i] >> j) & 1;
		if(cnt >= m){
			ans |= 1<<j;
			for(int i=1;i<=n;i++)
				if((a[i] >> j) % 2 == 0) a[i] = 0;
		}
	}
	cout << ans << '\n';
}
int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
