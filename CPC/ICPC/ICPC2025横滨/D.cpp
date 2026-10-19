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
void write(__int128 x){
	if(!x) return ;
	write(x/10);
	cout << int(x%10);
}
void solve(){
	__int128 x = read(),ans = 0;
	for(ll i=1;i<=x;i*=10){
		ans = max(ans,(x-i)*i*10+i);
	}
	write(ans);
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}
