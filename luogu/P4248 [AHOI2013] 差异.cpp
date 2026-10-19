#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
int n,sum;
string s;
int id[N],sa[N],rk[N],x[N],y[N],cnt[N],height[N];
bool cmp(int p,int q,int k){
	int a = p+k > n ? -1 : y[p+k];
	int b = q+k > n ? -1 : y[q+k];
	return a==b && y[p]==y[q];
}
void calc_sa(){
	int m = 127;
	for(int i=1;i<=m;i++) cnt[i] = 0;
	for(int i=1;i<=n;i++) cnt[x[i] = s[i]]++;
	for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
	for(int i=n;i>=1;i--) sa[cnt[x[i]]--] = i;
	for(int k=1;k<=n;k*=2){
		int p = 0;
		for(int i=n-k+1;i<=n;i++) y[++p] = i;
		for(int i=1;i<=n;i++) if(sa[i] > k) y[++p] = sa[i]-k;
		for(int i=1;i<=m;i++) cnt[i] = 0;
		for(int i=1;i<=n;i++) cnt[x[i]]++;
		for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
		for(int i=n;i>=1;i--) sa[cnt[x[y[i]]]--] = y[i];
		swap(x,y); p = 1; x[sa[1]] = 1;
		for(int i=2;i<=n;i++)
			x[sa[i]] = cmp(sa[i],sa[i-1],k) ? p : ++p;
		if(p == n) break;
		m = p;
	}
	//for(int i=1;i<=n;i++) cout << sa[i] << " ";
}
void getheight(){
	for(int i=1;i<=n;i++) rk[sa[i]] = i;
	int k = 0;
	for(int i=1;i<=n;i++){
		if(rk[i] == 1) continue;
		if(k) k--;
		int j = sa[rk[i]-1];
		while(s[i+k] == s[j+k]) k++;
		height[rk[i]] = k;
	}
}
int L[N],R[N],st[N],top;
int main(){
	cin >> s; n = s.size();
	s = " "+s;
	calc_sa(); getheight();
	st[top = 1] = 1;
	for(int i=2;i<=n;i++){
		while(top && height[st[top]] > height[i]) R[st[top--]] = i;
		L[i] = st[top];
		st[++top] = i;
	}
	while(top) R[st[top--]] = n+1;
	ll ans = (ll)n*(n-1)*(n+1)/2; 
	for(int i=2;i<=n;i++)
		ans -= 2ll*(i-L[i])*(R[i]-i)*height[i];
	cout << ans;
	return 0;
}