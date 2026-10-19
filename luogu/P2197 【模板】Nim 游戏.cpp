#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}

int main(){
	int T = read();
	while(T--){
		int n = read(),ans = 0;
		for(int i=1;i<=n;i++) ans ^= read();
		puts(ans ? "Yes" : "No");
	}
	return 0;
}
