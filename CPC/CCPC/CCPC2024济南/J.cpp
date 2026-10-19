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
int n;
struct node{
    int x[3];
}a[N];
int b[N],tot;
void lsh(){
    for(int j=0;j<=2;j++){
        for(int i=1;i<=n;i++) b[i]= a[i].x[j];
        sort(b+1,b+1+n);
        tot = unique(b+1,b+1+n)-b-1;
        for(int i=1;i<=n;i++)
            a[i].x[j] = lower_bound(b+1,b+1+tot,a[i].x[j])-b;
    }
}
int cnt[N][3],flag[N];
vector<int> v[N][3];
set<pair<int,int>> s[3];
void solve(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i].x[0] = read();
        a[i].x[1] = read();
        a[i].x[2] = read();
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++)
            cnt[i][j] = 0,v[i][j].clear();
        flag[i] = 0;
    }
    s[0].clear(); s[1].clear(); s[2].clear();
    lsh();
    for(int i=1;i<=n;i++)
        for(int j=0;j<=2;j++){
            cnt[a[i].x[j]][j]++;
            v[a[i].x[j]][j].push_back(i);
        }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=2;j++)
            s[j].insert(mk(cnt[a[i].x[j]][j],a[i].x[j]));
    int ans = 0;
    for(int k=0;k<n;k++){
        queue<pair<int,int>> q;
        for(int j=0;j<=2;j++){
            while(!s[j].empty() && s[j].begin()->fi <= k){
                q.push(mk(j,s[j].begin()->se));
                s[j].erase(*s[j].begin());
            }
        }
        while(!q.empty()){
            int op = q.front().fi,x = q.front().se; q.pop();
            for(int y : v[x][op]){
                flag[y]++;
                if(flag[y] == 3){
                    ans++;
                    for(int j=0;j<=2;j++){
                        if(s[j].find(mk(cnt[a[y].x[j]][j],a[y].x[j])) != s[j].end()){
                            s[j].erase(mk(cnt[a[y].x[j]][j],a[y].x[j]));
                            cnt[a[y].x[j]][j]--;
                            if(cnt[a[y].x[j]][j] <= k) q.push(mk(j,a[y].x[j]));
                        }
                        
                    }
                }
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 