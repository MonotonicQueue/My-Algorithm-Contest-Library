#include<bits/stdc++.h>
#define ll long long
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
int a[N],t[N]; 
int main(){
// 	freopen("duel.in","r",stdin);
// 	freopen("duel.out","w",stdout);
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) t[a[i]]++;
	int ans = 0;
	for(int i=1;i<=100000;i++){
		ans = max(ans-t[i],0);
		ans += t[i];
	}
	cout << ans << "\n"; 
	return 0;
} 
