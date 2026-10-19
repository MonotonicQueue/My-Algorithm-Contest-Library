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
const int N = 1e6+10;
int n;
int ct[1145]; char s[N];
int main(){
	int T = read();
	while(T--){
		n = read();
		cin >> (s+1);
		for(int i=0;i<4;i++) ct[i] = 0;
		int ans =0 ;
		for(int i=1;i<=4*n;i++){
			if(s[i] == '?') continue;
			if(ct[s[i]-'A'] != n) ans++,ct[s[i]-'A']++;
		}
		cout << ans << "\n";
	}
	return 0;
}
