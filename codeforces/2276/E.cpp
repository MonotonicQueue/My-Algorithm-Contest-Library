#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 3e5+10;
int n;
char s[N];
int g5[N],g6[N],nxt5[N],nxt6[N];
/*
对每个2找到最近的2026和2025
枚举起点 l
6后面都不好     id1
5后面没6就好    id2
r = id2~id1-1合法
l~id2          +=id1-id2
id2~id1        每层-1
*/
ll d[N],dd[N];
void solve(){
    n = read();
    scanf("%s",s+1);
    int lst0 = n+1,lst2 = n+1,lst5 = n+1,lst6 = n+1;
    for(int i=1;i<=n+1;i++){
        g5[i] = g6[i] = nxt5[i] = nxt6[i] = n+1;
        d[i] = dd[i] = 0;
    }
    for(int i=n;i;i--){
        if(s[i] == '0'){
            lst0 = i;
            g5[i] = g5[lst2];
            g6[i] = g6[lst2];
        }else if(s[i] == '2'){
            lst2 = i;
            g5[i] = lst5;
            g6[i] = lst6;
            nxt5[i] = g5[lst0];
            nxt6[i] = g6[lst0];
        }else if(s[i] == '5'){
            lst5 = i;
        }else if(s[i] == '6'){
            lst6 = i;
        }
    }
    for(int i=n;i;i--){
        nxt5[i] = min(nxt5[i],nxt5[i+1]);
        nxt6[i] = min(nxt6[i],nxt6[i+1]);
    }
    // for(int i=1;i<=n;i++){
    //     cout << nxt5[i] << " " << nxt6[i] << "\n";
    // }
    for(int i=1;i<=n;i++){
        int l = nxt5[i],r = nxt6[i];
        if(l > r) continue;
        d[i] += r-l; d[r+1] -= r-l;
        dd[l+1]--; dd[r+1] += r-l+1; dd[r+2] -= r-l;
    }
    for(int i=1;i<=n;i++) d[i] += d[i-1],dd[i] += dd[i-1];
    for(int i=1;i<=n;i++) dd[i] += dd[i-1];
    for(int i=1;i<=n;i++){
        // cout << d[i] << " " << dd[i] << "\n";
        ll ans = 1ll*i*(n-i+1)-d[i]-dd[i];
        cout << ans << " ";
    }
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
