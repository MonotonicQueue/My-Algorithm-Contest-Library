#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
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
char c[N];
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> c[i];
	int lst = 0,a = 0,b = 0,fi = 0;
	for(int i=1;i<=n;i++){
		if(c[i] == '.') continue;
		if(lst == 0){
			fi = i;
		}else if(c[lst] == 'a'){
			if(c[i] == 'a'){
				b++;
			}
		}else{
			if(c[i] == 'b'){
				a++;
			}
		}
		lst = i;
	}
	if(lst == 0){
		puts((n == 1) ? "alice" : "bob");
	}else{
		// cout << a << " " << b << "\n";
		int se = n-lst;
		if(fi == 2){
			if(c[fi] == 'a') b++;
			else a++;
		}
		if(fi <= 2 && se > 1){
			if(c[lst] == 'b') a++;
		}
		if(se == 1){
			if(c[lst] == 'a') b++;
			else a++;
		}
		if(se <= 1 && fi > 2){
			if(c[fi] == 'b') a++;
		}
		if(fi > 2 && se > 1){
			if(c[fi] == c[lst]){
				if(c[fi] == 'a') b++;
				else a++;
			}
		}
		puts((a > b) ? "alice" : "bob");
	}
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
