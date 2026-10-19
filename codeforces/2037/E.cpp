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
ll ask(int l,int r){
	cout << "? " << l << " " << r << endl;
	return read();
}
void answer(string s){
	cout << "! " <<  s << endl;
}
void solve(){
	int n = read();
	string ans = "";
	if(ask(1,n) == 0) return answer("IMPOSSIBLE");
	ll lst = 0,sum = 0,pre = 0;
	for(int i=2;i<=n;i++){
		ll now = ask(1,i);
		if(now != lst){
			ll x = now-lst-sum;
			sum += x;
			ll len = i-pre-1;
			for(int j=1;j<=len-x;j++) ans += "1";
			for(int i=1;i<=x;i++) ans += "0";
			ans += "1";
			lst = now; pre = i;
		}
	}
	while(ans.size() != n) ans += "0";
	answer(ans);
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
