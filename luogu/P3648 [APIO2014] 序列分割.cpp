#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){r = -1; ch = getchar();}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 1e5+10;
int n,k,a[N],q[N];
ll s[N],f[N],g[N];
int pre[N][205];
double slope(int i,int j) {
	if(s[i] == s[j]) return -1e18;
	return 1.0*((g[i]-s[i]*s[i])-(g[j]-s[j]*s[j]))/(s[j]-s[i]);
}
int main(){
	n = read(); k = read();
	for(int i=1;i<=n;++i) a[i] = read();
	for(int i=1;i<=n;i++) s[i] = s[i-1]+a[i];
	for(int j=1;j<=k;++j) {
		int l = 1,r = 1;
		q[1] = 0;
		for(int i=1;i<=n;++i) {
			while(l < r && slope(q[l],q[l+1]) <= s[i]) ++l;
			f[i] = g[q[l]]+s[q[l]]*(s[i]-s[q[l]]);
			pre[i][j] = q[l];
			while(l < r && slope(q[r-1],q[r]) >= slope(q[r],i)) --r;
			q[++r] = i;
		}
		memcpy(g,f,sizeof(f));
	}
	cout << f[n] << "\n";
	for(int x=n,i=k;i>=1;--i){
		x = pre[x][i];
		cout << x << " ";
	}
	return 0;
}