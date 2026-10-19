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
int n,m;
int a[N],pos[N];
map<int,int>mp;
int cnt[N],ans[N];
struct Ques{
	int l,r;
	int id;
}q[N];
bool cmp(Ques x,Ques y){
	if(pos[x.l] != pos[y.l]) return pos[x.l] < pos[y.l];
	if(pos[x.l] & 1) return x.r > y.r;
	return x.r < y.r;
}
priority_queue<int>que;
bool er[N];
void init(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=m;i++){
		q[i].l = read(); q[i].r = read();
		q[i].id = i;
	}
	int block = sqrt(n);
	for(int i=1;i<=n;i++) pos[i] = (i-1)/block+1;
	sort(q+1,q+1+m,cmp);
	for(int i=0;i<=n;i++) que.push(-i);
}
inline void add(int x){
	if(a[x] > n) return; 
	cnt[a[x]]++;
	if(cnt[a[x]] == 1) er[a[x]] = 1;
}
inline void del(int x){
	if(a[x] > n) return; 
	cnt[a[x]]--;
	if(cnt[a[x]] == 0){
		if(er[a[x]]) er[a[x]] = 0;
		else que.push(-a[x]);
	}
}
signed main(){
	init();
	int L = 1,R = 0;
	for(int i=1;i<=m;i++){
		while(L < q[i].l) del(L++);
		while(L > q[i].l) add(--L);
		while(R < q[i].r) add(++R);
		while(R > q[i].r) del(R--);
		while(er[-que.top()]){
			er[-que.top()] = 0;
			que.pop();
		}
		ans[q[i].id] = -que.top();
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}