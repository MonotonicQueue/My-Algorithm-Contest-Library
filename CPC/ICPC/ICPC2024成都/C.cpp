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
const int N = 100;
int id(int x,int y){return x*9+y;}
string chess = "JSCMXB";
vector<pii> way[6];
int dis[6][N][N];
void bfs(int o,int sx,int sy){
    int w = id(sx,sy);
    dis[o][w][w] = 0;
    queue<pii> q; q.emplace(sx,sy);
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        int u = id(x,y);
        for(auto &[dx,dy] : way[o]){
            if(o == 5 && x <= 4 && dy) continue;
            int nx = x+dx,ny = y+dy;
            if(nx < 0 || ny < 0 || nx > 9 || ny > 8) continue;
            int v = id(nx,ny);
            if(dis[o][w][v] == -1){
                dis[o][w][v] = dis[o][w][u]+1;
                q.emplace(nx,ny);
            }
        }
    }
}
void init(){
    way[0]={{1,0},{-1,0},{0,1},{0,-1}};
	way[1]={{1,1},{1,-1},{-1,1},{-1,-1}};
	for(int i=1;i<=9;i++){
		way[2].emplace_back(i,0);
		way[2].emplace_back(-i,0);
		way[2].emplace_back(0,i);
		way[2].emplace_back(0,-i);
	}
	way[3]={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
	way[4]={{2,2},{2,-2},{-2,-2},{-2,2}};
	way[5]={{1,0},{0,1},{0,-1}};
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<6;i++) for(int x=0;x<=9;x++)
    for(int y=0;y<=8;y++) bfs(i,x,y);
}
int n;
using info = vector<tuple<int,int,int>>;
map<info,bool> f[5];
map<info,pii> g[5];
bool chk(info A){
    for(auto [x,y,z] : A)
        if(z != get<2>(A[0])) return false;
    return true;
}
bool dfs(info A,int d){
    if(f[d].count(A)) return f[d][A];
    if(chk(A)) return f[d][A] = 1;
    if(!d) return false;
    for(int i=0;i<=9;i++) for(int j=0;j<=8;j++){
        int u = id(i,j);
        map<int,info> mp;
        for(auto [x,y,o] : A)
            mp[dis[o][id(x,y)][u]].emplace_back(x,y,o);
        bool flag = true;
        for(auto [a,b] : mp) flag &= dfs(b,d-1);
        if(flag){
            g[d][A] = mk(i,j);
            return f[d][A] = true;
        }
    }
    return f[d][A] = false;
}
int ask(int x,int y){
    cout << "? " <<  x << " " << y << endl;
    return read();
}
void answer(char c,int d=0){
    while(d--) cout << "? 0 0" << endl;
    cout << "! " << c << endl;
}
void query(info A,int d){
    if(chk(A)) return answer(chess[get<2>(A[0])],d);
    auto [i,j] = g[d][A];
    int u = id(i,j);
    map<int,info> mp;
    for(auto [x,y,o] : A)
        mp[dis[o][id(x,y)][u]].emplace_back(x,y,o);
    int res = ask(i,j);
    query(mp[res],d-1);
}
int main(){
    init();
    n = read();
    info A;
    for(int i=1;i<=n;i++){
        int x = read(),y = read();
        for(int o=0;o<6;o++) A.emplace_back(x,y,o);
    }
    int d = 0;
    while(true){
        d++;
        if(dfs(A,d)){
            cout << d << endl;
            query(A,d);
            return 0;
        }
    }
	return 0;
} 


