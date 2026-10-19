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
int n,a[N],pos[N][2];
inline void clear(){
    for(int i=1;i<=n;i++) pos[i][0] = pos[i][1] = 0;
}
char ans[N];
bool chk(int l,int r,int L,int R){
    int tot = 1;
    while(l <= r || L <= R){
        if(l <= r){
            if(pos[a[l]][1] == r){
                ans[++tot] = 'L'; ans[2*n-tot+1] = 'L';
                l++; r--; continue;
            }else if(pos[a[l]][1] == L){
                ans[++tot] = 'L'; ans[2*n-tot+1] = 'R';
                l++; L++; continue;
            }
        }
        if(pos[a[R]][0] == r){
            ans[++tot] = 'R'; ans[2*n-tot+1] = 'L';
            R--; r--; continue;
        }else if(pos[a[R]][0] == L){
            ans[++tot] = 'R'; ans[2*n-tot+1] = 'R';
            R--; L++; continue;
        }
        return false;
    }
    return true;
}
inline void solve(){
    for(int i=1;i<=2*n;i++){
        if(!pos[a[i]][0]) pos[a[i]][0] = i;
        else pos[a[i]][1] = i;
    }
    if(chk(2,pos[a[1]][1]-1,pos[a[1]][1]+1,2*n)){
        ans[1] = ans[2*n] = 'L';
        for(int i=1;i<=2*n;i++) cout << ans[i];
        cout << "\n";
    }else if(chk(1,pos[a[2*n]][0]-1,pos[a[2*n]][0]+1,2*n-1)){
        ans[1] = 'R'; ans[2*n] = 'L';
        for(int i=1;i<=2*n;i++) cout << ans[i];
        cout << "\n";
    }else puts("-1");
}
signed main(){
    // freopen("palin.in","r",stdin);
    // freopen("palin.out","w",stdout);
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=2*n;i++) a[i] = read();
        clear(); solve();
    }
    return 0;
}
