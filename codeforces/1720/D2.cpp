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
const int N = 3e5+10;
int n,a[N],f[N],g[N];
int t[N*32][2],mx[N*32][2],cnt;
void insert(int x){
    int p = 1;
    for(int i=30;~i;i--){
        int c = ((x^a[x]) >> i) & 1;
        if(!t[p][c]) t[p][c] = ++cnt;
        p = t[p][c];
        mx[p][(a[x] >> i) & 1] = max(mx[p][(a[x] >> i) & 1],f[x]);
    }
}
int ask(int x){
    int p = 1,res = 0;
    for(int i=30;~i;i--){
        int c = ((x^a[x]) >> i) & 1;
        int y = c^1,j = (x >> i) & 1,k = (a[x] >> i) & 1;
        if(j < (k^y)) res = max(res,mx[t[p][y]][0]);
        if((j^1) < (k^y^1)) res = max(res,mx[t[p][y]][1]);
        p = t[p][c];
    }
    return res;
}
int main(){
    int T = read();
    while(T--){
        n = read();
        auto clear = [&](){
            for(int i=0;i<=cnt;i++)
                t[i][0] = t[i][1] = mx[i][0] = mx[i][1] = 0;
            for(int i=1;i<=n;i++) f[i] = 0;
            cnt = 1;
        };
        clear();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            a[i] = read();
            f[i] = ask(i)+1;
            ans = max(ans,f[i]);
            insert(i);
        }
        // g[0] = 1;
        // for(int i=1;i<n;i++){
        //     g[i] = 1;
        //     for(int j=0;j<i;j++)
        //         if((a[j] ^ i) < (a[i] ^ j)) g[i] = max(g[i],g[j]+1);
        // }
        // for(int i=0;i<n;i++) cout << g[i] << " ";
        // cout << "\n";
        // for(int i=0;i<n;i++) cout << f[i] << " ";
        // cout << "\n";
        cout << ans << "\n";
    }
    return 0;
}
/*
1
10
3 8 8 2 9 1 6 2 8 3
*/