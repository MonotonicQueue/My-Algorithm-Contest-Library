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
const int N = 2e5+10;
int n,a[N];
void solve(){
	n = read();
	set<int> s;
	vector<int> v;
	for(int i=1;i<=n;i++){
		a[i] = read();
		if(s.find(a[i]) != s.end()){
			s.erase(a[i]);
			v.push_back(a[i]);
		}else s.insert(a[i]);
	}
	sort(v.begin(),v.end());
	if(v.size() < 4) return puts("NO"),void();
	puts("YES");
	int x = v[0],y = v[1],xx = v[v.size()-2],yy = v[v.size()-1];
	cout << x << " " << y << " " << xx << " " << y << " " << x << " " << yy << " " << xx << " " << yy << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}