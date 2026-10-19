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
int n,a[N];
void solve(){
    n = read();
    if(n % 2 == 0){
        puts("-1");
        return ;
    }
    int mid = (n+1)/2;
    a[mid] = 1;
    for(int i=mid+1;i<=n;i++) a[i] = (i-mid)*2;
    for(int i=mid-1;i;i--) a[i] = (mid-i)*2+1;
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
