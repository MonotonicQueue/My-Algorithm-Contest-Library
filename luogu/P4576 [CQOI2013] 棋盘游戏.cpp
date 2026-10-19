#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 25;
const int inf = 1e9;
const int dx[8] = {1,-1,0,0,2,-2,0,0};
const int dy[8] = {0,0,1,-1,0,0,2,-2};
int n;
int f[2][3*N][N][N][N][N];
int dfs(int op,int k,int r1,int r2,int c1,int c2){
	if(f[op][k][r1][r2][c1][c2]) return f[op][k][r1][r2][c1][c2];
	if(k > 3*n) return inf;
	if(r1 == c1 && r2 == c2) return op ? inf : 0;
	int ans;
	if(!op){
		ans = -1;
		for(int i=0;i<4;i++){
			int x = r1+dx[i],y = r2+dy[i];
			if(x < 1 || y < 1 || x > n || y > n) continue;
			ans = max(ans,dfs(1,k+1,x,y,c1,c2));
		}
	}else{
		ans = inf;
		for(int i=0;i<8;i++){
			int x = c1+dx[i],y = c2+dy[i];
			if(x < 1 || y < 1 || x > n || y > n) continue;
			ans = min(ans,dfs(0,k+1,r1,r2,x,y));
		}
	}
	return f[op][k][r1][r2][c1][c2] = ans+1;
}
int r1,r2,c1,c2;
int main(){
	n = read();
	r1 = read(); r2 = read(); c1 = read(); c2 = read();
	if(abs(r1-c1)+abs(r2-c2) == 1) printf("WHITE 1");
	else printf("BLACK %d",dfs(0,0,r1,r2,c1,c2));
	return 0;
}