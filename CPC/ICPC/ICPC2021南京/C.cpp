#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 2e6+10;
const int K = 1e6;
int n,k;
int a[N];
map<int,int> mp;
vector<int> v[N];
int main(){
	n = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read();
	int ans = 0;
	for(int i=1;i<=n;i++){
		mp[a[i]]++;
		v[a[i]+K].push_back(i);
	}
	for(auto it : mp){
		int x = it.fi,cnt = it.se;
		ans = max(ans,cnt);
		if(k && mp.count(x-k)){
			vector<pii> c;
			for(int y : v[x+K]) c.emplace_back(y,-1);
			for(int y : v[x-k+K]) c.emplace_back(y,1);
			sort(c.begin(),c.end());
			int now = 0;
			for(auto it : c){
				now += it.se;
				if(now < 0) now = 0;
				ans = max(ans,cnt+now);
			}
		}
	}
	cout << ans;
    return 0;
}
