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
void solve(){
    n = read();
    bool f = n & 1;
    set<int> s;
    
    if(n % 2 == 0){
        for(int i=1;i<=n;i++) s.insert(i);
        int k = 1;
        while(k*2 <= n) k = k*2;
        if(k == n){
            int x = k|(k-1);
            cout << x << "\n";
            s.erase(k-1); s.erase(k); s.erase(k-2); s.erase(1); s.erase(3);
            for(int it : s) cout << it << " ";
            cout << "1 3" << " " << k-2 << " " << k-1 << " " << k << "\n";
            cout << "\n";
        }else{
            s.erase(k-1); s.erase(k); s.erase(k+1);
            int x = (k-1)|k;
            cout << x << "\n";
            for(auto it : s) cout << it << " ";
            cout << k << " " << k+1 << " " << k-1 << "\n";
        }
    }else{
        for(int i=1;i<n;i++) s.insert(i);
        int k = 1;
        while(k*2 <= n-1) k = k*2;
        if(k == n-1){
            int x = n;
            s.erase(k); s.erase(k-1); s.erase(n^k);
            cout << x << "\n";
            for(int it : s) cout << it << " ";
            cout << (n^k) << " " << k-1 << " " << k << " " << n << "\n";
        }else{
            s.erase(k-1); s.erase(k); s.erase(k+1);
            int x = n;
            cout << x << "\n";
            for(auto it : s) cout << it << " ";
            cout << k << " " << k+1 << " " << k-1 << " " << n << "\n";
        }
    }
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}
