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
int n,a[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int cnt1 = 0,cnt2 = 0;
    for(int i=1;i<=n;i++){
        if(a[i] & 1) cnt1++;
        else cnt2++;
    }
    if((cnt1 == 1 && cnt2 == 1) || (cnt1 == 3 && cnt2 == 0)) puts("Larpity");
    else puts("Moggity");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}

