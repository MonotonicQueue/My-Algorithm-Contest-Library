#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1510;
const int mod = 1e9+7;
int m,tot,num[N];
struct Node{
	int son[10];
	int end,fail;
}t[N];
void insert(char ch[]){
	int n = strlen(ch+1),p = 0;
	for(int i=1;i<=n;i++){
		int c = ch[i]-'0';
		if(!t[p].son[c]) t[p].son[c] = ++tot;
		p = t[p].son[c];
	}
	t[p].end++; 
}
void getFail(){
	queue<int>q;
	for(int i=0;i<10;i++) if(t[0].son[i]) q.push(t[0].son[i]);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=0;i<10;i++)
			if(t[x].son[i]){
				t[t[x].son[i]].fail = t[t[x].fail].son[i];
				q.push(t[x].son[i]);
				t[x].end |= t[t[x].fail].end;
			}else t[x].son[i] = t[t[x].fail].son[i];
	}
}
int n;
ll f[2][N][2];
void work(){
	for(int i=1;i<=num[1];i++)
		if(!t[t[0].son[i]].end) f[1][t[0].son[i]][i==num[1]]++;
	for(int i=2;i<=n;i++){
		memset(f[i&1],0,sizeof(f[i&1]));
		for(int j=1;j<=9;j++)
			if(!t[t[0].son[j]].end)
				f[i&1][t[0].son[j]][0]++;
			
		for(int j=0;j<=tot;j++){
			if(t[j].end) continue;
			for(int k=0;k<=9;k++){
				int y = t[j].son[k];
				if(!t[y].end)
					f[i&1][y][0] = (f[i&1][y][0]+f[(i-1)&1][j][0])%mod;
			}
			for(int k=0;k<=num[i];k++){
				int y = t[j].son[k];
				if(!t[y].end)
					f[i&1][y][k==num[i]] = (f[i&1][y][k==num[i]]+f[(i-1)&1][j][1])%mod;
			}
		}
		
	}
	ll ans = 0;
	for(int i=0;i<=tot;i++)
		if(!t[i].end)
			ans = (ans+f[n&1][i][0]+f[n&1][i][1])%mod;
	printf("%lld",ans);
}
char ch[N],s[N];
int main(){
	scanf("%s%d",s+1,&m);
	n = strlen(s+1);
	for(int i=1;i<=m;i++){
		scanf("%s",ch+1);
		insert(ch);
	}
	getFail();
	for(int i=1;i<=n;i++) num[i] = s[i]-'0';
	work();
	return 0;
} 