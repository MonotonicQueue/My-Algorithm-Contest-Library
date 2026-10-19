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
const int N = 1e6+10;
int n,a,b;
void solve(){
    int cnt = 0;
    a = read(); b = read(); n = read();
    while(a <= n && b <= n){
        if(a < b) a += b;
        else b += a;
        cnt++;
    }
    cout << cnt << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}