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
const int N = 2010;
int ask(int l,int r){
	if(l >= r) return 0;
	cout << "? " <<  l << " " << r << endl;
	return read();
}
int pos[N],f[N][N],p[N];
int calc(int x,int y){
	int k = ask(x,y)-ask(x+1,y)-f[x][y-1];
	k = (k%2+2) % 2;
	return k;
}

void solve(int n){
	for(int i=1;i<=n;i++)
		pos[p[i]] = i;
	int l = 1,r = n,res = 0;
	
	while(l <= r){
		int mid = (l+r) >> 1;
		if(calc(pos[mid],n+1)) r = mid-1;
		else l = mid+1,res = mid;
	}

	for(int i=1;i<=n;i++)
		if(p[i] > res) p[i]++;
	p[n+1] = res+1;
	for(int i=1;i<=n;i++) f[i][n+1] = f[i][n]+(p[i] > p[n+1]);
}
int main(){
	p[1] = 1;
	int n = read();
	for(int i=2;i<=n;i++){
		solve(i-1);
	}
	cout << "! ";
	for(int i=1;i<=n;i++) cout << p[i] << " ";
	cout << endl;
	return 0;
}