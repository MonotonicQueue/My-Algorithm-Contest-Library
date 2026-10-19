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
const int K = 110;
const int N = 201010;
int n,k,f[2][N];
struct node{int l,r;}a[K];
int q[N],head,tail;
signed main(){
    // freopen("1.in","r",stdin);
    n = read(); k = read();
    for(int i=1;i<=k;i++)
        a[i].l = read(),a[i].r = read();
    sort(a+1,a+1+k,[](node x,node y){return x.l < y.l;});
    memset(f[0],0x3f,sizeof(f[0]));
    f[0][0] = 0;
    for(int i=1;i<=k;i++){
        int c = i&1;
        for(int j=0;j<=n;j++) f[c][j] = f[c^1][j];
        head = 1; tail = 0;
        for(int j=a[i].r;~j;j--){
            while(head <= tail && q[head] < a[i].l-j) head++;
            while(head <= tail && f[c^1][q[tail]] > f[c^1][a[i].r-j]) tail--;
            q[++tail] = a[i].r-j;
            f[c][j] = min(f[c][j],f[c^1][q[head]]+1);
        }
        head = 1; tail = 0;
        for(int j=0;j<=a[i].r;j++){
            while(head <= tail && q[head] < j-a[i].r+a[i].l) head++;
            while(head <= tail && f[c^1][q[tail]] > f[c^1][j]) tail--;
            q[++tail] = j;
            f[c][j] = min(f[c][j],f[c^1][q[head]]+2);
        }
    }
    if(f[k&1][n] > 1000000000) cout << "Hungry";
    else{
        cout << "Full\n";
        cout << f[k&1][n];
    }
    return 0;
}
