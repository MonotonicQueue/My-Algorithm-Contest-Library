#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){ch = getchar(); r = -1;}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar(); 
	}
	return X*r;
}
const int N = 110;
const int M = 114514;
int F,n;
int sg[M];
int getSG(int x){
	if(x < F) return 0;
	if(~sg[x]) return sg[x];
	bool vis[N];
	memset(vis,0,sizeof(vis));
	for(int l=2,r;l<=x;l=r+1){
		r = x/(x/l);
		bool flag = 1;
		if(l == r) flag = 0;
		int res = 0;
		if((x%l) & 1) res ^= getSG(x/l+1);
		if((l-x%l) & 1) res ^= getSG(x/l);
		vis[res] = 1;
		if(flag){
			l++; res = 0;
			if((x%l) & 1) res ^= getSG(x/l+1);
			if((l-x%l) & 1) res ^= getSG(x/l);
			vis[res] = 1;
		}
	}
	for(int i=0;;i++)
		if(!vis[i]) return sg[x] = i;
}
int main(){
	int T = read(); F = read();
	memset(sg,-1,sizeof(sg));
	while(T--){
		n = read();
		int ans = 0;
		for(int i=1;i<=n;i++){
			int a = read();
			ans ^= getSG(a);
		}
		if(ans == 0) cout << "0 ";
		else cout << "1 ";
	}
	return 0;
}