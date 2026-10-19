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
int n,a[N],b[N];
bool chk(){
    for(int i=1,j=n,l=1,r=n;i < j && l < r;){
        if(a[i] == b[l] && a[j] == b[r]) i++,l++;
        else if(a[i] == b[r] && a[j] == b[l]) i++,r--;
        else return true;
    }
    return false;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    puts(chk() ? "Alice" : "Bob");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
