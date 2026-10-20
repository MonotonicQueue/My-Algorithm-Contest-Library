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
ll m,n;
int main(){
    n = read(); m = read();
    n = (n+1)/2; m = (m+1)/2;
    if(n % 2 == 1 && (n+1)/2 == m) cout << "0";
    else cout << min(m,n-m+1);
    return 0;
}
