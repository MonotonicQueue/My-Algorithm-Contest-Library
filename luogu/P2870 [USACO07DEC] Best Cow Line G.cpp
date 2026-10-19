#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char ch[N];
int sa[N],rk[N],x[N],y[N],cnt[N];
bool cmp(int *y,int p,int q,int k,int n){
	int a = p+k > n ? -1 : y[p+k];
	int b = q+k > n ? -1 : y[q+k];
	return a == b && y[p] == y[q];
}
void calc_sa(int n){
	int m = 127;
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
void getheight(int n){
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
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",&ch[i]); ch[n+1] = 'a';
	for(int i=1;i<=n;i++) ch[n+i+1] = ch[n-i+1];
	calc_sa(2*n+1); getheight(2*n+1);
	int l = 1, r = n, tot = 0;
	while(l < r){
		if(ch[l] == ch[r]){
			if(rk[l] < rk[2*n+2-r]) putchar(ch[l++]);
			else putchar(ch[r--]);
		}else if(ch[l] < ch[r]) putchar(ch[l++]);
		else putchar(ch[r--]);
		tot++;
		if(tot == 80){
			tot = 0;
			putchar('\n');
		}
	}
	putchar(ch[l]);
	return 0;
}