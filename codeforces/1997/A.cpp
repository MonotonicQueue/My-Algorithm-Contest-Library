#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
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
int n;
char s[N];
void solve(){
	bool flag = false;
	for(int i=1;i<=n;i++){
		if(!flag && s[i] == s[i-1]){
			if(s[i] == 'a') cout << "b";
			else cout << "a";
			flag  = true;
		}
		cout << s[i];
	}
	if(!flag){
		if(s[n] == 'a') cout << 'b';
		else cout << 'a';
	}
	cout << "\n";
}
int main(){
	int T = read();
	while(T--){
		cin >> s+1;
		n = strlen(s+1);
		solve();
	}
	return 0;
}
