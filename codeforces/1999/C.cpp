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
int n,s,m;
int main(){
    int T = read();
    while(T--){
        n = read(); s = read(); m = read();
        bool flag = false;
        int lst = 0;
        for(int i=1;i<=n;i++){
            int l = read(),r = read();
            if(l-lst >= s) flag = true;
            lst = r;
        }
        if(m-lst >= s) flag = true;
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
