#include<bits/stdc++.h>
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
const int N = 2e5+10;
int n,len;
char ch[N];
int sa[N],t1[N],t2[N],rk[N],cnt[N];
void getsa(int *x,int *y){
	int m = 127;
	for(int i=1;i<=n;i++) cnt[x[i] = ch[i]]++;
	for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
	for(int i=n;i;i--) sa[cnt[x[i]]--] = i;
	for(int k=1;k<=n;k*=2){
		int p = 0;
		for(int i=n-k+1;i<=n;i++) y[++p] = i;
		for(int i=1;i<=n;i++) if(sa[i] > k) y[++p] = sa[i]-k;

		for(int i=1;i<=m;i++) cnt[i] = 0;
		for(int i=1;i<=n;i++) cnt[x[y[i]]]++;
		for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
		for(int i=n;i;i--) sa[cnt[x[y[i]]]--] = y[i];
		
		swap(x,y); p = 1; x[sa[1]] = 1;
		for(int i=2;i<=n;i++)
			x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k] ? p : ++p;
		m = p;
		if(m == n) break;
	}
	for(int i=1;i<=n;i++) rk[sa[i]] = i;
	// for(int i=1;i<=n;i++) cout << sa[i] << " ";
	// cout << "\n";
	// for(int i=1;i<=n;i++) cout << rk[i] << " ";
	// cout << "\n";
}
int main(){
    cin >> ch+1;
	n = len = strlen(ch+1);
	for(int i=1;i<=len;i++) ch[++n] = ch[i];
	getsa(t1,t2);
	for(int i=1;i<=n;i++)
		if(sa[i] <= len) cout << ch[sa[i]+len-1];
	return 0;
}