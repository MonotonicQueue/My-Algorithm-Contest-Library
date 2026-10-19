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
    int l = read(),r = read();
    if(l % 2 == 0) l++;
    int len = (r-l+2)/2;
    cout << len/2 << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
