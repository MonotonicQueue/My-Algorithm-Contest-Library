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
const int N = 1e5+10;
const int M = 1e6+10;
int n,m,TTT;
char s[M];
struct node{
    int fail,dep;
    bool end;
    unordered_map<int,int> son;
}t[N]; int rt;
int lst[200],pre[M];
void trans(){
    for(char c='A';c<='Z';c++) lst[c] = 0;
    m = strlen(s+1);
    for(int i=1;i<=m;i++){
        if(!lst[s[i]]) pre[i] = 0;
        else pre[i] = i-lst[s[i]];
        lst[s[i]] = i;
    }
    // for(int i=1;i<=m;i++) cout << pre[i];
    // cout << "\n";
}
void insert(){
    int p = 0;
    for(int i=1;i<=m;i++){
        if(!t[p].son[pre[i]]) t[p].son[pre[i]] = ++rt,t[rt].dep = t[p].dep+1;
        p = t[p].son[pre[i]];
    }
    t[p].end = 1;
}
int find(int x,int v){
    while(true){
        int y = v;
        // cout << x << "\n";
        if(y > t[x].dep) y = 0;
        auto it = t[x].son.find(y);
        if(it != t[x].son.end()) return it->se;
        if(x == 0) return 0;
        x = t[x].fail;
    }
}
void getFail(){
    queue<int> q;
    for(auto p : t[0].son) q.push(p.se);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto [i,y] : t[x].son){
            t[y].fail = find(t[x].fail,i);
            t[y].end |= t[t[y].fail].end;
            q.push(y);
        }
    }
}
bool chk(){
    trans();
    int p = 0;
    for(int i=1;i<=m;i++){
        p = find(p,pre[i]);
        if(t[p].end) return true;
    }
    return false;
}
void solve(){
    ++TTT;
    for(int i=0;i<=rt;i++){
        t[i].son.clear();
        t[i].fail = t[i].end = t[i].dep = 0;
    } rt = 0;
    n = read();
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        trans();
        insert();
    }
    getFail();
    int Q = read();
    printf("Case #%d: ",TTT);
    while(Q--){
        scanf("%s",s+1);
        if(chk()) cout << "Y ";
        else  cout << "N ";
    }
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
