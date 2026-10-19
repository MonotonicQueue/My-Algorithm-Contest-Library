#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
double st = clock();
int a[4][4],b[4][4];
inline void work2(int x,int y){
    //逆时针
    swap(a[x][y],a[x][y+1]);
    swap(a[x][y],a[x+1][y]);
    swap(a[x+1][y],a[x+1][y+1]);
}
inline void work1(int x,int y){
    //顺时针
    swap(a[x][y],a[x+1][y]);
    swap(a[x][y],a[x][y+1]);
    swap(a[x][y+1],a[x+1][y+1]);
}
// void work1(int x,int y){
//     //逆时针
//     memcpy(b,a,sizeof(b));
//     b[x][y] = a[x][y+1];
//     b[x+1][y] = a[x][y];
//     b[x][y+1] = a[x+1][y+1];
//     b[x+1][y+1] = a[x+1][y];
//     memcpy(a,b,sizeof(b));
// }
// void work2(int x,int y){
//     //顺时针
//     memcpy(b,a,sizeof(b));
//     b[x][y] = a[x+1][y];
//     b[x+1][y] = a[x+1][y+1];
//     b[x][y+1] = a[x][y];
//     b[x+1][y+1] = a[x][y+1];
//     memcpy(a,b,sizeof(b));
// }
inline int calc(int x,int y){
    return a[x][y]+a[x+1][y]+a[x][y+1]+a[x+1][y+1];
}
int k;
int dfs(int p){
    if(p > 2*k) return 0;
    int ans = 1e9;
    if(p & 1) ans = 0;
    for(int x=0;x<3;x++)
        for(int y=0;y<3;y++){
            work1(x,y);
            int t = calc(x,y)+dfs(p+1);
            if(p & 1) ans = max(ans,t);
            else ans = min(ans,t);
            work2(x,y);
        }
    return ans;
}
void solve(){
    k = read();
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++) a[i][j] = read();
    cout << dfs(1) << "\n";
}
int main(){
    // freopen("1.in","r",stdin);
    // a[0][0] = 1;
    // a[0][1] = 2;
    // a[1][0] = 3;
    // a[1][1] = 4;
    // work1(0,0);
    // for(int i=0;i<2;i++,puts(""))
    //     for(int j=0;j<2;j++) cout << a[i][j];
	int T = read();
	while(T--) solve();
	return 0;
}