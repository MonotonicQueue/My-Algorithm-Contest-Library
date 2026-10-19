#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e6+10;

void solve(){
	int n = read();
	if(n < 5) puts("-1");
	else{
		vector<int> ans;
		for(int i=1;i<=n;i+=2)
			if(i != 5) ans.push_back(i);
		ans.push_back(5); ans.push_back(4);
		for(int i=2;i<=n;i+=2)
			if(i != 4) ans.push_back(i);
		for(int x : ans) cout << x << " ";
		cout << "\n";
	}
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
