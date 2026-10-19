#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 15;
int n;
int a[N][N][N];
int f[1<<12][1<<12];
vector<int> v[1<<N],st[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++) a[i][j][k] = read();
    for(int i=0;i<(1<<n);i++){
        int cnt = 0;
        for(int j=0;j<n;j++)
            if((i >> j) & 1) v[i].push_back(j),cnt++;
        st[cnt].push_back(i);
    }
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int &visx : st[i]) for(int &visy : st[i]){
            for(int x : v[visx]) for(int y : v[visy]){
                f[visx][visy] = min(f[visx][visy],f[visx^(1<<x)][visy^(1<<y)]+a[i][x][y]);
            }
        }
    }
    cout << f[(1<<n)-1][(1<<n)-1];
	return 0;
}
