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
signed main(){
	int T = read();
	while(T--){
		int a = read(),b = read(),c = read();
		if(a < b && b < c) puts("STAIR");
		else if(a < b && b > c) puts("PEAK");
		else puts("NONE");
	}
	return 0;
}
///