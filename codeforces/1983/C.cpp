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
ll tot,a[N][3];
int l[3],r[3];
bool chk(int x,int y,int z){
    ll sum = 0;
    l[0] = l[1] = l[2] = r[0] = r[1] = r[2] = 0;
    l[x] = 1;
    for(int i=1;i<=n;i++){
        sum += a[i][x];
        if(sum >= tot){
            r[x] = i;
            break;
        }
    }
    if(!r[x]) return false;
    l[y] = r[x]+1;
    sum = 0;
    for(int i=l[y];i<=n;i++){
        sum += a[i][y];
        if(sum >= tot){
            r[y] = i;
            break;
        }
    }
    if(!r[y]) return false;
    l[z] = r[y]+1;
    sum = 0;
    for(int i=l[z];i<=n;i++){
        sum += a[i][z];
        if(sum >= tot){
            r[z] = i;
            break;
        }
    }
    if(!r[z]) return false;
    r[z] = n;
    printf("%d %d %d %d %d %d\n",l[0],r[0],l[1],r[1],l[2],r[2]);
    return true;
}
void solve(){
    if(chk(0,1,2)) return ;
    if(chk(0,2,1)) return ;
    if(chk(1,0,2)) return ;
    if(chk(1,2,0)) return ;
    if(chk(2,1,0)) return ;
    if(chk(2,0,1)) return ;
    cout << "-1\n";
}
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i][0] = read();
        for(int i=1;i<=n;i++) a[i][1] = read();
        for(int i=1;i<=n;i++) a[i][2] = read();
        tot = 0;
        for(int i=1;i<=n;i++) tot += a[i][0];
        tot = (tot+2)/3;
        // cout << tot << "\n";
        solve();
    }
	return 0;
}
