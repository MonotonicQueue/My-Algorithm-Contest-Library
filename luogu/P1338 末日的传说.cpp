#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 5e4+10;
int n,a[N]; ll m;
int main(){
    n = read(); m = read();
    int l = 0,r = n+1;
    for(int i=1;i<=n;i++){
        ll s = 1ll*(n-i)*(n-i-1)/2;
        if(s >= m) a[++l] = i;
        else a[--r] = i,m -= n-i;
    }
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    return 0;
}
