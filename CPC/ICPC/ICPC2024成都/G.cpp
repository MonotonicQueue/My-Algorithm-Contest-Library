#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
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
int n;
int a[N];
void solve(){
    n = read();
    set<int> s;
    for(int i=1;i<=n;i++){
        a[i] = read();
        s.insert(a[i]);
    }
    s.insert(0);
    for(int i=2;i<=n;i++){
        int x = a[i-1],y = a[i],z = x^y;
        s.insert(x^y); s.insert(x&y);
        s.insert(x|y); s.insert(x|z);
        s.insert(y|z); s.insert(x&z);
        s.insert(y&z);
    }
    cout << s.size() << "\n";
}
int main(){
    int Q = 1;
    while(Q--) solve();
	return 0;
} 


