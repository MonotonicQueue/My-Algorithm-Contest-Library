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
    map<char,int>mp;
    int cnt = 0;
    for(int i=1;i<=4;i++){
        char s; cin >> s;
        mp[s]++;
        if(mp[s] == 1) cnt++;
    }
    cout << cnt-1 << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}