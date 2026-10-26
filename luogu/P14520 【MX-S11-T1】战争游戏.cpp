#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int> 
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n;
ll a[N],sum[N];
bool chk(int i){
	if(sum[i] > sum[n]-sum[i]) return true;
	if(a[i] <= a[i+1]) return false;
	if((i == n-1 || a[i]+a[i+1] > a[i+2]) && sum[i+1] > sum[n]-sum[i+1])return true;
	return false;
}
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
	for(int i=1;i<n;i++){
		if(chk(i)) cout << "1";
		else cout << "0";
	}
	cout << "\n";
} 
int main(){
	int T = read();
	while(T--) solve(); 
	return 0;
}
