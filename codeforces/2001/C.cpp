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
int ask(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    return read();
}
bool flag[N];
vector<pii> ans;
void solve(){
    n = read();
    for(int i=1;i<=n;i++) flag[i] = false;
    flag[1] = true;
    ans.clear();
    for(int i=n;i>1;){
        int l = 1,r = i;
        if(flag[i]){
            i--;
            continue;
        }
        while(true){
            int p = ask(l,r);
            if(p == l){
                flag[r] = true;
                ans.push_back(mk(l,r));
                break;
            }
            if(flag[p]) l = p;
            else r = p;
        }
    }
    cout << "! ";
    for(auto it : ans) cout << it.fi << " " << it.se << " ";
    cout << endl;
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}
