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
int solve(){
    int x = read(),y = read(),k = read();
    while(x != 1){
        int t = y-x%y;
        if(k < t)
            return x+k;
        x += t;
        while(x % y == 0) x /= y;
        k -= t;
    }
    return x+k%(y-1);
}
int main(){
    int T = read();
    while(T--) cout << solve() << "\n";
    return 0;
}
