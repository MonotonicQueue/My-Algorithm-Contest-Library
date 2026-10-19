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
int a,b,c,d;
int main(){
    int T = read();
    while(T--){
        cin >> a >> b >> c >> d;
        int ans = 0;
        if(a > c && b >= d) ans++;
        else if(b > d && a == c) ans++;
        if(a > d && b >= c) ans++;
        else  if(b > c && a == d) ans++;
        cout << ans*2 << "\n";
    }
    return 0;
}
