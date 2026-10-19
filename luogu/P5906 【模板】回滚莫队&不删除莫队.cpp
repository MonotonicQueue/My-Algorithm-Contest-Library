#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 2e5+10;
int n,m,a[N],b[N];
int pos[N],L[N],R[N],t;
struct Ques{
	int l,r;
	int id;
}q[N];
map<int,int>mp;
bool cmp(Ques x,Ques y){
	if(pos[x.l] != pos[y.l]) return pos[x.l] < pos[y.l];
	return x.r < y.r;
}
inline void init(){
	n = read();
	for(int i=1;i<=n;i++) b[i] = a[i] = read();
	m = read();
	sort(b+1,b+1+n);
	int tot = 0,block = sqrt(n);
	for(int i=1;i<=n;i++) if(b[i] == b[i-1]) mp[b[i]] = ++tot;
	for(int i=1;i<=n;i++) a[i] = mp[a[i]];
	for(int i=1;i<=m;i++){
		q[i].l = read(); q[i].r = read();
		q[i].id = i;
	}
	t = n/block;
	if(n % block) t++;
	for(int i=1;i<=t;i++){
		L[i] = (i-1)*block+1;
		R[i] = i*block;
	} R[t] = n;
	for(int i=1;i<=n;i++) pos[i] = (i-1)/block+1;
	sort(q+1,q+1+m,cmp);
}
int res[N],st[N],ed[N],en[N];
signed main(){
	init();
	int block = 0,l = 0,r = 0,ans1 = 0;
	for(int i=1;i<=m;i++){
		if(pos[q[i].l] == pos[q[i].r]){
			ans1 = 0;
			for(int j=q[i].l;j<=q[i].r;j++) st[a[j]] = 0;
			for(int j=q[i].l;j<=q[i].r;j++){
				if(!st[a[j]]) st[a[j]] = j;
				ans1 = max(ans1,j-st[a[j]]);
			}
			for(int j=q[i].l;j<=q[i].r;j++) st[a[j]] = 0;
			res[q[i].id] = ans1;
			continue;
		}
		int now = pos[q[i].l];
		if(block != now){
			ans1 = 0;
			for(int j=l;j<=r;j++) st[a[j]] = ed[a[j]] = 0;
			l = R[now]; r = l-1;
			block = now;
		}
		while(r < q[i].r){
			r++;
			if(!st[a[r]]) st[a[r]] = r;
			ed[a[r]] = r;
			ans1 = max(ans1,r-st[a[r]]);
		}
		int p = l,ans2 = 0;
		while(q[i].l < p){
			p--;
			if(!en[a[p]]) en[a[p]] = p;
			ans2 = max(ans2,max(en[a[p]],ed[a[p]])-p);
		}
		while(p < l){
			en[a[p]] = 0;
			p++;
		}
		res[q[i].id] = max(ans1,ans2);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",res[i]);
	return 0;
}
