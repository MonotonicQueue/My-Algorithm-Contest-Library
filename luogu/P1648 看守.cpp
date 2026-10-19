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
const int N = 1e6+10;
int n,d;
int a[N][4],c[4];
int main(){
	n = read(); d = read();
	for(int i=1;i<=n;i++)
		for(int j=0;j<d;j++) a[i][j] = read();
	int ans = 0;
	for(int S=0;S<(1<<(d-1));S++){
		for(int i=0;i<d;i++)
			if((S >> i) & 1) c[i] = 1;
			else 			 c[i] = -1;
		int mx = -1e9,mn = 1e9;
		for(int i=1;i<=n;i++){
			int sum = 0;
			for(int j=0;j<d;j++) sum += c[j]*a[i][j];
			mx = max(mx,sum);
			mn = min(mn,sum);
		}
		ans = max(ans,mx-mn);
	}
	cout << ans;
    return 0;
}
