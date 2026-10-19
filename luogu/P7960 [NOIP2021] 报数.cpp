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
const int N = 1e7+114514+1919810;
bool vis[N];
bool chk(int x){
    while(x){
        if(x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
int ans[N];
inline void init(int n = 1e7+114514){
    int lst = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(chk(i)){
            for(int j=i;j<=n;j+=i) vis[j] = true;
        }else{
            ans[lst] = i;
            lst = i;
        }
    }
}
signed main(){
    // freopen("number.in","r",stdin);
    // freopen("number.out","w",stdout);
    init();
    int T = read();
    while(T--){
        int x = read();
        printf("%d\n",vis[x] ? -1 : ans[x]);
    }
    return 0;
}