#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 3e5+10;
mt19937_64 rnd(time(0));
int n,m;
ull hsh[N];
unordered_map<ull,int> mp,mpi,mpj;
int main(){
	int T = read();
    while(T--){
		n = read(); m = read();
		for(int i=1;i<=n;i++) hsh[i] = rnd();
        vector<vector<int>> a(n+2);
		for(int i=1;i<=n;i++){
			a[i].resize(m+2);
			for(int j=1;j<=m;j++){
				char ch; cin >> ch;
				a[i][j] = ch-'0';
			}
		}
		mp.clear(); mpi.clear(); mpj.clear();
		int ans = 0; ull pos = 0;
		for(int j=1;j<=m;j++){
			ull sum = 0;
			for(int i=1;i<=n;i++) sum ^= a[i][j]*hsh[i];
			for(int i=1;i<=n;i++){
				ull now = sum^hsh[i];
				mp[now]++; mpi[now] = i; mpj[now] = j;
				if(mp[now] > ans) ans = mp[now],pos = now;
			}
		}
		cout << ans << "\n";
		int i = mpi[pos],j = mpj[pos];
		for(int k=1;k<=n;k++){
			if(i == k) cout << 1-a[k][j];
			else cout << (a[k][j] == 1);
		}
		cout << "\n";
    }
	return 0;
}

