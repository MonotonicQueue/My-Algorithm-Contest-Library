#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e3+10;
int n,k;
ll a[N],b[N],ans[N];
int main(){
	n = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) b[i] = read();
	int cnt = 0;
	for(int i=n;i;i--){
		int x = a[i]/b[i];
		if(x+cnt > k){
			x = k-cnt;
			cnt = k;
			ans[i] = x;
			break;
		}else{
			ans[i] = x;
			cnt += x;
		}
	}
	if(cnt != k){
		for(int i=1;i<=n;i++) cout << "0 ";
	}else{
		for(int i=1;i<=n;i++) cout << ans[i] << " ";
	}
    return 0;
}