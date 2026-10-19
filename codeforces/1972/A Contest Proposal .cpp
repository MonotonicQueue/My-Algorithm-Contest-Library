#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
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
int n,a[N],b[N];
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=n;i++) b[i] = read();
		int ans = 0;
		for(int i=n,j=n;i>=1&&j >= 1;i--,j--){
			while(a[j] > b[i] && j >= 1) ans++,j--;
		}
		cout << ans << "\n";
	}
	return 0;
}