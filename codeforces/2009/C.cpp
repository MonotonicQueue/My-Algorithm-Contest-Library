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
void solve(){
    int x = read(),y = read(),k = read();
    if(x) x = (x-1)/k+1;
    if(y) y = (y-1)/k+1;
    cout << max(2*x-1,2*y) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
