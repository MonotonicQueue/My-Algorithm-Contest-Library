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
const int N = 3e5+10;
int n,m;
char s[N];
void solve(){
    scanf("%s",s+1);
    n = strlen(s+1);
    int ans = 1,f1 = 0,f2 = 0;
    
    for(int i=2;i<n;i++){
        if(s[i-1] != s[i] && s[i] != s[i+1]) f1 = 1;
        if(s[i-1] == s[i] && s[i] == s[i+1]) f2 = 1;
    }
    cout << ans+f1+f2 << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
