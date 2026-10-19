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
int n,m,q;
int a[N],b[N];
void solve(){
    n = read(); m = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=m;i++) b[i] = read();
    set<int> s;
    for(int i=1,j=1;i<=m;i++){
        if(s.find(b[i]) != s.end())
            continue;
        if(a[j] != b[i]){
            puts("TIDAK");
            return ;
        }
        s.insert(a[j]); j++;
    }
    puts("YA");
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
