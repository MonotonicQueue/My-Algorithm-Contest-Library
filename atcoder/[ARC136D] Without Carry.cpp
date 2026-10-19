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
int n,a[N],pw[6]={1,10,100,1000,10000,100000};
ull sum[N];
ll ans;
bool chk(int x){
	for(int i=0;i<6;i++){
		int num = (x/pw[i])%10;
		if(num >= 5) return false;
	}
	return true;
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		sum[a[i]]++;
		ans -= chk(a[i]);
	}
	for(int j=0;j<6;j++)
		for(int i=0;i<1000000;i++){
			int num = (i/pw[j])%10;
			if(num) sum[i] += sum[i-pw[j]];
		}
	for(int i=1;i<=n;i++)
		ans += sum[999999-a[i]];
	cout << ans/2;
    return 0;
}
