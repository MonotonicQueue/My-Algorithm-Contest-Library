#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e7+5;
int raw[200];
int n,m;
int son[N][4],fa[N],len[N],tot=1,lst=1;
inline void insert(int c){
	int p = lst,cur = ++tot;
	len[cur] = len[p]+1;
	while(p && !son[p][c]) son[p][c] = cur,p = fa[p];
	if(!p) fa[cur] = 1;
	else{
		int q = son[p][c];
		if(len[q] == len[p]+1) fa[cur] = q;
		else{
			int nq = ++tot;
			len[nq] = len[p]+1;
			memcpy(son[nq],son[q],sizeof(son[q]));
			fa[nq] = fa[q];
			fa[q] = fa[cur] = nq;
			while(p && son[p][c] == q) son[p][c] = nq,p = fa[p];
		}
	}
	lst = cur;
}
const int M = 1e5+10;
char s[M];
int main(){
	raw['W'] = 0, raw['S'] = 1, raw['E'] = 2, raw['N'] = 3;
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		char ch; cin >> ch;
		insert(raw[ch]);
	}
	for(int i=1;i<=m;i++){
		cin >> s+1;
		int len = strlen(s+1),j,p=1;
		for(j=1;j<=len;j++){
			if(!son[p][raw[s[j]]]) break;
			p = son[p][raw[s[j]]];
		}
		cout << j-1 << "\n";
	}
	return 0;
}