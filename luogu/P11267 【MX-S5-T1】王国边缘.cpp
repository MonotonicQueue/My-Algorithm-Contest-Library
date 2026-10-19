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
const int mod = 1e9+7;
ll n,m;
ll f[N][62],g[N][62];
char ch[N];
int get(ll x){
    if(x % n) return x % n;
    return n;
}
void init(){
    bool flag = false;
    for(int i=1;i<=n;i++)
        if(ch[i] == '1') flag = true;
    if(!flag){
        for(int i=1;i<=n;i++)
            f[i][0] = get(i+1),g[i][0] = 1;
    }else{
        if(m < n){
            deque<int> q;
            for(int i=2;i<=m;i++)
                if(ch[i] == '1') q.push_back(i);
            for(int i=1,j=m+1;i<=n;i++,j++){
                if(!q.empty() && q.front() == i) q.pop_front();
                if(ch[get(j)] == '1') q.push_back(j);
                if(!q.empty()) f[i][0] = get(q.back()),g[i][0] = q.back()-i;
                else f[i][0] = get(i+1),g[i][0] = 1; 
            }
        }else{
            ll lstf = 0,lstg = 0;
            for(ll i=m;~i;i--){
                if(ch[get(i)] == '1'){
                    lstf = get(i);
                    lstg = i%mod;
                    break;
                }
            }
            for(ll i=1,j=m+1;i<=n;i++,j++){
                if(ch[get(j)] == '1'){
                    lstf = get(j);
                    lstg = j%mod;
                }
                f[i][0] = lstf; g[i][0] = (lstg-i+mod)%mod;
            }
        }
    }
    for(int j=1;j<=60;j++){
        for(int i=1;i<=n;i++){
            f[i][j] = f[f[i][j-1]][j-1];
            g[i][j] = (g[i][j-1]+g[f[i][j-1]][j-1])%mod;
        }
    }
}
int main(){
    n = read(); m = read();
    int Q = read();
    scanf("%s",ch+1);
    init();
    while(Q--){
        ll s = read(),k = read();
        ll ans = s%mod; s = get(s);
        for(int i=60;~i;i--){
            if((k >> i) & 1){
                ans = (ans+g[s][i])%mod;
                s = f[s][i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
