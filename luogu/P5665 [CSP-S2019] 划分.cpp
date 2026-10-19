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
const int N = 4e7+10;
int n,q[N],lst[N];
ll a[N];
inline void input(){
	int type = read();
	if(type == 0){
		for(int i=1;i<=n;i++) a[i] = read();
	}else{
		ll x = read(),y = read(),z = read();
		q[1] = read(); q[2] = read(); int m = read();
		int mod = 1<<30;
		int lst = 0;
		for(int i=3;i<=n;i++) q[i] = (1ll*x*q[i-1]+1ll*y*q[i-2]+z)%mod;
		for(int i=1;i<=m;i++){
			int p = read(),l = read(),r = read();
			for(int j=lst+1;j<=p;j++) a[j] = q[j]%(r-l+1)+l;
			lst = p;
		}
	}
}
void write(__int128 x){
	if(!x) return ;
	write(x/10);
	putchar('0'+(x%10));
}
int main(){
	n = read(); 
	input();
	for(int i=1;i<=n;i++) a[i] += a[i-1];
	/*
	sum_j-sum_{lst_j} <= sum_i-sum_j
	=>
	2*sum_j-sum_{lst_j} <= sum_i
	*/
	int l = 1,r = 1; q[1] = 0;
	for(int i=1;i<=n;i++){
		while(l < r && 2*a[q[l+1]]-a[lst[q[l+1]]] <= a[i]) l++;
		lst[i] = q[l];
		while(l < r && 2*a[q[r]]-a[lst[q[r]]] >= 2*a[i]-a[lst[i]]) r--;
		q[++r] = i;
	}
	__int128 ans = 0;
	int now = n;
	while(now){
		ans += __int128(a[now]-a[lst[now]])*(a[now]-a[lst[now]]);
		now = lst[now];
	}
	write(ans);
    return 0;
}
