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

void solve(){
	string s;
	cin >> s;
	int x = s[0],y = s[2];
	if(x < y) s[1] = '<';
	else if(x > y) s[1] = '>';
	else s[1] = '=';
	cout << s << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}