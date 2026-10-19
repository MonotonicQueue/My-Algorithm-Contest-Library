#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
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
const int N = 2e5+10;
int n; ll k;
ll a[N],cnt;
int main(){
	int T = read();
	while(T--){
		n = read(); k = read();
		ll sum = 0; cnt = 0;
		if(k != 1){
			for(int i=0;sum+(1<<i)<k;i++) a[++cnt] = 1<<i,sum += 1<<i;
			if(k-sum-1) a[++cnt] = k-sum-1;
			sum = k-1;
			if(k != n){
				int i=1;
				while(sum < n) sum += i*k+1,a[++cnt] = i*k+1,i*=2;
				if(3*k+1 <= n) a[++cnt] = 3*k+1;
			}
		}else{
			for(int i=1;sum<n;i++) a[++cnt] = 1<<i,sum+=(1<<i);
			a[++cnt] = 3;
		}
		cout << cnt << "\n";
		for(int i=1;i<=cnt;i++) cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}