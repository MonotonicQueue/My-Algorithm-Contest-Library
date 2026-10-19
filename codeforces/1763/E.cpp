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
const int N = 2e5+10;
const int mod = 1e9+7;
int n,f[N];
int main(){
    n = read();
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j*(j-1)/2<=i;j++)
            f[i] = min(f[i],f[i-j*(j-1)/2]+j);
    ll m = f[n];
    cout << f[n] << " " << m*(m-1)/2-n << "\n";
    return 0;
}