#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
int n;
ll a[N],mn[N],mx[N];
int main(){
	int T = read();
	while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        mn[1] = a[1];
        mx[1] = max(a[1],-a[1]);
        for(int i=2;i<=n;i++){
            mn[i] = mn[i-1]+a[i];
            mx[i] = max(mx[i-1]+a[i],abs(mn[i]));
        }
        cout << mx[n] << "\n";
	}
	return 0;
}