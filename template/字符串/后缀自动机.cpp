#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e5+10;
int n; char ch[N];
int fa[N],son[N][26],len[N],tot=1,lst=1;
inline void insert(int c){
	int p = lst,cur = ++tot;
	len[cur] = len[p]+1;
	while(p && !son[p][c]) son[p][c] = cur,p = fa[p];
	if(!p) fa[cur] = 1;
	else{
		int q = son[p][c];
		if(len[p]+1 == len[q]) fa[cur] = q;
		else{
			int nq = ++tot;
			len[nq] = len[p]+1;
			memcpy(son[nq],son[q],sizeof(son[nq]));
			fa[nq] = fa[q];
			fa[q] = fa[cur] = nq;
			while(p && son[p][c] == q)
				son[p][c] = nq,p = fa[p];
		}
	}
	lst = cur;
}
int main(){
	
	scanf("%s",ch+1);
	n = strlen(ch+1);
	for(int i=1;i<=n;i++)
		insert(ch[i]-'a');
	return 0;
}
