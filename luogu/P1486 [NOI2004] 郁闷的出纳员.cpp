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
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 3e5+10;
ll n,minn,tot; 
ll c,root;
struct FHQ_Tree{
	int ls,rs;
	ll siz,val,pri;
}t[N];
int newNode(ll x){
	t[++tot].val = x;
	t[tot].pri = rand();
	t[tot].siz = 1;
	return tot;
}
inline void push_up(int rt){
	t[rt].siz = t[t[rt].ls].siz+1+t[t[rt].rs].siz;
}
void split(int rt,int k,int &L,int &R){
	if(!rt){
		L = R = 0;
		return ;
	}
	if(t[rt].val <= k){
		L = rt;
		split(t[rt].rs,k,t[rt].rs,R);
	}else{
		R = rt;
		split(t[rt].ls,k,L,t[rt].ls);
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
ll kth(int rt,ll k){
	if(t[t[rt].ls].siz+1 == k) return t[rt].val;
	if(t[t[rt].ls].siz+1 > k) return kth(t[rt].ls,k);
	return kth(t[rt].rs,k-t[t[rt].ls].siz-1);
}
ll sum;
int main(){
	srand(time(0));
	n = read(); minn = read();
	int L,R;
	while(n--){
		char ch[2];
		scanf("%s",ch);
		ll k = read();
		if(ch[0] == 'I'){
			if(k < minn) continue;
			int p = newNode(k-c);
			split(root,k-c,L,R);
			root = merge(merge(L,p),R);
		}else if(ch[0] == 'A'){
			c += k;
		}else if(ch[0] == 'S'){
			c -= k;
			split(root,minn-c-1,L,R);
			sum += t[L].siz;
			root = R;
		}else{
			if(t[root].siz < k){
				puts("-1");
				continue;
			}
			printf("%lld\n",kth(root,t[root].siz-k+1)+c);
		}
	}
	printf("%lld",sum);
	return 0;
}
/*
9 10
I 60
I 70
S 50
F 2
I 30
S 15
A 5
F 1
F 2
*/