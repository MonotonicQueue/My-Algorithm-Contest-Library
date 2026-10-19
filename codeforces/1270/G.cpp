#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int n,a[N];
vector<int> G[N],ans;
int stk[N],top;
bool vis[N],flag;
void dfs(int x){
	if(vis[x]){
		int z;
		do{
			z = stk[top--];
			ans.push_back(z);
		}while(z != x);
		flag = true;
		return ;
	}
	stk[++top] = x;
	vis[x] = true;
	for(int y : G[x]){
		dfs(y);
		if(flag) return ;
	}
	top--;
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) G[i].clear(),vis[i] = false;
		ans.clear(); flag = false; top = 0;
		for(int i=1;i<=n;i++){
			a[i] = read();
			G[i].push_back(i-a[i]);
		}
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				dfs(i);
				if(flag) break;
			}
		printf("%d\n",int(ans.size()));
		for(int y : ans) printf("%d ",y);
		printf("\n");
	}
	
    return 0;
}
