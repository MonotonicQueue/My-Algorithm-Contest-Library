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
const int N = 1e4+10;
int n;
signed main(){
    n = read();
    if(n & 1){
        int len = n-1;
        cout << (n+1)/2 << "\n";
        for(int i=1;i<=len/2;i++) cout << i << " " << i+len/2 << "\n";
        cout << "1 " << n << "\n";
    }else{
        cout << n/2 << "\n";
        for(int i=1;i<=n/2;i++) cout << i << " " << i+n/2 << "\n";
    }
    return 0;
}
