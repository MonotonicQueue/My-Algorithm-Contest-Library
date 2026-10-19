#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5e5+10;
int n,a[N];
int t[N*30][2],cnt,sum[N*30];
void insert(int x){
	int p = 1;
	for(int i=30;~i;i--){
		int c = (x >> i) & 1;
		if(!t[p][c]) t[p][c] = ++cnt;
		p = t[p][c]; sum[p]++;
	}
}
int ask(int x){
	int res = 0,p = 1;
	bool flag = false;
	for(int i=30;~i;i--){
		int c = (x >> i) & 1;
		if(!flag){
			if(c == 1){
				flag = true;
				p = t[p][0];
			}else p = t[p][0];
		}else{
			if(c == 1){
				res += sum[t[p][1]];
				p = t[p][0];
			}else p = t[p][0];
		}
	}
	res += sum[p];
	return res;
}
int main(){
	int T = read();
	while(T--){
		auto clear = [&](){
			for(int i=1;i<=cnt;i++)
				t[i][0] = t[i][1] = sum[i] = 0;
			cnt = 1;
		};
		clear();
		n = read();
		ll ans = 0;
		for(int i=1;i<=n;i++) a[i] = read(),insert(a[i]);
		for(int i=1;i<=n;i++) ans += ask(a[i]);
		cout << ans << "\n";
	}
	
	return 0;
}
/*
1
15
132 256 852 31 1 0 12 13 12 0 0 255 143 23 32

*/