#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define mt make_tuple
#define fi first
#define se second
#define ll long long
#define all(x) x.begin(),x.end()
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 510;
const int M = 3e5+10;
const ll inf = 1e18;
int n,Q;
int u[N],v[N],w[N][N];
struct Ques{
    int a,b,c,d,id;
    Ques(int a,int b,int c,int d,int id): a(a),b(b),c(c),d(d),id(id) {}
};
vector<Ques> q;
ll ff[N][N],fg[N][N],fh[N][N];
ll gf[N][N],gg[N][N],gh[N][N],ans[M];
void solve(int xl,int xr,int yl,int yr,vector<Ques> q){
    if(q.empty()) return ;
    auto maxx = [&](ll x1,ll x2,ll x3,ll x4)->ll{
        return max(max(x1,x2),max(x3,x4));
    };
    if(xr-xl >= yr-yl){
        int xm = (xl+xr) >> 1;
        vector<Ques> ql,qr,now;
        for(auto x : q){
            if(x.a > xm) qr.push_back(x);
            else if(x.b < xm) ql.push_back(x);
            else now.push_back(x);
        }
        solve(xl,xm-1,yl,yr,ql);
        solve(xm+1,xr,yl,yr,qr);
        auto dp1 = [&](int xl,int xr,int yl,int yr){
            for(int x=xl;x<=xr;x++)
                for(int y=yl;y<=yr;y++){
                    ff[x][y] = maxx(x > xl ? ff[x-1][y] : -inf,
                                    y > yl ? ff[x][y-1] : -inf,
                                    x > xl ? fg[x-1][y] : -inf,
                                    y > yl ? fh[x][y-1] : -inf);
                    fg[x][y] = maxx(ff[x][y]-u[x],
                                    y > yl ? fg[x][y-1] : -inf,
                                    y > yl ? fg[x][y-1]-v[y-1]+w[x][y-1] : -inf,
                                    y > yl ? fh[x][y-1]-u[x]+w[x][y-1] : -inf);
                    fh[x][y] = maxx(ff[x][y]-v[y],
                                    x > xl ? fh[x-1][y] : -inf,
                                    x > xl ? fh[x-1][y]-u[x-1]+w[x-1][y] : -inf,
                                    x > xl ? fg[x-1][y]-v[y]+w[x-1][y] : -inf);
                    if(x == xl && y == yl) fh[x][y] = 0;
                }
        };
        auto dp2 = [&](int xl,int xr,int yl,int yr){
            for(int x=xr;x>=xl;x--)
                for(int y=yr;y>=yl;y--){
                    gg[x][y] = maxx(x < xr ? gf[x+1][y] : -inf,
                                    y < yr ? gg[x][y+1] : -inf,
                                    y < yr ? gg[x][y+1]-v[y]+w[x][y] : -inf,
                                    x < xr ? gh[x+1][y]-v[y]+w[x][y] : -inf);
                    gh[x][y] = maxx(y < yr ? gf[x][y+1] : -inf,
                                    x < xr ? gh[x+1][y] : -inf,
                                    y < yr ? gg[x][y+1]-u[x]+w[x][y] : -inf,
                                    x < xr ? gh[x+1][y]-u[x]+w[x][y] : -inf);
                    if(x == xr && y == yr) gh[x][y] = 0;
                    gf[x][y] = maxx(x < xr ? gf[x+1][y] : -inf,
                                    y < yr ? gf[x][y+1] : -inf,
                                    gg[x][y]-u[x],gh[x][y]-v[y]);
                }
        };
        for(int ym=yl;ym<=yr;ym++){
            dp1(xm,xr+1,ym,yr+1);
            dp2(xl,xm,yl,ym);
            for(auto &[a,b,c,d,id] : now){
                if(ym < c || ym > d) continue;
                ans[id] = max(gf[a][c]+ff[b+1][d+1],ans[id]);
            }
        }
    }else{
        int ym = (yl+yr) >> 1;
        vector<Ques> ql,qr,now;
        for(auto x : q){
            if(x.c > ym) qr.push_back(x);
            else if(x.d < ym) ql.push_back(x);
            else now.push_back(x);
        }
        solve(xl,xr,yl,ym-1,ql);
        solve(xl,xr,ym+1,yr,qr);
        auto dp1 = [&](int xl,int xr,int yl,int yr){
            for(int x=xl;x<=xr;x++)
                for(int y=yl;y<=yr;y++){
                    ff[x][y] = maxx(x > xl ? ff[x-1][y] : -inf,
                                    y > yl ? ff[x][y-1] : -inf,
                                    x > xl ? fg[x-1][y] : -inf,
                                    y > yl ? fh[x][y-1] : -inf);
                    fg[x][y] = maxx(ff[x][y]-u[x],
                                    y > yl ? fg[x][y-1] : -inf,
                                    y > yl ? fg[x][y-1]-v[y-1]+w[x][y-1] : -inf,
                                    y > yl ? fh[x][y-1]-u[x]+w[x][y-1] : -inf);
                    fh[x][y] = maxx(ff[x][y]-v[y],
                                    x > xl ? fh[x-1][y] : -inf,
                                    x > xl ? fh[x-1][y]-u[x-1]+w[x-1][y] : -inf,
                                    x > xl ? fg[x-1][y]-v[y]+w[x-1][y] : -inf);
                    if(x == xl && y == yl) fg[x][y] = 0;
                }
        };
        auto dp2 = [&](int xl,int xr,int yl,int yr){
            for(int x=xr;x>=xl;x--)
                for(int y=yr;y>=yl;y--){
                    gg[x][y] = maxx(x < xr ? gf[x+1][y] : -inf,
                                    y < yr ? gg[x][y+1] : -inf,
                                    y < yr ? gg[x][y+1]-v[y]+w[x][y] : -inf,
                                    x < xr ? gh[x+1][y]-v[y]+w[x][y] : -inf);
                    gh[x][y] = maxx(y < yr ? gf[x][y+1] : -inf,
                                    x < xr ? gh[x+1][y] : -inf,
                                    y < yr ? gg[x][y+1]-u[x]+w[x][y] : -inf,
                                    x < xr ? gh[x+1][y]-u[x]+w[x][y] : -inf);
                    if(x == xr && y == yr) gg[x][y] = 0;
                    gf[x][y] = maxx(x < xr ? gf[x+1][y] : -inf,
                                    y < yr ? gf[x][y+1] : -inf,
                                    gg[x][y]-u[x],gh[x][y]-v[y]);
                }
        };
        for(int xm=xl;xm<=xr;xm++){
            dp1(xm,xr+1,ym,yr+1);
            dp2(xl,xm,yl,ym);
            for(auto &[a,b,c,d,id] : now){
                if(xm < a || xm > b) continue;
                ans[id] = max(gf[a][c]+ff[b+1][d+1],ans[id]);
            }
        }
    }
}
int main(){
    n = read(); Q = read();
    for(int i=1;i<=n;i++) u[i] = read();
    for(int i=1;i<=n;i++) v[i] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) w[i][j] = read();
    for(int i=1;i<=Q;i++){
        int a = read(),b = read(),c = read(),d = read();
        q.push_back(Ques(a,b,c,d,i));
    }
    solve(1,n,1,n,q);
    for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
	return 0;
}
