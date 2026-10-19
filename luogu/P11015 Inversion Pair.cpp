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
const int N = 3e5+10;
int n,q,a[N],cnt[N];
int main(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=2;i<=n;i++) cnt[i] = cnt[i-1]+(a[i] < a[i-1]);
    while(q--){
        int x = read(),y = read();
        if(x > y) swap(x,y);
        cout << cnt[y]-cnt[x] << "\n";
    }
    return 0;
}