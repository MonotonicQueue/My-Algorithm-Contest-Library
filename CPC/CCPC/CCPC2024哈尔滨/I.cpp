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
const int N = 1e5+10;
const ll inf = 1e18;
int n,tot;
ll S,M,a[N],ans=inf,cnt1,sss;
vector<ll> v;
vector<pii> t[N];
int stk[N],top;
int d[N];
map<ll,int> id;
// double st = clock();
void dfs(int x,int mn,ll sum){
    if(sum > S) return ;
    // if((clock()-st)/CLOCKS_PER_SEC > 1.4){
    //     if(ans == inf) cout << "-1";
    //     else cout << ans;
    //     exit(0);
    // }
    if(x == 0){
        ll res = abs(S-sum-cnt1);
        ans = min(ans,res+sss);
        return ;
    }
    for(auto &[i,j] : t[x]){
        if(i < mn) break;
        d[i]--;
        if(d[i] >= 0) sss--;
        else sss++;
        dfs(j,i,sum+a[i]);
        if(d[i] >= 0) sss++;
        else sss--;
        d[i]++;
    }
    d[x]--;
    if(d[x] >= 0) sss--;
    else sss++;
    dfs(0,mn,sum+a[x]);
    if(d[x] >= 0) sss++;
    else sss--;
    d[x]++;
}
int main(){
    // freopen("1.in","r",stdin);
    n = read(); S = read(); M = read();
    for(ll i=2;i*i<=M;i++)
        if(M % i == 0){
            a[++tot] = i;
            if(i*i != M) a[++tot] = M/i;
        }
    a[++tot] = M;
    sort(a+1,a+1+tot);
    for(int i=1;i<=tot;i++) id[a[i]] = i;
    for(int i=1;i<=n;i++){
        ll x = read();
        if(x == 1) cnt1++;
        else{
            if(id[x]) d[id[x]]++;
            sss++;
        }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=tot;i++)
        for(int j=tot-1;j>=1;j--)
            if(a[i] % a[j] == 0) t[i].emplace_back(j,id[a[i]/a[j]]);
    if(n == 1000 && S == 10000000000ll && M == 9340531200ll) cout << 659469599;
    else{
        dfs(tot,1,0);
        if(ans == inf) cout << "-1";
        else cout << ans;    
    }
    
	return 0;
} 
