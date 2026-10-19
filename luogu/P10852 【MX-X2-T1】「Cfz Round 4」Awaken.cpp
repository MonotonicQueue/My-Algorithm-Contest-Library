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
const int inf = 1e9+1;
int n,m;
int a[N];
bool chk(){
    int lst = 0,d = inf;
    for(int i=1;i<=n;i++){
        if(a[i] != inf){
            if(lst){
                if((a[i]-a[lst]) % (i-lst)) return false;
                if(d == inf){
                    d = (a[i]-a[lst])/(i-lst);
                }else{
                    if((a[i]-a[lst])/(i-lst) != d) return false;
                }
            }
            lst = i;
        }
    }
    return true;
}
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        for(int i=1;i<=n;i++) a[i] = inf;
        for(int i=1;i<=m;i++){
            int p = read();
            a[p] = read();
        }
        if(m <= 1){
            puts("Yes");
            continue;
        }
        puts(chk() ? "Yes" : "No");
    }
    return 0;
}