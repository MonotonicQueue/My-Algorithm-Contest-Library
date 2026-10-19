#include<bits/stdc++.h>
#define ll long long
#define int ll
#define ull unsigned long long
#define pii pair<ll,ll>
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
vector<pii> v;
int mat[N],lst[N];
void ask(int x,int y){
    cout << "^ " << x << " " << y << endl;
    v.push_back(mk(x,y));
}
void solve(int n,int mn,int mx){
    int res = read();
    if(n == 2){
        ask(mn,res);
        int rs = read();
        mat[rs] = mat[mn] = 2;
        return ;
    }
    ask(mn,res);
    int rs = read();
    ask(rs,mx);
    mat[mn] = mat[mx] = n;
    solve(n-1,mn+1,mx-1);
}
signed main(){
    int T = read();
    while(T--){
        int n = read(),lim = read();
        if(n == 1){
            int res = read();
            cout << "!\n1 2" << endl;
            continue;
        }
        v.clear();
        for(int i=1;i<=2*n;i++) mat[i] = 1,lst[i] = 0;
        solve(n,1,2*n);
        while(!v.empty()){
            int x = v.back().fi,y = v.back().se;
            swap(mat[x],mat[y]);
            v.pop_back();
        }
        cout << "!\n";
        for(int i=1;i<=2*n;i++){
            if(!lst[mat[i]]) lst[mat[i]] = i;
            else cout << lst[mat[i]] << " " << i << "\n";
        }
        fflush(stdout);
    }
    return 0;
}
