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
const int N = 1e6+10;
int n,l[N],r[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++){
        l[i] = read();
        r[i] = read();
    }
    int mx = r[1],now = r[1],cnt = 1;
    for(int i=2;i<=n;i++){
        mx = max(mx,r[i]);
        if(l[i] > now){
            now = mx;
            cnt++;
        }
    }
    cout << cnt << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
