#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
ll n,k;
int main(){
	int T = read();
	while(T--){
		n = read(); k = read();
		if(k == 0) cout << "1\n";
		else cout << (n/k)-(n/(k+1)) << "\n";
	}	
    return 0;
}
