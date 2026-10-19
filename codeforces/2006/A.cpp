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
const int N = 1e6+10;
int n;
bool flag[N];
char s[N];
vector<int> G[N],V;
void solve(){
    n = read();
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    scanf("%s",s+1);
    int cnt[2] = {0,0},cntt = 0;
    for(int i=2;i<=n;i++)
        if(G[i].size() == 1){
            if(s[i] == '?') cntt++;
            else if(s[i] == '0') cnt[0]++;
            else cnt[1]++;
        }
    int sum = 0;
    for(int i=2;i<=n;i++) sum += s[i] == '?';
    int ans = 0;
    if(s[1] != '?'){
        ans = cnt[(s[1]-'0')^1]+(cntt+1)/2;
    }else{
        ans = max(cnt[1],cnt[0])+cntt/2;
        if(cnt[1] == cnt[0] && ((sum-cntt) & 1)) ans = max(ans,cnt[1]+(cntt+1)/2);
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
6
1 2
2 3
3 4
5 3
3 6
?0????
*/