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

void solve(){
    int A = read(),B = read(),C = read(),D = read();
    if(A < 4) return puts("0"),void();
    int ans = 4;
    for(int i=0;i<=D;i++)
        for(int j=0;j*i<=D&&(i+j)<=min(B,C);j++)
            ans = max(ans,4+2*(i+j)+i*j);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}