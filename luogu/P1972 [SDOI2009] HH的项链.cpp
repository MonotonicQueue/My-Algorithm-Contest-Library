#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}
void write(ll X) {
	if(X < 0) putchar('-'),X=-X;
    if(X>9) write(X/10); 
    putchar(X%10+'0'); 
}
const int N = 1e6+10;
int n,m;
int a[N],ans[N];
struct node{
	int l,r,k;
}q[N];
bool cmp(node x,node y){
	return x.r < y.r;
}
int c[N],pre[N];
inline int lowbit(int x){
	return x&-x;
}
inline int query(int x){
	int sum = 0;
	while(x){
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
inline void add(int x,int k){
	while(x <= n){
		c[x] += k;
		x += lowbit(x);
	} 
}
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	m = read();
	for(int i=1;i<=m;i++){
		q[i].l = read();
		q[i].r = read();
		q[i].k = i;
	}
	sort(q+1,q+1+m,cmp);
	int p = 1;
	for(int i=1;i<=m;i++){
		for(int j=p;j<=q[i].r;j++){
			if(pre[a[j]]) add(pre[a[j]],-1);
			pre[a[j]] = j;
			add(j,1);
		}
		p = q[i].r+1;
		ans[q[i].k] = query(q[i].r)-query(q[i].l-1);
	}
	for(int i=1;i<=m;i++) cout << ans[i] << "\n";
	return 0;
}