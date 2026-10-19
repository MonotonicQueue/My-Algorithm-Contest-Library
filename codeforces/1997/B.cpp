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
char s[3][N];
int main(){
	int T = read();
	while(T--){
		n = read();
		cin >> s[0]+1 >> s[1]+1;
		int cnt = 0;
		for(int op=0;op<=1;op++)
		for(int i=1;i<=n;i++){
			if(s[op][i] == '.' && s[op][i-1] == 'x' && s[op][i+1] == 'x' && s[op^1][i] == '.' &&
			s[op^1][i-1] == '.' && s[op^1][i+1] == '.')
				cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}
