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
const int N = 3e5+10;
int n,h[N],stk[N],top;
int main(){
    ll ans = 0;
    n = read();
    for(int i=1;i<=n;i++){
        h[i] = read();
        while(top && h[stk[top]] < h[i]) ans += i-stk[top]+1,top--;
        if(top) ans += i-stk[top]+1;
        stk[++top] = i;
    }
    cout << ans;
	return 0;
} 