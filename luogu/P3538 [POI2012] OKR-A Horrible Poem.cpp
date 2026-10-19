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
const int N = 5e5+10;
int n;
char s[N];
ull hsh[N],pw[N],P=1331;
ll get(int l,int r){
    return hsh[r]-hsh[l-1]*pw[r-l+1];
}
int d[N],pr[N],cnt;
void init(){
    for(int i=2;i<=n;i++){
        if(!d[i]) d[i] = pr[++cnt] = i;
        for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
            d[i*pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}
int main(){
    n = read();
    init();
    scanf("%s",s+1);
    pw[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*P;
    for(int i=1;i<=n;i++) hsh[i] = hsh[i-1]*P+s[i];
    int Q = read();
    while(Q--){
        int l = read(),r = read(),len = r-l+1;
        int ans = len;
        while(len > 1){
            if(get(l,r-ans/d[len]) == get(l+ans/d[len],r))
                ans /= d[len];
            len /= d[len];
        }
        cout << ans << "\n";
    }
    return 0;
}