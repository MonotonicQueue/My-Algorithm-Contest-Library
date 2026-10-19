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
const int N = 110;
int n,pos[N],d;
struct node{
    int x,y;
}a[N];
int dis(node x,node y){
    return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
bitset<N> b[N];
mt19937 rnd(time(0));
int main(){
    n = read(); d = read();
    for(int i=1;i<=n;i++)
        a[i].x = read(),a[i].y = read();
    for(int i=1;i<=n;i++) b[i][i] = true,pos[i] = i;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(dis(a[i],a[j]) <= d*d) b[i][j] = b[j][i] = true;
    int T = 1000;
    vector<int> ans;
    while(T--){
        shuffle(pos+1,pos+1+n,rnd);
        vector<int> v;
        auto chk = [&](int x){
            for(int y : v)
                if(!b[x][y]) return false;
            return true;
        };
        for(int i=1;i<=n;++i){
            int x = pos[i];
            if(chk(x)) v.push_back(x);
        }
        if(v.size() > ans.size()) ans = v;
    }
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
	return 0;
} 