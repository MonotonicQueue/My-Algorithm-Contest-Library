#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define ll long long 
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 110;
int n,a[N],t[N],mx,mn;
#define YES return puts("Possible"),0;
#define NO return puts("Impossible"),0;
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) t[a[i]]++;
	mx = mn = a[1];
	for(int i=2;i<=n;i++){
		mx = max(mx,a[i]);
		mn = min(mn,a[i]);
	}
	if(mn != (mx+1)/2) NO;
	if(!(mx & 1) && t[mn] != 1) NO;
	if((mx & 1) && t[mn] != 2) NO;
	for(int i=mn+1;i<=mx;i++)
		if(t[i] < 2) NO;
	YES;
    return 0;
}
