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
const int N = 5010;
int n,m,a[N];
struct node{
    int p,c;
}b[N];
bool cmp(node x,node y){
    return x.p < y.p;
}
ll sum[N],f[N][N];
int q[N],l,r;
signed main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    ll sum_cnt = 0;
    for(int i=1;i<=m;i++){
        b[i].p = read(); b[i].c = read();
        sum_cnt += b[i].c;
    }
    if(sum_cnt < n){
        puts("-1");
        return 0;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m,cmp);
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) sum[j] = sum[j-1]+abs(b[i].p-a[j]);
        l = 1; r = 1; f[i][0] = 0;
        q[1] = 0;
        for(int j=1;j<=n;j++){
            while(l <= r && q[l] < j-b[i].c) l++;
            while(l <= r && f[i-1][j]-sum[j] <= f[i-1][q[r]]-sum[q[r]]) r--;
            q[++r] = j;
            f[i][j] = sum[j]+f[i-1][q[l]]-sum[q[l]];
        }
    }
    cout << f[m][n];
	return 0;
}
/////////