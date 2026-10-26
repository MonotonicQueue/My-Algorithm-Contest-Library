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
const int N = 1e5+10;
int n,k,a[N];
bool s[N];
void solve(){
	n = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read();
	int cnt = 0;
	vector<int> v;
	for(int i=1;i<=n;i++){
		if(a[i] != a[i-1]){
			v.push_back(i);
			cnt++;
		}
	}
	if(cnt > k){
		cout << "1\n";
		cout << v[cnt-k]-1 << " ";
		for(int i=1;i<=v[cnt-k]-1;i++) cout << i << " ";
		cout << a[v[cnt-k]];
	}else if(cnt == k){
		cout << "0";
	}else{
		vector<pii> ans;
		int i=1;
		while(cnt+2 <= k){
			bool flag = false;
			for(;i<n;i++){
				if(a[i] == a[i-1] && a[i] == a[i+1]){
					flag = true;
					ans.push_back(mk(i,a[i]));
					for(int j=1;j<=n;j++)
						if(j != a[i-1] && j != a[i+1]){
							s[a[i]] = 1;
							a[i] = j;
							break;
						}
					
					cnt+=2;
					break;
				}
			}
			if(!flag) break;
		}
		i = 1;
		while(cnt < k){
			for(;i<=n;i++){
				if(a[i] == a[i-1] && a[i] != a[i+1]){
					ans.push_back(mk(i,a[i]));
					for(int j=1;j<=n;j++)
						if(j != a[i-1] && j != a[i+1]){
							s[a[i-1]] = s[a[i+1]] = 1;
							a[i] = j;
							break;
						}
					
					cnt++;
					break;
				}
			}
		}
		cout << 1 << "\n";
		cout << ans.size() << " ";
		for(auto [x,y] : ans){
			cout << x << " ";
		}
		for(int i=1;i<=n;i++)
			if(!s[i]){
				cout << i;
				break;
			}
	}
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}
