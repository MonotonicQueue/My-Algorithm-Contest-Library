#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e5+10;
int n; 
struct Trie{
	int fa[N],t[N][26],c[N],from[N],cnt[N],tot;
	Trie(){tot = 1;}
	void insert(char ch[],int fr){
		int len = strlen(ch+1),p = 1;
		for(int i=1;i<=len;i++){
			int v = ch[i]-'a';
			if(!t[p][v]) t[p][v] = ++tot,c[tot] = v,fa[tot] = p;
			p = t[p][v]; from[p] = fr; cnt[p]++;
		}
	}
}T;

struct Suffix_Automation{
	int fa[N],son[N][26],len[N],tot,lst,cnt[N];
	Suffix_Automation(){tot = lst = 1;} 
	inline int insert(int c,int lst){
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
		return cur;
	}
	int pos[N]; queue<int> Q;
	void build(){
		for(int i=0;i<26;i++) if(T.t[1][i]) Q.push(T.t[1][i]);
		pos[1] = 1;
		while(!Q.empty()){
			int x = Q.front(); Q.pop();
			pos[x] = insert(T.c[x],pos[T.fa[x]]);
			for(int i=0;i<26;i++) if(T.t[x][i]) Q.push(T.t[x][i]);
		}
	}
	int siz[N],pre[N];
	int query(char s[]){
		int len = strlen(s+1),p = 1;
		for(int i=1;i<=len;i++){
			int c = s[i]-'a';
			if(!son[p][c]) return 0;
			p = son[p][c];
		}
		return siz[p];
	}
	void update(int x,int y){
		for(;x&&pre[x]!=y;x=fa[x])
			siz[x]++,pre[x] = y;
	}
}SAM;
char ch[N],s[N];
int len[N],sum[N],tot;
int main(){
	int n,Q; scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		T.insert(ch,i); len[i] = strlen(ch+1);
		for(int j=1;j<=len[i];j++)
			sum[++tot] = ch[j]-'a';
	}
	SAM.build();
	tot = 0;
	for(int i=1;i<=n;i++)
		for(int j=1,x=1;j<=len[i];j++)
			SAM.update(x=SAM.son[x][sum[++tot]],i);
	while(Q--){
		scanf("%s",s+1);
		int x = SAM.query(s);
		if(!x){
			puts("0");
			continue;
		}else printf("%d\n",x);
	}
	return 0;
}
