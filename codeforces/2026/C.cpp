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
const int N = 4e5+10;
int n;
char s[N];
void solve(){
    n = read();
    scanf("%s",s+1);
    set<int> q1,q2;
    for(int i=1;i<=n;i++)
        if(s[i] == '1') q1.insert(i);
        else            q2.insert(i);
    ll ans = 0;
    while(!q1.empty()){
        int x = *q1.rbegin(); q1.erase(x);
        while(!q2.empty() && *q2.rbegin() > x) ans += *q2.rbegin(),q2.erase(*q2.rbegin());
        if(!q2.empty()) ans += *q2.rbegin(),q2.erase(*q2.rbegin());
        else if(!q1.empty()) ans += *q1.begin(),q1.erase(*q1.begin());
        else ans += x;
    }
    while(!q2.empty()) ans += *q2.rbegin(),q2.erase(*q2.rbegin());
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}
