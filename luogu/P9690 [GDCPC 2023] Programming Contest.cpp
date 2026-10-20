#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define mk make_pair
#define pii pair<int,int>
#define ull unsigned ll
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch)) ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 110;
int n;
bool vis[10100];
void solve(){
    memset(vis,0,sizeof(vis));
    int st = read();
    n = read();
    for(int i=1;i<=n;i++){
        int x = read();
        vis[x] = true;
    }
    int ed = read();
    int cnt = 0;
    for(int i=st;i<=ed;i++)
        cnt += !vis[i];
    cout << cnt << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}