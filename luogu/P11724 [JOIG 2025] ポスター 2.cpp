#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 300;
int n,k,a[N][N];
int chk(int i,int j){
	if(i < 1 || j < 1 || i >= n || j >= n) return 0;
	map<int,int> mp;
	mp[a[i][j]] = 1; mp[a[i+1][j]] = 1;
	mp[a[i][j+1]] = 1; mp[a[i+1][j+1]] = 1;
	return mp.size() >= 3;
}
int main(){
	n = read(); k = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) a[i][j] = read();
	int sum = 0;
	for(int i=1;i<n;i++) for(int j=1;j<n;j++) sum += chk(i,j);
	int ans = sum;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int t = a[i][j];
			int s = chk(i-1,j-1)+chk(i,j-1)+chk(i-1,j)+chk(i,j);
			if(k <= 8){
				for(int c=1;c<=k;c++){
					a[i][j] = c;
					ans = max(ans,sum+chk(i-1,j-1)+chk(i,j-1)+chk(i-1,j)+chk(i,j)-s);
				}
				a[i][j] = t;
			}else{
				a[i][j] = 1e9+1;
				ans = max(ans,sum+chk(i-1,j-1)+chk(i,j-1)+chk(i-1,j)+chk(i,j)-s);
				a[i][j] = t;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}