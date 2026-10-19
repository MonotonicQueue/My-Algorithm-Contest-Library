#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read() {
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) {
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 5e5+10;
int n;
char ch[N],ch2[N];
ull P = 131,pp[N],f[N],g[N],ans;
void search(int x){
	int L = 0,R = min(x,n-x);
	while(L < R){
		int mid = (L+R+1)>>1;
		if((ull)(f[x]-f[x-mid]*pp[mid]) == (ull)(g[x+1]-g[x+mid+1]*pp[mid])) L = mid;
		else R= mid-1; 
	}
	ans += L;
}
int main() {
	n = read();
	scanf("%s",ch+1);
	pp[0] = 1;
	for(int i=1;i<=n;i++) pp[i] = pp[i-1]*P;
	for(int i=1;i<=n;i++) ch2[i] = ch[i] == '0' ? '1' : '0';
	for(int i=1;i<=n;i++) f[i] = f[i-1]*P+ch[i];
	for(int i=n;i>=1;i--) g[i] = g[i+1]*P+ch2[i];
	for(int i=1;i<n;i++) search(i);
	cout << ans;
	return 0;
}