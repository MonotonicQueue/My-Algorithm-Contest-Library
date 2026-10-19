#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1020;
struct Trie{
	int son[26];
	int fail,end;
}t[N]; 
int n,l,m,tot;
int ed[N];
double p[N],q[N]; 
double a[N][N];
inline void insert(char ch[],int id){
	int p = 0;
	for(int i=1;i<=l;i++){
		int c = ch[i]-'A';
		if(!t[p].son[c]) t[p].son[c] = ++tot;
		p = t[p].son[c];
	}
	t[p].end = id; ed[id] = p;
}
void getFail(){
	queue<int>Q;
	for(int i=0;i<26;i++)
		if(t[0].son[i]) Q.push(t[0].son[i]);
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i=0;i<26;i++)
			if(t[x].son[i]){
				t[t[x].son[i]].fail = t[t[x].fail].son[i];
				Q.push(t[x].son[i]);
			}else t[x].son[i] = t[t[x].fail].son[i];
	}
}
double ans[N];
void guass(int cnt){
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++)
			if(fabs(a[j][i]) > fabs(a[i][i])) swap(a[i],a[j]);
		for(int j=cnt+1;j>=i;j--) a[i][j] /= a[i][i];
		for(int j=1;j<=cnt;j++)
			if(i != j)
			for(int k=cnt+1;k>=i;k--)
				a[j][k] -= a[j][i]*a[i][k];
	}
	for(int i=1;i<=n;i++)
		printf("%.2lf\n",max(a[ed[i]+1][cnt+1],0.00));
}
void build(){
	for(int i=0;i<=tot;i++)
		if(!t[i].end)
			for(int j=0;j<m;j++)
				a[t[i].son[j]+1][i+1] += p[j+1]*1.0/q[j+1];
	for(int i=1;i<=tot+1;i++) a[i][i] -= 1;
	a[1][tot+2] = -1;
	guass(tot+1);
}
char ch[N];
int main(){
	n = read(); l = read(); m = read();
	for(int i=1;i<=m;i++){
		p[i] = read(); q[i] = read();
		if(!p[i]) p[i] = 0.000001;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		insert(ch,i);
	}
	getFail(); build();
	
	return 0;
} 