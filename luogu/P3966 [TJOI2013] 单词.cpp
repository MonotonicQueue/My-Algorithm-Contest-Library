#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+10000;
int n,m,s[N];
char ch[N];
struct Suffix_Automation{
	int fa[N],son[N][27],len[N],tot,lst;
	int cnt[N],pos[N],siz[N];
	Suffix_Automation(){tot = lst = 1;}
	void insert(int c){
		int p = lst,cur = ++tot;
		len[cur] = len[lst]+1; siz[cur] = 1;
		while(p && !son[p][c])
			son[p][c] = cur,p = fa[p];
		if(!p) fa[cur] = 1;
		else{
			int q = son[p][c];
			if(len[q] == len[p]+1) fa[cur] = q;
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
	void build(){
		for(int i=1;i<=tot;i++) cnt[len[i]]++;
		for(int i=1;i<=tot;i++) cnt[i] += cnt[i-1];
		for(int i=1;i<=tot;i++) pos[cnt[len[i]]--] = i;
		for(int i=tot;i>=1;i--) siz[fa[pos[i]]] += siz[pos[i]];
		siz[1] = 0; 
	}
	int query(int lent){
		int p = 1;
		for(int i=1;i<=lent;i++){
			int c = ch[i]-'a';
			if(!son[p][c]) return 0;
			p = son[p][c];
		}
		return siz[p];
	}
}SAM;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		int lench = strlen(ch+1);
		for(int j=1;j<=lench;j++)
			s[++m] = ch[j]-'a';
		s[++m] = 26;
	}
	for(int i=1;i<=m;i++) SAM.insert(s[i]);
	SAM.build(); 
	int lent = 0;
	for(int i=1;i<=m;i++){
		if(s[i] != 26) ch[++lent] = s[i]+'a';
		else{
			printf("%d\n",SAM.query(lent));
			lent = 0;
		}
	}
	return 0;
} 