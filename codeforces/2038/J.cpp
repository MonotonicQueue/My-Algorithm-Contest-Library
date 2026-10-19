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
int n;
int main(){
	n = read();
	int now = 0;
	while(n--){
		char op; cin >>op;
		int x = read();
		if(op == 'P'){
			now += x;
		}else{
			if(x > now) cout << "YES\n";
			else cout << "NO\n";
			now = max(0,now-x);
		}
	}
    return 0;
}