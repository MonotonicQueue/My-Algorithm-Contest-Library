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
const int N = 1010;
int n,Q;
int cnt[N][N][3];
int main(){
    n = read(); Q = read();
    int ans = 0;
    auto add = [&](int x,int y,int op){
        cnt[x][y][op]++;
        ans += (cnt[x][y][op] == n);
    };
    while(Q--){
        int x = read(),y = read(),z = read();
        add(x,y,0);
        add(x,z,1);
        add(y,z,2);
        cout << ans << "\n";
    }
    return 0;
}