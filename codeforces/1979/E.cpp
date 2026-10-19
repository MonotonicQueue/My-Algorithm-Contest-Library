#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
int n,d;
struct node{
    int x,y,id;
}a[N];
int b[N],tot;
vector<pii> v[N];
bool cmp(node x,node y){
    return x.y != y.y ? x.y < y.y : x.x < y.x;
}
bool solve(){
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=tot;i++) b[i] = 0,v[i].clear();
    tot = 0;
    for(int i=1;i<=n;i++){
        if(a[i].y != a[i-1].y || i == 1){
            b[++tot] = a[i].y;
            v[tot].push_back(mk(a[i].x,a[i].id));
        }else v[tot].push_back(mk(a[i].x,a[i].id));
    }
    for(int i=1;i<=tot;i++){
        int len = v[i].size();
        for(int x=0;x<len;x++){
            int y = lower_bound(v[i].begin(),v[i].end(),mk(v[i][x].first+d,0))-v[i].begin();
            if(y == len || v[i][y].fi != v[i][x].fi+d) continue;
            int k = lower_bound(b+1,b+1+tot,b[i]-d)-b;
            if(b[k] == b[i]-d){
                int t = lower_bound(v[k].begin(),v[k].end(),mk(v[i][x].fi,0))-v[k].begin();
                if(t != v[k].size() && v[k][t].fi <= v[i][x].fi+d){
                    cout << v[i][x].se << " " << v[i][y].se << " " << v[k][t].se << "\n";
                    return true;
                }
            }
            k = lower_bound(b+1,b+1+tot,b[i]+d)-b;
            if(b[k] == b[i]+d){
                int t = lower_bound(v[k].begin(),v[k].end(),mk(v[i][x].fi,0))-v[k].begin();
                if(t != v[k].size() && v[k][t].fi <= v[i][x].fi+d){
                    cout << v[i][x].se << " " << v[i][y].se << " " << v[k][t].se << "\n";
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
	int T = read();
    while(T--){
        n = read(); d = read();
        for(int i=1;i<=n;i++){
            int x = read(),y = read();
            a[i] = {x+y,x-y,i};
        }
        if(solve()) continue;
        for(int i=1;i<=n;i++) swap(a[i].x,a[i].y);
        if(solve()) continue;
        puts("0 0 0");
    }
	return 0;
}