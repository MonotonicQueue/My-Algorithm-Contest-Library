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
string s;
bool chk(){
	int len = s.size();
	if(s[0] != '1') return false;
	if(s[len-1] == '9') return false;
	ll n = 0;
	for(int i=len-1;~i;i--){
		int x = s[i]-'0'+10-(i!=len-1);
		if(x < 10) return false;
	}
	return true;
}
int main(){
	int T = read();
	while(T--){
		cin >> s;
		puts(chk() ? "YES" : "NO");
	}
	return 0;
}
