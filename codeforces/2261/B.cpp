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
const int N = 2e5+10;
int n,a[N];
void solve(){
    n = read(); 
    for(int i=1;i<=n;i++) a[i] = read();
    int mn = a[1],mx = a[1];
    for(int i=1;i<=n;i++) mn = min(mn,a[i]),mx = max(mx,a[i]);
    for(int i=30;~i;i--){
        if((mx >> i) != (mn >> i)){
            mx |= (1<<i)-1;
            break;
        }
    }
    cout << mx << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}

