#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int read(){
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	return ch-'0';
}

void solve(){
	int T = 3;
	while(T--){
		int x = read();
		if(x & 4) cout << "r";
		else cout << "-";
		if(x & 2) cout << "w";
		else cout << "-";
		if(x & 1) cout << "x";
		else cout << "-";
	}
	cout << "\n";
}
int main(){
	int T; cin >> T;
	while(T--) solve();
	return 0;
}