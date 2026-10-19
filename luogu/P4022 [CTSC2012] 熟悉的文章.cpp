#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll read(){
	ll X = 0,r = 1; char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){r = -1; ch = getchar();}
	while(isdigit(ch)){X = X*10+ch-'0'; ch = getchar();}
	return X*r;
} 
const int N = 1e6+10;
int mac[N];
struct Trie{
	int fa[N],t[N][2],c[N],tot;
	Trie(){tot = 1;}
	void insert(char ch[]){
		int p = 1,len = strlen(ch+1);
		for(int i=1;i<=len;i++){
			int v = ch[i]-'0';
			if(!t[p][v]) t[p][v] = ++tot,fa[tot] = p,c[tot] = v;
			p = t[p][v];
		}
	}
}T;
struct Suffix_Automation{
	int fa[N<<1],len[N<<1],son[N<<1][2],tot;
	Suffix_Automation(){tot = 1;}
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
		for(int i=0;i<2;i++) if(T.t[1][i]) Q.push(T.t[1][i]);
		pos[1] = 1;
		while(!Q.empty()){
			int x = Q.front(); Q.pop();
			pos[x] = insert(T.c[x],pos[T.fa[x]]);
			for(int i=0;i<2;i++) if(T.t[x][i]) Q.push(T.t[x][i]);
		}
	}
	void match(char ch[]){
		int p = 1,lenn = strlen(ch+1),res = 0;
		for(int i=1;i<=lenn;i++){
			int c = ch[i]-'0';
			if(son[p][c]) p = son[p][c],res++;
			else{
				for(;p&&!son[p][c];p=fa[p]);
				if(p) res = len[p]+1,p = son[p][c];
				else p = 1,res = 0;
			}
			mac[i] = res; 
		}
	}
}SAM;
int q[N],f[N];
bool chk(int L,int n){
	int l = 1,r = 0;
	for(int i=1;i<L;i++) f[i] = 0;
	for(int i=L;i<=n;i++){
		f[i] = f[i-1];
		while(l <= r && f[q[r]]-q[r] <= f[i-L]-i+L) r--;
		q[++r] = i-L;
		while(l <= r && q[l] < i-mac[i]) l++;
		if(l <= r) f[i] = max(f[i],f[q[l]]+i-q[l]);
	}
	return f[n]*10 >= n*9;
}
char ch[N];
int main(){
	int n = read(),m = read();
	for(int i=1;i<=m;i++){
		scanf("%s",ch+1);
		T.insert(ch);
	} SAM.build();
	while(n--){
		scanf("%s",ch+1); SAM.match(ch);
		int l = 0,r = strlen(ch+1),ans = 0,len = r;
		while(l <= r){
			int mid = (l+r)>>1;
			if(chk(mid,len)) l = mid+1,ans = mid;
			else r = mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}