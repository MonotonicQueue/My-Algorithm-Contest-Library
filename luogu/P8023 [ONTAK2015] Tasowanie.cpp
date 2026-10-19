#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
int n;
int ch[N];
int sa[N],rk[N],x[N],y[N],cnt[N];
bool cmp(int *y,int p,int q,int k,int n){
	int a = p+k > n ? -1 : y[p+k];
	int b = q+k > n ? -1 : y[q+k];
	return a == b && y[p] == y[q];
}
void calc_sa(){
	int m = 1100;
	for(int i=1;i<=m;i++) cnt[i] = 0;
	for(int i=1;i<=n;i++) cnt[x[i] = ch[i]]++;
	for(int i=2;i<=m;i++) cnt[i] += cnt[i-1];
	for(int i=n;i>=1;i--) sa[cnt[x[i]]--] = i;
	for(int k=1;k<=n;k*=2){
		int p = 0;
		for(int i=n-k+1;i<=n;i++) y[++p] = i;
		for(int i=1;i<=n;i++) if(sa[i] > k) y[++p] = sa[i]-k;
		for(int i=1;i<=m;i++) cnt[i] = 0;
		for(int i=1;i<=n;i++) cnt[x[i]]++;
		for(int i=2;i<=m;i++) cnt[i] += cnt[i-1];
		for(int i=n;i>=1;i--) sa[cnt[x[y[i]]]--] = y[i];
		swap(x,y);
		x[sa[1]] = 1; p = 1;
		for(int i=2;i<=n;i++)
			x[sa[i]] = cmp(y,sa[i],sa[i-1],k,n) ? p : ++p;
		if(p == n) break;
		m = p;
	}
	//for(int i=1;i<=n;i++) cout <<sa[i] <<" ";
}
int height[N];
void getheight(){
	for(int i=1;i<=n;i++) rk[sa[i]] = i;
	int k = 0;
	for(int i=1;i<=n;i++){
		if(rk[i] == 1) continue;
		if(k) k--;
		int j = sa[rk[i-1]];
		while(ch[i+k] == ch[j+k]) k++;
		height[rk[i]] = k; 
	}
}
int main(){
	int len1,len2; cin >> len1;
	for(int i=1;i<=len1;i++) cin >> ch[i];
	ch[len1+1] = 1010; cin >> len2; 
	for(int i=1;i<=len2;i++) cin >> ch[i+1+len1]; 
	n = len1+len2+2;
	ch[n] = 1050;
	calc_sa(); getheight();
	int i,j;
	for(i=1,j=1;i<=len1&&j<=len2;){
		if(rk[i] < rk[j+len1+1]) cout << ch[i++] << " ";
		else cout << ch[len1+1+j++] << " ";
	}
	while(i <= len1) cout << ch[i++] << " ";
	while(j <= len2) cout << ch[len1+1+j++] << " ";
	return 0;
}
