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
const int N = 1<<14;
const int M = 105;
const int inf = 1e9;
int n,m;
struct node{
    int x,y,t;
}a[M],b[M];
bool cmp(node x,node y){
    return x.t < y.t;
}
int f[N][M],g[N][M];
//f为传送门集合S，完成i个任务的最小时间
//g为传送门集合S，当前在i任务点的最大完成任务数
int d[N][M],t[N][M];
//d为从传送门到目标，t为从传送门到传送门
int dis(node x, node y){
    return abs(x.x-y.x)+abs(x.y-y.y);
}
int main(){
    n = read(); m = read();
    for(int i=0;i<n;i++)
        a[i].x = read(),a[i].y = read();
    for(int i=1;i<=m;i++){
        b[i].x = read(); b[i].y = read();
        b[i].t = read();
    }
    sort(b+1,b+1+m,cmp);
    for(int s=0;s<(1<<n);s++){
        for(int i=1;i<=m;i++){
            d[s][i] = inf;
            for(int j=0;j<n;j++)
                if((s >> j) & 1) d[s][i] = min(d[s][i],dis(a[j],b[i]));
        }
        for(int i=0;i<n;i++){
            t[s][i] = inf;
            for(int j=0;j<n;j++)
                if((s >> j) & 1) t[s][i] = min(t[s][i],dis(a[j],a[i]));
        }
    }
    memset(f,0x3f,sizeof(f));
    memset(g,0xcf,sizeof(g));
    for(int i=0;i<n;i++) f[1<<i][0] = 0;
    for(int i=1;i<=m;i++) g[0][i] = 1;
    for(int s=0;s<(1<<n);s++){
        for(int i=0;i<=m;i++){
            if(f[s][i] > inf) continue;
            for(int j=1;j<=m;j++)
                if(f[s][i]+d[s][j] <= b[j].t) g[s][j] = max(g[s][j],i+1);
            for(int j=0;j<n;j++)
                f[s|(1<<j)][i] = min(f[s|(1<<j)][i],f[s][i]+t[s][j]);
        }
        for(int i=1;i<=m;i++){
            if(g[s][i] < 0) continue;
            for(int j=0;j<n;j++)
                f[s|(1<<j)][g[s][i]] = min(f[s|(1<<j)][g[s][i]],b[i].t+min(dis(b[i],a[j]),t[s][j]));
            for(int j=i+1;j<=m;j++){
                if(b[i].t+min(dis(b[i],b[j]),d[s][j]) <= b[j].t)
                    g[s][j] = max(g[s][j],g[s][i]+1);
            }
        }
    }
    int ans = 1;
    for(int s=0;s<(1<<n);s++)
        for(int i=1;i<=m;i++) ans = max(ans,g[s][i]);
    cout << ans;
	return 0;
}
