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
		string s;
		cin >> s;
		int x = (s[0]-'0')*10+(s[1]-'0'),y = (s[3]-'0')*10+(s[4]-'0');
		bool flag = 0;
		if(x >= 12) x -= 12,flag = 1;
		if(x == 0) x += 12;
		if(x < 10) printf("0%d",x);
		else printf("%d",x);
		printf(":");
		if(y < 10) printf("0%d",y);
		else printf("%d",y);
		if(flag) puts(" PM");
		else puts(" AM");
	}
	return 0;
}
