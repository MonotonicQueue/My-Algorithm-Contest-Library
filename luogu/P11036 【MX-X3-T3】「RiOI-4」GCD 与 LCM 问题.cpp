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
int main(){
    int T = read();
    while(T--){
        ll a = read();
        for(ll i=1;;i*=2)
            if(a+i+a+i == i*(a+i)/__gcd(i,a+i)){
                cout << "1 " << a+i << " " << i << "\n";
                break;
            }
    }
    return 0;
}