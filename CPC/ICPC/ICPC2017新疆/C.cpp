#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 1600;
int n,a[N][N];
int mx[N][N],rk[N][N];
char c[N][N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            cin >> a[i][j] >> c[i][j];
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(mx[i-1][j-1] < mx[i-1][j]) rk[i][j] = rk[i-1][j];
            else if(mx[i-1][j-1] > mx[i-1][j]) rk[i][j] = rk[i-1][j-1];
            else rk[i][j] = min(rk[i-1][j-1],rk[i-1][j]);
            mx[i][j] = max(mx[i-1][j-1],mx[i-1][j])+a[i][j];
        }
        vector<int> p;
        for(int j=1;j<=i;j++) p.push_back(j);
        auto cmp = [&](int x,int y){
            if(c[i][x] != c[i][y]) return c[i][x] < c[i][y];
            if(rk[i][x] != rk[i][y]) return rk[i][x] < rk[i][y];
            return x < y;
        };
        sort(p.begin(),p.end(),cmp);
        for(int j=0;j<i;j++) rk[i][p[j]] = j;
    }
    vector<int> ans;
    int mxx = 0;
    for(int i=1;i<=n;i++){
        mxx = max(mxx,mx[n][i]);
    }
    for(int i=1;i<=n;i++) if(mxx == mx[n][i]) ans.push_back(i);
    sort(ans.begin(),ans.end(),[](int x,int y){return rk[n][x] != rk[n][y] ? rk[n][x] < rk[n][y] : x < y;});
    for(int x : ans) cout << x << " ";
    cout << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}