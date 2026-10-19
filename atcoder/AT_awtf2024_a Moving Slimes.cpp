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
const int N = 2.5e5+10;
int n,k,a[N];
double sum[N],ans;
int main(){
    n = read(); k = read();
    for(int i=1;i<=n;i++){
        a[i] = read();
        sum[i] = a[i]+sum[i-1];
    }
    for(int i=1;i<k;i++)
        ans = max(ans,-1.0*sum[i]/i+1.0*(sum[n]-sum[n-k+i])/(k-i));
    printf("%.10lf",ans/k);
    return 0;
}
