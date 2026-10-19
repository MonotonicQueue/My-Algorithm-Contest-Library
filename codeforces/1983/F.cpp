#include<bits/stdc++.h>
#define int long long
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
int n; ll k;
int a[N];
int t[N*32][2],f[N*32],cnt=1;
void insert(int x,int id){
    int p = 1;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1;
        if(!t[p][c]) t[p][c] = ++cnt;
        p = t[p][c]; f[p] = max(f[p],id);
    }
}
int ask(int x,int y){
    int res = 0,p = 1;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1,d = (y >> i) & 1;
        if(d){
            res = max(res,f[t[p][c]]);
            p = t[p][c^1];
        }else{
            p = t[p][c];
        }
    }
    res = max(res,f[p]);
    return res;
}
bool chk(int x){
    ll res = 0;int l = 0;
    for(int i=1;i<=n;i++){
        l = max(l,ask(a[i],x));
        res += l;
        insert(a[i],i);
    }
    // cout << x << " " << res << "\n";
    for(int i=0;i<=cnt;i++) f[i] = t[i][0] = t[i][1] = 0;
    cnt = 1;
    return res >= k;
}
signed main(){
    int T = read();
    while(T--){
        n = read(); k = read();
        for(int i=1;i<=n;i++) a[i] = read();
        int l = 0,r = 2e9,res = 0;
        while(l <= r){
            int mid = (l+r)>>1;
            if(chk(mid)) r = mid-1,res = mid;
            else l = mid+1;
        }
        cout << res << "\n";
    }
	return 0;
}
