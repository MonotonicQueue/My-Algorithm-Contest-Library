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
const int N = 3e4+10;
int n,m,a[N],op[N],ans[N];
struct node{int p,t;}b[N];
vector<int> G[N];
struct Stack{
    stack<node> s;
    vector<vector<int>> f;
    int query(int x){
        return f.empty() ? 0 : f.back()[x];
    }
    inline void push(node x){
        s.push(x);
        vector<int> g;
        if(f.empty()) g = vector<int>(2001);
        else g = f.back();
        for(int i=2000;i>=x.p;i--) g[i] = max(g[i],g[i-x.p]+x.t);
        f.push_back(g);
    }
    node top(){
        return s.top();
    }
    inline void pop(){
        s.pop(); f.pop_back();
    }
    int size(){
        return s.size();
    }
    bool empty(){
        return s.empty();
    }
};
struct mindeque{
    Stack L,R;
    int query(int x){
        int res = 0;
        for(int i=0;i<=x;i++)
            res = max(res,L.query(i)+R.query(x-i));
        return res;
    }
    void push_front(node x){
        L.push(x);
    }
    void push_back(node x){
        R.push(x);
    }
    void rebuild(){
        vector<node> a,b;
        while(!L.empty()) a.push_back(L.top()),L.pop();
        while(!R.empty()) b.push_back(R.top()),R.pop();
        while(!b.empty()) a.push_back(b.back()),b.pop_back();
        int siz = a.size() >> 1;
        for(int i=siz-1;~i;i--) L.push(a[i]);
        for(int i=siz;i<int(a.size());i++) R.push(a[i]);
    }
    void pop_front(){
        if(L.empty()) rebuild();
        if(L.empty()) R.pop();
        else          L.pop();
    }
    void pop_back(){
        if(R.empty()) rebuild();
        if(R.empty()) L.pop();
        else          R.pop();
    }
    node front(){
        if(L.empty()) rebuild();
        if(L.empty()) return R.top();
        else          return L.top();
    }
    node back(){
        if(R.empty()) rebuild();
        if(R.empty()) return L.top();
        else          return R.top();
    }
}q;
void dfs(int x){
    if(op[x] == 2){
        q.push_back(b[x]);
    }else if(op[x] == 3){
        b[x] = q.front();
        q.pop_front();
    }else if(op[x] == 4){
        ans[x] = q.query(b[x].p);
    }
    for(int y : G[x]) dfs(y);
    if(op[x] == 2){
        q.pop_back();
    }else if(op[x] == 3){
        q.push_front(b[x]);
    }
}
int main(){
    n = read();
    m = 1; a[1] = 0;
    for(int i=1;i<=n;i++){
        op[i] = read();
        int x = read();
        if(op[i] == 1){
            a[++m] = i;
            G[a[x]].push_back(i);
        }else if(op[i] == 2){
            int p = read(),t = read();
            G[a[x]].push_back(i);
            a[x] = i;
            b[i] = node{p,t};
        }else if(op[i] == 3){
            G[a[x]].push_back(i);
            a[x] = i;
        }else{
            int p = read();
            G[a[x]].push_back(i);
            a[x] = i;
            b[i] = node{p,0};
        }
    }
    dfs(0);
    for(int i=1;i<=n;i++)
        if(op[i] == 4) cout << ans[i] << "\n";
    return 0;
}
