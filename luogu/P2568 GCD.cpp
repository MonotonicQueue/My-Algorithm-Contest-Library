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
const int N = 1e7+10;
int n;
int pr[N],cnt;
bool flag[N];
ll phi[N];
void init(){
    phi[1] = 1;
    for(int i=2;i<=n;i++){
        if(!flag[i]){
            pr[++cnt] = i;
            phi[i] = i-1;
        }
        for(int j=1;j<=cnt&&pr[j]*i<=n;j++){
            flag[i*pr[j]] = true;
            if(i % pr[j] == 0){
                phi[i*pr[j]] = phi[i]*pr[j];
                break;
            }
            phi[i*pr[j]] = phi[i]*phi[pr[j]];
        }
    }
    for(int i=1;i<=n;i++) phi[i] += phi[i-1];
}
int main(){
    n = read();
    init();
    ll ans = 0;
    for(int i=1;i<=cnt;i++)
        ans += 2*phi[n/pr[i]]-1;
    cout << ans;
    return 0;
}
