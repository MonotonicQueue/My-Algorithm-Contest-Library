#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 1e4+10;
double f[N],g[N];
int main(){
    int n = read();
    for(int i=n-1;~i;i--){
        f[i] = f[i+1]+1.0*n/(n-i);
        g[i] = g[i+1]+1.0*n/(n-i)*f[i];
    }
    printf("%.2lf",g[0]);
	return 0;
}
