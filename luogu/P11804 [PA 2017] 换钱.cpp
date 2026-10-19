#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
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
const int N = 2e6+10;
int n,a[N];
int t[N];
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) t[a[i]]++;
	int cnt = 0;
	for(int i=0;i<=2000000;i++)
		if(t[i]) cnt = i,t[i+1] += t[i]/2;
	cout << cnt << "\n";
	return 0;
}