#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair 
#define fi first
#define se second
#define ll long long
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
char ch[N];
int main(){
	int T = read();
	while(T--){
		int n = read();
		cin >> ch+1;
		int l = 1e9,r = -1e9;
		int pos = 0,now = 1;
		ch[0] = 't';
		for(int i=1;i<=n;i++){
			if(ch[i] == ch[i-1]) now *= -1;
			else pos += now;
			l = min(l,pos); r = max(r,pos);
		}
		cout << r-l+1 << "\n";
	}
	return 0;
}