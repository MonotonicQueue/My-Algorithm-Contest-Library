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
const int N = 110;
int n;
char s[N];
void solve(){
    n = read();
    scanf("%s",s+1);
    int mn = n,mx = 1,sum = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == '1') mn = min(mn,i),mx = max(mx,i),sum++;
    }
    if(mn == mx) puts("0");
    else if(sum == 2) puts("1");
    else cout << mx-mn << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}

