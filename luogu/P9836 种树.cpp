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
const int N = 1e4+10;
const int M = 1400;
const int mod = 998244353;
int n,w;
int pr[N],cnt,sum[M];
bool vis[N];
void init(){
	for(int i=2;i<=10000;i++){
		if(!vis[i]) pr[++cnt] = i;
		for(int j=1;j<=cnt&&pr[j]*i<=10000;j++){
			vis[pr[j]*i] = true;
			if(i % pr[j] == 0) break;
		}
	}
}
priority_queue<int>q[M];
void divide(int x){
	for(int i=1;i<=cnt;i++){
		if(x % pr[i] != 0) sum[i]++;
		else{
			int res = 0;
			while(x % pr[i] == 0) res++,x /= pr[i];
			q[i].push(-res);
		}
	}
}

int main(){
	init();
	n = read(); w = read();
	for(int i=1;i<=n;i++){
		int p = read();
		divide(p);
	}
	for(int i=1;i<=cnt;i++){
		if(w % pr[i] == 0){
			while(w % pr[i] == 0){
				w /= pr[i];
				if(sum[i]) sum[i]--,q[i].push(-1);
				else{
					int x = -q[i].top(); q[i].pop();
					q[i].push(-(x+1));
				}
			}
		}
	}
	ll ans = 1;
	for(int i=1;i<=cnt;i++){
		while(!q[i].empty()){
			ans = ans*(-q[i].top()+1)%mod;
			q[i].pop();
		}
	}
	cout << ans;
	return 0;
}