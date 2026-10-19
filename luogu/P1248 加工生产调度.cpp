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
const int N = 1010;
int a[N],b[N],p[N],c[N];
int main(){
    int n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    for(int i=1;i<=n;i++) p[i] = i;
    sort(p+1,p+1+n,[](int x,int y){return min(a[x],b[x]) < min(a[y],b[y]);});
    int l = 0,r = n+1;
    for(int i=1;i<=n;i++){
        if(a[p[i]] == min(a[p[i]],b[p[i]])) c[++l] = p[i];
        else c[--r] = p[i];
    }
    int sa = 0,sb = 0;
    for(int i=1;i<=n;i++){
        int x = c[i];
        sa += a[x];
        if(sa > sb) sb = sa;
        sb += b[x];
    }
    cout << sb << "\n";
    for(int i=1;i<=n;i++) cout << c[i] << " ";
    return 0;
}
