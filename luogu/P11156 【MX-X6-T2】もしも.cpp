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
const int N = 110+10;
ll n,an;
signed main(){
    int T = read();
    while(T--){
        n = read(); an = read();
        if(n % 2 == 0) cout << "1 " << an << "\n";
        else cout << an << " 1\n";
    }
    
    return 0;
}