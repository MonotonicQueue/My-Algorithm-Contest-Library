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
const int N = 5e5+10;
int n,p[N];
ll a[N],c;
void solve(){
    n = read(); c = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) p[i] = i;
    sort(p+2,p+1+n,[](int x,int y){return a[x]-x*c > a[y]-y*c;});
    ll now = a[1];
    for(int i=2;i<=n;i++){
        int x = p[i];
        if(now+a[x] < x*c) return puts("No"),void();
        now += a[x];
    }
    puts("Yes");
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}