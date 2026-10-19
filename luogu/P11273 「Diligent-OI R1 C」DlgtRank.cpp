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
const int N = 2e5+10;
int n,pos[N],k;
ll a[N],ans[N];
int main(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) pos[i] = i;
    sort(pos+1,pos+1+n,[](int x,int y){return a[x] > a[y];});
    for(int i=2;i<=n;i++){
        int x = pos[i],lst = pos[i-1];
        if(a[lst] == a[x]) ans[x] = ans[lst];
        else{
            ans[x] = ans[lst]+1;
            ans[x] -= (a[lst]-a[x]-1)/k;
            ans[x] = max(ans[x],0ll);
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    return 0;
}
