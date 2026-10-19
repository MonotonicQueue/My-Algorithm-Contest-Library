#include<bits/stdc++.h>
#define ll long long
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
const int N = 1e5+10;
int n;
pii d[2][N];
ll f[N][20][2][2];
int dis(pii x,pii y){
    return abs(x.fi-y.fi)+abs(x.se-y.se);
}
int main() {
	n = read();
    d[0][1] = d[1][1] = mk(1,1);
    for(int i=2;i<=n;i++){
        d[0][i].fi = read()+1; d[0][i].se = read();
        d[1][i].fi = read(); d[1][i].se = read()+1;
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        for(int x=0;x<=1;x++) f[i][0][x][x] = 0;
        for(int x=0;x<=1;x++) f[i][0][x][x^1] = dis(d[0][i],d[1][i]);
    }
    for(int j=1;j<=18;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            int u = i+(1<<(j-1))-1,v = u+1;
            for(int x=0;x<=1;x++) for(int y=0;y<=1;y++)
                for(int xx=0;xx<=1;xx++) for(int yy=0;yy<=1;yy++)
                    f[i][j][x][y] = min(f[i][j][x][y],f[i][j-1][x][xx]+f[v][j-1][yy][y]+dis(d[xx][u],mk(d[yy][v].fi-(yy^1),d[yy][v].se-yy))+1);
        }
    }
    int Q = read();
    while(Q--){
        int sx = read(),sy = read(),dx = read(),dy = read();
        int sp = max(sx,sy),sd = max(dx,dy);
        if(sp > sd) swap(sx,dx),swap(sy,dy),swap(sp,sd);
        ll ans = 1e18;
        if(sp == sd){
            ans = dis(mk(sx,sy),mk(dx,dy));
        }else{
            int st = sp+1,ed = sd;
            ll mn1 = dis(mk(sx,sy),d[0][sp+1]),mn2 = dis(mk(sx,sy),d[1][sp+1]);
            for(int i=18;~i;i--){
                if(st+(1<<i)-1 <= ed){
                    ll d1 = min(mn1+f[st][i][0][0],mn2+f[st][i][1][0]),
                       d2 = min(mn1+f[st][i][0][1],mn2+f[st][i][1][1]);
                    mn1 = d1; mn2 = d2;
                    st += (1<<i)-1;
                }
            }
            while(st < ed){
                ll d1 = min(mn1+f[st][1][0][0],mn2+f[st][1][1][0]),
                    d2 = min(mn1+f[st][1][0][1],mn2+f[st][1][1][1]);
                mn1 = d1; mn2 = d2; st++;
            }
            ans = min(mn1+dis(mk(dx,dy),d[0][sd]),mn2+dis(mk(dx,dy),d[1][sd]));
        }
        cout << ans << "\n";
        
    }
	return 0;
}
/*
5
1 1 1 1
2 1 1 2
3 1 3 3
4 3 4 4
1
1 2 2 5 

*/