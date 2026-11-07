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
const int N = 1010;
int n;
int a[N][N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) a[i][j] = 0;
    for(int k=n;k;k--){
        for(int i=k;i<=n;i+=k)
            for(int j=k;j<=n;j+=k)
                if(!a[i][j]) a[i][j] = k;
    }
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++) cout << a[i][j] << " ";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
