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
int a[N],b[N];
void solve(){
    int xc = read(),yc = read(),k = read();
    if(k & 1){
        a[1] = xc; b[1] = yc;
        for(int i=1;i<=k/2;i++)
            a[i*2] = a[1]+i,a[i*2+1] = a[1]-i,
            b[i*2] = b[1]+i,b[i*2+1] = b[1]-i;
    }else{
        for(int i=1;i<=k/2;i++)
            a[i*2-1] = xc+i,a[i*2] = xc-i,
            b[i*2-1] = yc+i,b[i*2] = yc-i;
    }
    for(int i=1;i<=k;i++) cout << a[i] << " " << b[i] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
