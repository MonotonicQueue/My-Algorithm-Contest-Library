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
const int N = 2e5+10;
int n;
char s[N];
int main(){
	int T = read();
	while(T--){
		n = read();
		cin >> s+1;
		ll ans = 0;
		for(int i=n;i>=1;){
			if(s[i] == ')'){
				int j = i-2;
				while(s[j] == '(') ans++,j-=2;
				ans += i-j-1;
				i = j;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
(()())()()
*/