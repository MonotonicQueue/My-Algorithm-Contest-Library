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
int n,m,a[N];
int solve(){
    int l = read(),r = read();
    int L = read(),R = read();
    if(R < l || r < L) return 1;
    int a = max(l,L),b = min(r,R);
    return b-a+(min(l,L) < a)+(max(r,R) > b);
}
int main(){
    int T = read();
    while(T--)
        cout << solve() << "\n";
    return 0;
}
