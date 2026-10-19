#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
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
const int N = 1e6+10;
int n,m;
int pr[N],cnt,sum[N];
bool vis[N];
void init(int n = 1e6){
    for(int i=2;i<=n;i++){
        if(!vis[i]) pr[++cnt] = i;
        for(int j=1;j<=cnt&&pr[j]*i<=n;j++){
            vis[i*pr[j]] = true;
            if(i % pr[j] == 0) break;
        }
    }
    for(int i=2;i<=n;i++) sum[i] = sum[i-1]+(vis[i]^1);
}
int main(){
    n = read(); m = read();
    init(m);
    while(n--){
        int l = read(),r = read();
        if(l < 1 || r > m) puts("Crossing the line");
        else cout << sum[r]-sum[l-1] << "\n";
    }
    return 0;
}
