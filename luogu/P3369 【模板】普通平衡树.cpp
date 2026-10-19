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
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,tot;
mt19937 rnd(time(0));
struct FHQ_Tree{
	int ls,rs;
	int siz,val,pri;
}t[N];
int newNode(int x){
	t[++tot].val = x;
	t[tot].siz = 1;
	t[tot].pri = rnd();
	return tot;
}
inline void push_up(int rt){
	t[rt].siz = t[t[rt].ls].siz+1+t[t[rt].rs].siz;
}
void split(int rt,int x,int &L,int &R){
	if(!rt){L = R = 0; return ;}
	if(t[rt].val <= x){
		L = rt;
		split(t[rt].rs,x,t[rt].rs,R);
	}else{
		R = rt;
		split(t[rt].ls,x,L,t[rt].ls);
	}
	push_up(rt);
}
int merge(int L,int R){
	if(!L || !R) return L+R;
	if(t[L].pri > t[R].pri){
		t[L].rs = merge(t[L].rs,R);
		push_up(L);
		return L;
	}else{
		t[R].ls = merge(L,t[R].ls);
		push_up(R);
		return R;
	}
}
int kth(int rt,int k){
	if(t[t[rt].ls].siz+1 == k) return t[rt].val;
	if(t[t[rt].ls].siz+1 >  k) return kth(t[rt].ls,k);
	return kth(t[rt].rs,k-1-t[t[rt].ls].siz);
}
int main(){
	n = read();
	int root = 0;
	for(int i=1;i<=n;i++){
		int opt = read(),x = read(),L,R;
		if(opt == 1){
			int p = newNode(x);
			split(root,x,L,R);
			root = merge(merge(L,p),R);
		}else if(opt == 2){
			int p;
			split(root,x,L,R);
			split(L,x-1,L,p);
			p = merge(t[p].ls,t[p].rs);
			root = merge(merge(L,p),R);
		}else if(opt == 3){
			split(root,x-1,L,R);
			cout << t[L].siz+1 << "\n";
			root = merge(L,R);
		}else if(opt == 4){
			cout << kth(root,x) << "\n";
		}else if(opt == 5){
			split(root,x-1,L,R);
			cout << kth(L,t[L].siz) << "\n";
			root = merge(L,R);
		}else{
			split(root,x,L,R);
			cout << kth(R,1) << "\n";
			root = merge(L,R);
		}
	}
	return 0;
}
/*
input:
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
output:
106465
84185
492737
 */


























