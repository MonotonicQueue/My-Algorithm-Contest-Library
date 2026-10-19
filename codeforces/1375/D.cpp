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
const int N = 1e3+10;
int n,a[N],cnt[N];
void solve(){
    n = read();
    for(int i=0;i<=n;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++) a[i] = read(),cnt[a[i]]++;
    auto mex = [&]()->int{
        for(int i=0;i<=n;i++)
            if(!cnt[i]) return i;
        return n+1;
    };
    vector<int> op;
    for(int i=1;i<=n;i++){
        int x = mex();
        if(a[i] == i-1) continue;
        while(x < n && x > i-1){
            cnt[a[x+1]]--;
            a[x+1] = x;
            cnt[a[x+1]]++;
            op.push_back(x+1);
            x = mex();
        }
        for(int j=i+1;j<=n;j++){
            if(a[j] == i-1){
                cnt[a[j]]--;
                a[j] = x;
                cnt[x]++;
                op.push_back(j);
                x = mex();
            }
        }
        cnt[a[i]]--;
        a[i] = x;
        cnt[a[i]]++;
        op.push_back(i);
    }
    cout << op.size() << "\n";
    for(int x : op) cout << x << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
