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
int ask(string s){
	cout << "1 " << s << endl;
	return read();
}
int answer(int x,int y){
	cout << "0 " << x << " " << y << endl;
	return read();
}
void solve(){
	n = read();
	int r1 = ask("0"),r2 = ask("00");
	int len = r1-r2;
	int r3 = ask("01");
	if(len == r3){
		answer(n,1);
	}else{
		answer(n,0);
	}
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}