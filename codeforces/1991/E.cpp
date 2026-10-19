#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 2e5+10;
int n,m;
vector<int> G[N],le,ri;
int col[N];
bool flag;
inline void clear(){
	for(int i=1;i<=n;i++) G[i].clear(),col[i] = -1;
}
void dfs(int x,int lst){
	for(int y : G[x]){
		if(flag) return ;
		if(y == lst) continue;
		if(col[y] == -1){
			col[y] = col[x]^1;
			dfs(y,x);
		}else if(col[y] == col[x]){
			flag = true;
			return ;
		}
	}
}
int main(){
	int T = read();
	while(T--){
		n = read(); m = read();
		clear();
		for(int i=1;i<=m;i++){
			int u = read(),v = read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		col[1] = 0; flag = false;
		dfs(1,0);
		if(flag){
			puts("Alice"); fflush(stdout);
			for(int i=1;i<=n;i++){
				cout << "1 2\n";
				fflush(stdout);
				int x = read(),y = read();
			}
		}else{
			puts("Bob"); fflush(stdout);
			le.clear(); ri.clear();
			for(int i=1;i<=n;i++)
				if(col[i] == 0) le.push_back(i);
				else ri.push_back(i);
			for(int i=1;i<=n;i++){
				int a = read(),b = read();
				if((a == 1 || b == 1) && !le.empty()){
					cout << le.back() << " 1" << endl;
					le.pop_back();
				}else if((a == 2 || b == 2) && !ri.empty()){
					cout << ri.back() << " 2" << endl;
					ri.pop_back();
				}else{
					if(!le.empty()){
						cout << le.back() << " 3" << endl;
						le.pop_back();
					}else{
						cout << ri.back() << " 3" << endl;
						ri.pop_back();
					}
				}
			}
		}
	}
	return 0;
}
