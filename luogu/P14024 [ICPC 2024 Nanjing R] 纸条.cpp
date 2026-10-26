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
int n,m,w,k;
int a[N],b[N];
pii p[N];
int stk[N],top;
void solve(){
    n = read(); m = read();
    k = read(); w = read(); 
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=m;i++) b[i] = read();
    int tot = 0;
    for(int i=1;i<=n;i++) p[++tot] = mk(a[i],0);
    for(int i=1;i<=m;i++) p[++tot] = mk(b[i],1);
    p[++tot] = mk(0,1); p[++tot] = mk(w+1,1);
    sort(p+1,p+1+tot);
    top = 0;
    for(int i=1;i<=tot;i++){
        auto [x,op] = p[i];
        if(top && stk[top]+k-1 >= x){
            if(op == 0){

            }else{
                // cout << i << " " << p[i].fi << "\n";
                stk[top] = x-k;
                for(int j=top-1;j;j--){
                    if(stk[j]+k-1 >= stk[j+1]){
                        stk[j] = stk[j+1]-k;
                    }else break;
                }
            }
        }else{
            if(op == 0) stk[++top] = x;
        }
    }
    // for(int i=1;i<=top;i++){
    //     cout << stk[i] << " ";
    // }
    // cout << "\n";
    if(stk[1] <= 0) return puts("-1"),void();
    for(int i=1,j=1;i<=top;i++){
        while(j <= tot && p[j].fi < stk[i]) j++;
        while(j <= tot && p[j].fi <= stk[i]+k-1){
            if(p[j].se == 1) return puts("-1"),void();
            j++;
        }

    }
    cout << top << "\n";
    for(int i=1;i<=top;i++) cout << stk[i] << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 
