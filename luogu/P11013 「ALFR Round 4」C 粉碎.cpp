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
const int N = 5e5+10;
int n;
int pre[N],lst[N],a[N];
int sum[N],flag[N];
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) lst[i] = pre[i] = sum[i] = flag[i] = 0;
        for(int i=1;i<=n;i++){
            a[i] = read();
            pre[i] = lst[a[i]];
            lst[a[i]] = i;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(!pre[i] || sum[i-1]-sum[pre[i]-1]) flag[i] = 1;
            sum[i] = sum[i-1]+flag[pre[i]];
            if(flag[pre[i]]) ans = i;
        }
        cout << ans << "\n";
    }
    return 0;
}