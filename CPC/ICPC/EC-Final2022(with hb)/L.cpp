#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1010;
int n,m;
int a[N][N];
struct node{
	int cnt;
	vector<vector<int>> a;
	void init(){
		cnt = 0;
		a.resize(n+1);
		for(int i=1;i<=n;i++) a[i].resize(m+1);
	}
	void calc(){
		cnt = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cnt += a[i][j];
	}
	void print(bool tp){
		calc();
		cout << cnt << "\n";
		if(!tp){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++) cout << a[i][j];
				cout << "\n";
			}
		}else{
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++)
					cout << a[j][i];
				cout << "\n";
			}
		}
	}
};


void solve(){
	n = read(); m = read();
	if(n <= 3 && m <= 3){
		node ans; ans.init();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) ans.a[i][j] = 1;
		ans.print(0);
		return ;
	}
	bool flag = false;
	if(n > m) swap(n,m),flag = true;
	if(n == 2){
		node ans; ans.init();
		for(int i=1;i<=m;i++){
			if(i & 1) ans.a[1][i] = ans.a[2][i] = 1;
			else if(i % 4 == 2) ans.a[2][i] = 1;
			else ans.a[1][i] = 1;
		}
		ans.print(flag);
	}else if(n == 3){
		node ans; ans.init();
		for(int i=1;i<=m;i++){
			if(i & 1) ans.a[1][i] = ans.a[2][i] = ans.a[3][i] = 1;
			else if(i % 4 == 2) ans.a[1][i] = ans.a[3][i] = 1;
			else ans.a[2][i] = 1;
		}
		ans.print(flag);
	}else{
		node ans; ans.init();
		if((n % 4 == 2 && m % 4 == 2) ||
		   (n % 4 == 1 && m % 4 == 1)){
			int b[4][4] = {1,1,0,1,
						   1,1,1,0,
						   1,0,1,1,
						   0,1,1,1};
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++) ans.a[i][j] = b[(i-1)%4][(j-1)%4];
		}else{
			int b[4][4] = {1,1,1,0,
						   1,0,1,1,
						   1,1,0,1,
						   0,1,1,1};
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++) ans.a[i][j] = b[(i-1)%4][(j-1)%4];
		}
		ans.print(flag);
	}
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}