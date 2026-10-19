#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e4+10;
int n,a[N],b[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) b[i] = read();
	auto SG = [&](int x,int a){
		int nx = 0,na = 0,k = 0;
		bool flag = false;
		for(int i=30;~i;i--){
			int p = (x >> i) & 1,q = (a >> i) & 1;
			flag |= q;
			if(p && q) nx = nx<<1|1,na = na<<1|1;
			else if(p && flag) nx = nx<<1|1,na = na<<1;
			else if(q) a |= (1<<i)-1;
		}
		for(int i=0;i<30;i++)
			if((nx >> i) & 1) k++;
		if((1 << (k-1)) == na) return (k-1)^1;
		if(na == nx) return k;
		if(na == nx-1) return 0;
		return k;
	};
	int sum = 0;
	for(int i=1;i<=n;i++)
		sum ^= SG(b[i],a[i]);
	puts(sum ? "Alice" : "Bob");
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
} 
/*
1
4
8 32 65 64
7 45 126 94
*/