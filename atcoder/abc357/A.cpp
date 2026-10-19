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
const int N = 110;
int n,m;
int h[N];
int main(){
	n = read(); m = read();
    for(int i=1;i<=n;i++) h[i] = read();
    int i = 0;
    for(i=1;i<=n;i++){
        if(m >= h[i]) m -= h[i];
        else break;
    }
    cout << i-1;
	return 0;
}
