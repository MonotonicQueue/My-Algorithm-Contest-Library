#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,m,cnt;
struct FHQ_Tree{
	int ls,rs;
	int siz,val,pri,tag;
}t[N];
int newNode(int x){
	t[++cnt].siz = 1;
	t[cnt].val = x;
	t[cnt].pri = rand();
	return cnt;
}
void push_up(int rt){
	t[rt].siz = t[t[rt].ls].siz+1+t[t[rt].rs].siz;
}
void reverse(int rt){
	if(!rt) return ;
	swap(t[rt].ls,t[rt].rs); 
	t[rt].tag ^= 1;
}
void push_down(int rt){
	if(t[rt].tag){
		reverse(t[rt].ls);
		reverse(t[rt].rs);
		t[rt].tag = 0;
	}
}
void split(int rt,int k,int &L,int &R){
	if(!rt){
		L = R = 0;
		return ;
	}
	push_down(rt);
	if(k < t[t[rt].ls].siz+1){
		R = rt;
		split(t[rt].ls,k,L,t[rt].ls);
	}else{
		L = rt;
		split(t[rt].rs,k-t[t[rt].ls].siz-1,t[rt].rs,R);
	}
	push_up(rt);
}
int merge(int L,int R){
	if(!L || !R) return L+R;
	if(t[L].pri > t[R].pri){
		push_down(L);
		t[L].rs = merge(t[L].rs,R);
		push_up(L);
		return L;
	}else{
		push_down(R);
		t[R].ls = merge(L,t[R].ls);
		push_up(R);
		return R;
	}
}
int root;
void output(int rt){
	if(!rt) return ;
	push_down(rt);
	output(t[rt].ls);
	cout << t[rt].val << " ";
	output(t[rt].rs);
}
int main(){
	srand(time(0));
	n = read(); m = read();
	for(int i=1;i<=n;i++)
		root = merge(root,newNode(i));
	int L,R,p;
	while(m--){
		int l = read(),r = read();
		split(root,r,L,R);
		split(L,l-1,L,p);
		reverse(p);
		root = merge(merge(L,p),R);
	}
	output(root);
	return 0; 
}
