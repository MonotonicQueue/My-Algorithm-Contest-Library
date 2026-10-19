#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair 
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const ull P = 131;
const ull PP = 13131;
const int N = 2e5+10;
int n,ans,tot;
char a[N],b[N];
int pa[N],pb[N];
ull pw[N],pre[N],suf[N];
ull pw1[N],pre1[N],suf1[N];
char ch[N];
void manacher(char *s,int *p){
	tot = 0;
	ch[0] = '!';
	for(int i=1;i<=n;i++) ch[++tot] = '#',ch[++tot] = s[i];
	ch[++tot] = '#'; ch[++tot] = '?';
	for(int i=0;i<=tot;i++) s[i] = ch[i];
	
	int C = 0,R = 0;
	for(int i=1;i<tot;i++){
		if(i < R) p[i] = min(p[C*2-i],R-i);
		else p[i] = 1;
		while(s[i+p[i]] == s[i-p[i]]) p[i]++;
		if(i+p[i] > R) R = i+p[i],C = i;
	}
	for(int i=1;i<tot;i++) ans = max(ans,p[i]);
}
ull geta(int l,int r){
	return pre[r]-pre[l-1]*pw[r-l+1];
}
ull getb(int l,int r){
	return suf[l]-suf[r+1]*pw[r-l+1];
}
ull geta1(int l,int r){
	return pre1[r]-pre1[l-1]*pw1[r-l+1];
}
ull getb1(int l,int r){
	return suf1[l]-suf1[r+1]*pw1[r-l+1];
}
int calc(int x,int y){
	int l = 0,r = min(x,n-y),res = 0;
	while(l <= r){
		int mid = (l+r)>>1;
		if(geta(x-mid+1,x) == getb(y,y+mid-1) && geta1(x-mid+1,x) == getb1(y,y+mid-1)) res = mid,l = mid+1;
		else r = mid-1;
	}
	return res;
}
int main(){
	cin >> n;
	cin >> a+1 >> b+1;
	manacher(a,pa); manacher(b,pb);
	n = tot;
	pw[0] = pw1[0] = 1;
	for(int i=1;i<n;i++) pw[i] = pw[i-1]*P,pw1[i] = pw1[i-1]*PP;
	for(int i=1;i<n;i++) pre[i] = pre[i-1]*P+a[i],pre1[i] = pre1[i-1]*PP+a[i];
	for(int i=n-1;i;i--) suf[i] = suf[i+1]*P+b[i],suf1[i] = suf1[i+1]*PP+b[i];
//	for(int i=1;i<n;i++) cout << a[i]; cout <<"\n";
//	for(int i=1;i<n;i++) cout << b[i]; cout << "\n"; 
	for(int i=1;i<n;i++){
		ans = max(ans,pa[i]+calc(i-pa[i],i+pa[i]-2));
		ans = max(ans,pb[i]+calc(i-pb[i]+2,i+pb[i]));
	}
	cout << ans-1;
	return 0;
} 
//g++ -std=c++14 -O2 -Wall -o 1st 1st.cpp
//cd C:\Users\c\Desktop\gzez_lsa\1

/*
5
ABCDE
AAEDC

5
ABCDE
CBAAC
*/