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
const int inf = 1e9;
int n,m;
ll ans;
void dfs(int a,int b,int c,int d,int v){
    ans += max(0,min(a ? (n-b)/a : inf,(m-d)/c)-v+1);
    ans += max(0,(n-d)/c-v+1);
    for(int u=1;;u++){
        ll A = a+2*u*c,B = b+2*u*d;
        if(A*max(u,v)+B > m) break;
        dfs(c,d,A,B,max(u,v));
    }
}
void dfs0(int a,int b,int v){
    for(int u=1;;u++){
        ll c = a+2*u*b;
        if(b+2*c*max(u+1,v) > m) break;
        dfs0(b,c,max(u+1,v));
    }
    dfs(0,b,2*b,a,v);
}
int main(){
    n = read(); m = read();
    if(n > m) swap(n,m);
    dfs0(0,1,1);
    cout << ans;
	return 0;
}
