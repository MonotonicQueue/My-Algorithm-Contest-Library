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
int n,a[N][2];
void solve(){
    n = read();
    for(int i=1;i<=n+2;i++)
        a[i][0] = a[i][1] = 0;
    ll cnt1 = 0,cnt2 = 0,ans = 0;
    for(int i=1;i<=n;i++){
        int x = read()+1,y = read();
        a[x][y]++;
        if(y == 0) cnt1++;
        else cnt2++;
    }
    for(int i=1;i<=n+1;i++){
        if(a[i][0] && a[i][1]) ans += cnt1+cnt2-2;
        for(int j=0;j<2;j++)
            if(a[i][j] && a[i-1][j^1] && a[i+1][j^1]) ans++; 
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
