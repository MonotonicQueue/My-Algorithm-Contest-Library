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
    int n = read();
    if(n % 2 == 0){
        for(int i=n;i>=3;i--) cout << "3";
        cout << "66\n";
        return ;
    }
    if(n <= 3) return puts("-1"),void();
    for(int i=n;i>5;i--) cout << "3";
    cout << "36366\n";
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}
