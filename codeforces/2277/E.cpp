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
const int N = 510;
int n,p[N];
void work(int x,int y){
    p[x] = n-1;
    p[y] = n;
    int cnt = 1;
    for(int i=1;i<=n;i++)
        if(i != x && i != y) p[i] = cnt++;
    cout << "? ";
    cout << x << " ";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << "\n";
    fflush(stdout);
}
void work2(int rt){
    cout << "? " << rt << " ";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << "\n";
    fflush(stdout);
}
int siz[N];
vector<int> G[N];
void solve(){
    n = read();
    for(int i=2;i<=n;i++){
        work(1,i);
        siz[i] = read()-(n-1)*n;
    }
    for(int i=1;i<=n;i++) G[i].clear();
    vector<int> V;
    for(int i=1;i<=n;i++) V.push_back(i);
    siz[1] = n;
    sort(V.begin(),V.end(),[](int x,int y){return siz[x] > siz[y];});
    for(int i=1;i<n;i++){
        int x = V[i];
        p[x] = 1;
        queue<int> q; q.push(1);
        int cnt = 1;
        while(!q.empty()){
            int x = q.front(); q.pop();
            p[x] = ++cnt;
            for(int y : G[x]){
                q.push(y);
            }
        }
        for(int j=i+1;j<n;j++) p[V[j]] = j+1;
        work2(x);
        int val = read();
        val -= (i+1+n)*(n-i)/2;
        for(int j=0;j<i;j++){
            int c = p[V[j]];
            if(val == (c-1)*i+(i-c+2)*(i-c+1)/2){
                G[V[j]].emplace_back(x);
            }
        }
            
    }
    cout << "! ";
    for(int i=1;i<=n;i++)
        for(int x : G[i]) cout << i << " " << x << "\n";
    fflush(stdout);
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}