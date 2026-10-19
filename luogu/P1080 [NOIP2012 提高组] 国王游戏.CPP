#include<bits/stdc++.h>
using namespace std;
const int MAX = 1010,MAXN = 1e5;
int n,a,b;
struct node{
	int a,b;
	long long c;
}s[MAX];
bool cmp(node x,node y){
	return x.c < y.c;
}
int len_now,len_maxn,len_sum,maxn[MAXN],now[MAXN],sum[MAXN];
inline void cheng(int x){
	for(int i=1;i<=len_sum;i++) sum[i] *= x;
	for(int i=1;i<=len_sum;i++)
		if(sum[i] >= 10){
			sum[i+1]+=sum[i]/10;
			sum[i]%=10;
			if(i == len_sum) len_sum++;
		}
}
inline void chu(int x){
	int cnt = 0;
	len_now = len_sum;
	for(int i=1;i<=len_now;i++)
		now[i] = sum[i];
	for(int i=len_now;i>=1;i--){
		now[i] += cnt*10;
		cnt = now[i]%x;
		now[i]/=x;
	}
	for(int i=len_now;i>=1;i--)
		if(now[i]) break;
		else len_now--;
}
inline void copy(){
	len_maxn = len_now;
	for(int i=1;i<=len_now;i++)
		maxn[i] = now[i];
}
inline void work_max(){
	if(len_now > len_maxn){
		copy();
		return;
	}
	if(len_now < len_maxn) return;
	for(int i=len_now;i>=1;i--)
		if(now[i] < maxn[i]) return;
		else if(now[i] > maxn[i]){
			copy();
			return;
		}
}
int main(){
	cin >> n >> a >> b;
	for(int i=1;i<=n;i++){
		cin >> s[i].a >> s[i].b;
		s[i].c = s[i].a*s[i].b;
	}
	sort(s+1,s+1+n,cmp);
	len_sum = 1;
	sum[1] = 1;	
	s[0].a = a;
	for(int i=1;i<=n;i++){
		cheng(s[i-1].a);
		chu(s[i].b);
		work_max();
	}
	for(int i=len_maxn;i>=1;i--)
		cout << maxn[i];
	return 0;
}