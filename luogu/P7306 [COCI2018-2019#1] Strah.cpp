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
const int N = 2100;
int n,m;
char ch[N][N];
int s[N],top,h[N][N];
ll f(ll x){
    return x*(x+1)*(x+2)/6;
}
int main(){
    n = read(); m =  read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> ch[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(ch[i][j] == '#') h[i][j] = 0;
            else h[i][j] = h[i-1][j]+1;
    // for(int i=1;i<=n;i++,puts(""))
    //     for(int j=1;j<=m;j++) cout << h[i][j] << " ";
    ll ans = 0;
    for(int i=1;i<=n;i++){
        top = 0;
        for(int j=1;j<=m+1;j++){
            while(top && h[i][s[top]] >= h[i][j]){
                ll sum = (h[i][s[top]]+max(h[i][s[top-1]],h[i][j])+1)*(h[i][s[top]]-max(h[i][s[top-1]],h[i][j]))/2;
                ans += f(j-s[top-1]-1)*sum;
                top--;
            }
            s[++top] = j;
        } 
        // cout << ans << "\n";
    }
    cout << ans;
	return 0;
}
