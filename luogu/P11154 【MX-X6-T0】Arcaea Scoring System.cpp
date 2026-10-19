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
signed main(){
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    double t = 1e7/(a+b+c+d);
    int sum = a+t*(a+b+c/2.0);
    if(sum >= 9.9e6) cout << "EX+";
    else if(sum >= 9.8e6) cout << "EX";
    else if(sum >= 9.5e6) cout << "AA";
    else if(sum >= 9.2e6) cout << "A";
    else if(sum >= 8.9e6) cout << "B";
    else if(sum >= 8.6e6) cout << "C";
    else cout << "D";
    return 0;
}
