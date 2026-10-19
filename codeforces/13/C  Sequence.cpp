#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
priority_queue<int>q;
int main(){
	int n = read(); ll ans = 0;
	for(int i=1;i<=n;i++){
		int a = read(); q.push(a);
		if(q.top() > a) ans += q.top()-a,q.pop(),q.push(a);
	}
	cout << ans;
	return 0;
}