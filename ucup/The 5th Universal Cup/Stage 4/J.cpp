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
const int N = 4e5+10;
int n,a[N],fa[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)] = get(y);
}
bool flag[N];
void solve(){
    n = read();
    for(int i=1;i<=2*n;i++) a[i] = read();
    for(int i=1;i<=n;i++) fa[i] = i;
    stack<int> s;
    for(int i=1;i<=2*n;i++){
        if(s.empty()) s.push(i),flag[i] = 0;
        else{
            if(get(a[i]) != get(a[s.top()])){
                merge(a[i],a[s.top()]);
                flag[i] = 1;
                s.pop();
            }else{
                flag[i] = 0;
                s.push(i);
            }
        }
    }
    // for(int i=1;i<=n;i++) cout << get(i) << "\n";
    // assert(s.size() == 2);
    flag[s.top()] = 1;
    for(int i=1;i<=2*n;i++) putchar(flag[i] ? ')' : '(');
    puts("");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
