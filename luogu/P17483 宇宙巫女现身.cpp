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
const int N = 1e5+10;
void solve(){
    int n = read(),m = 100;
    for(int i=1;i<=n;i++){
        int x = read(),y = read();
        m -= min(x,50);
        m = max(m,100);
        m += y;
        m = min(m,400);
    }
    cout << m << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}

