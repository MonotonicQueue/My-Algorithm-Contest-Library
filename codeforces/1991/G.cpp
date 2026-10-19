#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
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
int n,m,k,q;
char op[1010];
int a[N][N];
int calcsum(int lx,int ly,int rx,int ry){
    int res = 0;
    for(int i=lx;i<=rx;i++)
        for(int j=ly;j<=ry;j++)
            res += a[i][j];
    return res;
}
int rowsum[N],colsum[N];
void work(int x,int y,bool flag){
    cout << x << " " << y << "\n";
    for(int i=1;i<=k;i++){
        a[x][y] = 1;
        flag ? x++ : y++;
    }
    for(int i=1;i<=n;i++) rowsum[i] = 0;
    for(int i=1;i<=m;i++) colsum[i] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            rowsum[i] += a[i][j],colsum[j] += a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(rowsum[i] == m || colsum[j] == n) a[i][j] = 0;
}
int main(){
	int T = read();
    while(T--){
        n = read(); m = read();
        k = read(); q = read();
        cin >> op+1;
        memset(a,0,sizeof(a));
        for(int i=1;i<=q;i++){
            if(op[i] == 'H'){
                int row = 0;
                for(int j=1;j<=n;j++){
                    if(calcsum(j,1,j,k) == 0){
                        row = j;
                        if(calcsum(j,1,j,m) == m-k) break;
                    }
                }
                work(row,1,0);
            }else{
                int col = 0;
                for(int j=1;j<=m;j++){
                    if(calcsum(1,j,k,j) == 0){
                        col = j;
                        if(calcsum(1,j,n,j) == n-k) break;
                    }
                }
                work(1,col,1);
            }
        }
    }
	return 0;
} 