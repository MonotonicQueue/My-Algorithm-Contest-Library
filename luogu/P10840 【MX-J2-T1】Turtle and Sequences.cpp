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
const int N = 1e5+10;
int n,a[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int lst = a[1]; bool flag = true;
    for(int i=2;i<=n;i++)
        if(a[i] != a[1]) flag = false;
    if(flag) puts("0");
    else cout << n-1;
    return 0;
}