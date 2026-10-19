#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 110;
int n,num[N],maxn,sum; 
bitset<35> a[N];
int main(){
	n = read();
	for(int i=1;i<=n;i++) num[i] = read(),maxn = max(maxn,num[i]),sum += num[i];
	int m = log(maxn)/log(2)+1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			a[i][m-j] = (num[i]>>j)&1;
	for(int i=1;i<=min(n,m);i++){
		maxn = i;
		for(int j=i+1;j<=n;j++){
			if(!a[maxn][i] && a[j][i]) maxn = j;
			if(a[j][i] && num[j] > num[maxn]) maxn = j;
		}
		if(!a[maxn][i]) continue;
		if(maxn != i){swap(a[i],a[maxn]);swap(num[i],num[maxn]);}
		for(int j=1;j<=n;j++)
			if(i != j && a[j][i])
				a[j] = a[j]^a[i];
	}
	ll ans = 0;
	for(int i=1;i<=n;i++)
		if(a[i] == 0) ans += num[i];
	printf("%lld",ans);
	return 0;
} 
