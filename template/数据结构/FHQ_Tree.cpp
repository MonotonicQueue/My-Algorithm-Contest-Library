#include<bits/stdc++.h>
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
const int N = 1e5+10;
int n;
int cnt,root;
struct FHQ_Tree{
	int ls,rs;
	int pri,key,siz;
}t[N];
int newNode(int x){
	t[++cnt].pri = rand();
	t[cnt].key = x;
	t[cnt].siz = 1;
	return cnt;
}
inline void push_up(int rt){
	t[rt].siz = t[t[rt].ls].siz+t[t[rt].rs].siz+1;
}
void split(int rt,int x,int &L,int &R){
	if(!rt){L = R = 0; return ;}
	if(t[rt].key <= x){
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
	if(t[L].pri < t[R].pri){
		t[L].rs = merge(t[L].rs,R);
		push_up(L);
		return L;
	}else{
		t[R].ls = merge(L,t[R].ls);
		push_up(R);
		return R;
	}
}
int kth(int rt,int x){
	if(t[t[rt].ls].siz+1 == x) return t[rt].key;
	if(t[t[rt].ls].siz >= x) return kth(t[rt].ls,x);
	return kth(t[rt].rs,x-t[t[rt].ls].siz-1);
}
int main(){
	n = read();
	int L,R;
	for(int i=1;i<=n;i++){
		int op = read(),x = read();
		if(op == 1){
			int p = newNode(x);
			split(root,x,L,R);
			root = merge(merge(L,p),R);
		}else if(op == 2){
			int p;
			split(root,x,L,R);
			split(L,x-1,L,p);
			p = merge(t[p].ls,t[p].rs);
			root = merge(merge(L,p),R);
		}else if(op == 3){
			split(root,x-1,L,R);
			cout << t[L].siz+1 << "\n";
			root = merge(L,R);
		}else if(op == 4){
			cout << kth(root,x) << "\n";
		}else if(op == 5){
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
