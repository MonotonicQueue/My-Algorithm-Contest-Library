#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 5e5+10;
int n,m,fa[N],L[N],R[N],siz[N];
int pre[N],nxt[N];
int get(int x){
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
void swp(int x,int y){
	int d = get(x);
	if(L[d] == x) L[d] = y;
	if(R[d] == y) R[d] = x;
	pre[y] = pre[x]; nxt[x] = nxt[y];
	pre[x] = y; nxt[y] = x;
	nxt[pre[y]] = y;
	pre[nxt[x]] = x;
}
void rev(int x){
	int it = L[x];
	vector<int> v;
	while(it){
		int lst = it;
		it = nxt[it];
		swap(pre[lst],nxt[lst]);
	}
	swap(L[x],R[x]);
}

int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		fa[i] = i;
		L[i] = R[i] = i;
		siz[i] = 1;
	}
	auto op = [&](int x)->int{
		int y = get(x);
		if(L[y] == x) return 0;
		if(R[y] == x) return 1;
		return 2;
	};
	for(int i=1;i<=m;i++){
		int a = read(),b = read();
		if(get(a) != get(b)){
			int x = get(a),y = get(b);
			if(op(a) == 2 || op(b) == 2){
				puts("No");
				return 0;
			}
			if(siz[x] < siz[y]) swap(x,y),swap(a,b);
			if(op(a) == op(b)) rev(y);
			if(op(a) == 0){
				pre[a] = b; nxt[b] = a;
				L[x] = L[y];
			}else{
				nxt[a] = b; pre[b] = a;
				R[x] = R[y];
			}
			fa[y] = x; siz[x] += siz[y];
		}
		if(pre[a] == b){
			swp(b,a);
		}else if(pre[b] == a){
			swp(a,b);
		}else{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	vector<int> v;
	for(int i=1;i<=n;i++)
		if(fa[i] == i) v.emplace_back(i);
	for(int x : v){
		if(L[x] > R[x]) rev(x);
	}
	sort(v.begin(),v.end(),[](int x,int y){return L[x] < L[y];});
	for(int x : v){
		int y = L[x];
		while(y){
			cout << y << "\n";
			y = nxt[y];
		}
	}
    return 0;
}