#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	ll X = 0 , f = 1;
	if(ch == '-') f = -1 , ch = getchar();
	while(isdigit(ch)) X = (X<<1)+(X<<3)+ch-'0' , ch = getchar();
	return X*f;
}

const int N = 1e6+10;
const int M = 2e6+10;
const int mod = 100003;
int n,m; 
vector<int>ver[N];
queue<int> q;
int deep[N] , ans[N];

int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int x,y;
		x = read(); y = read();
		if(x != y){
			ver[x].push_back(y);
			ver[y].push_back(x);
		}
	}
	q.push(1); deep[1] = 1; ans[1] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=0;i<ver[x].size();i++){
			int y = ver[x][i];
			if(!deep[y]){
				deep[y] = deep[x]+1;
				q.push(y);
			}
			if(deep[y] == deep[x]+1){
				ans[y] = (ans[x]+ans[y])%mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout << ans[i] << "\n";
	return 0;
}