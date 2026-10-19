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
const int N = 2100;
int n,a[N],fa[N];
pii ans[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
int v[N];
void work(){
    for(int i=1;i<=n;i++) fa[i] = i;
    for(int i=n-1;i;i--){
        for(int j=0;j<i;j++) v[j] = 0;
        for(int j=1;j<=n;j++){
            if(!v[a[j] % i]) v[a[j] % i] = j;
            else{
                int x = v[a[j] % i];
                if(get(x) != get(j)){
                    ans[i] = mk(x,j);
                    fa[get(x)] = get(j);
                    break;
                }
            }
            if(j == n){
                puts("NO");
                return ;
            }
        }
    }
    puts("YES");
    for(int i=1;i<n;i++) cout << ans[i].fi << " " << ans[i].se << "\n";
}
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        work();
    }
	return 0;
}
