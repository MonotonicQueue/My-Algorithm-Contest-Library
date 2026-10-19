#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 2.5e5+10;
int n,a[N],b[N],p[N],c[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read(),b[i] = read();
    for(int i=1;i<=n;i++) p[i] = i;
    sort(p+1,p+1+n,[](int x,int y){return min(a[x],b[x]) < min(a[y],b[y]);});
    int l = 0,r = n+1;
    for(int i=1;i<=n;i++){
        int x = p[i];
        if(min(a[x],b[x]) == a[x]) c[++l] = x;
        else          c[--r] = x;
    }
    ll suma = 0,sumb = 0;
    for(int i=1;i<=n;i++){
        int x = c[i];
        suma += a[x];
        if(sumb < suma) sumb = suma;
        sumb += b[x];
    }
    cout << sumb;
    return 0;
}
