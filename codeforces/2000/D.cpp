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
int n,a[N];
ll sum[N],ans;
char s[N];
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        ans = 0;
        for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
        cin >> (s+1);
        int l = 1,r = n;
        while(l < r){
            while(s[l] != 'L' && l <= n) l++;
            while(s[r] != 'R' && r >= 1) r--;
            if(r <= 0 || l > n || l >= r) break;
            ans += sum[r]-sum[l-1];
            l++; r--;
        }
        cout << ans << "\n";
    }
    return 0;
}
