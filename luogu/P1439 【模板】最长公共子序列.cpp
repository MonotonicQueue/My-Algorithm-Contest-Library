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
const int N = 1e5+10;
int n,a[N],b[N],c[N],f[N];
int t[N];
void add(int x,int y){
	while(x <= n){
		t[x] = max(t[x],y);
		x += x&(-x);
	}
}
int ask(int x){
	int res = 0;
	while(x){
		res = max(res,t[x]);
		x -= x&(-x);
	}
	return res;
}
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) b[i] = read();
	for(int i=1;i<=n;i++) c[b[i]] = i;
	for(int i=1;i<=n;i++){
		f[i] = ask(c[a[i]])+1;
		add(c[a[i]],f[i]);
	}
	cout << ask(n);
    return 0;
}