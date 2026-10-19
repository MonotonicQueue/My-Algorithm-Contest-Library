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
const int N = 5e5;
const int M = N*120;
int T,n;
bitset<M+10> sg;
bool vis[N+10];
signed main(){
    T = read(); n = read();
    for(int i=0;i<=M;i++){
        if(vis[i%n]){
            sg[i] = true;
            continue;
        }
        if(!sg[i]){
            vis[i%n] = true;
            for(int j=1;j*j<=n;j++) sg[i+j*j] = true;
        }
    }
    while(T--){
        int x = read();
        if(x > M) putchar('F');
        else putchar(sg[x] ? 'F' : 'B');
    }
    return 0;
}
