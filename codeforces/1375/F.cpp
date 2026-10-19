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
ll a[4];
int get(ll x){
    cout << x << endl;
    int k = read();
    if(k == 0) exit(0);
    a[k] += x;
    return k;
}
int main(){
    a[1] = read(); a[2] = read(); a[3] = read();
    puts("First");
    ll inf = 1e10;
    int k = get(inf);
    int kk = get(3*a[k]-a[1]-a[2]-a[3]);
    get(a[k]-a[(k^kk)]);
    return 0;
}
