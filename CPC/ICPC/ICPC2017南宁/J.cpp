#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
int n;
void solve(){
    n = read();
    int cnt0 = 0,cnt1 = 0,cnt2 = 0;
    for(int i=1;i<=2*n;i++){
        int x = read();
        if(x % 3 == 0) cnt0++;
        if(x % 3 == 1) cnt1++;
        if(x % 3 == 2) cnt2++;
    }
    if(cnt0 > n) puts("NO");
    else if(cnt1 > 0 && cnt2 > 0 && cnt0 < 2) puts("NO");
    else if(cnt1 > 0 && cnt2 > 0 && cnt0 == 2 && cnt1 % 2 == 0) puts("NO");
    else puts("YES");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
