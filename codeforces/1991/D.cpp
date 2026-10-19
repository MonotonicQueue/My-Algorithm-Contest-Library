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
int ans[N]={0,1,2,2,3,3,4},n;
int main(){
	int T = read();
	while(T--){
		n = read();
		if(n <= 5){
			cout << ans[n] << "\n";
			for(int i=1;i<=n;i++) cout << ans[i] << " ";
			cout << "\n";
		}else{
			cout << "4\n";
			for(int i=1;i<=n;i++)
				cout << (i%4)+1 << " ";
			cout << "\n";
		}
	}
	return 0;
}
