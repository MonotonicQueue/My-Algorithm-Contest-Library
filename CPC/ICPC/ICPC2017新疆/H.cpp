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
int mod;
struct Mat{
    ll d[21][21];
    Mat(){memset(d,0,sizeof(d));}
    ll *operator[](const int &x){
        return d[x];
    }
};
Mat operator*(Mat &a,Mat &b){
    Mat c;
    for(int i=1;i<=20;i++)
        for(int j=1;j<=20;j++)
            for(int k=1;k<=20;k++)
                c[i][j] = (c[i][j]+a[i][k]*b[k][j])%mod;
    return c;
}

ll f[12],g[12];
void solve(){
    int a = read(),b = read();
    mod = read();
    memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
    g[0] = 1;
    for(int i=1;i<=9;i++)
        for(int j=1;j<=i;j++){
            f[i] = (f[i]+f[i-j]*10+j*g[i-j])%mod;
            g[i] = (g[i]+g[i-j])%mod;
        }
            
    // for(int i=0;i<=9;i++) cout << f[i] << " ";
    // cout << "\n";
    __int128 k = 1;
    while(b--) k *= a;
    if(k <= 9) return cout << f[k] << "\n",void();
    k -= 9;
    Mat A,B;
    for(int i=1;i<=9;i++) A[1][i] = f[9-i+1];
    A[1][10] = 1;
    for(int i=1;i<=9;i++) A[1][i+10] = g[9-i+1];
    for(int i=1;i<=9;i++) B[i][1] = 10;
    for(int i=1;i<=9;i++) B[i+10][1] = i;
    for(int i=1;i<=8;i++) B[i][i+1] = 1;
    B[10][10] = 1;
    for(int i=1;i<=9;i++) B[i+10][11] = 1;
    for(int i=11;i<=18;i++) B[i][i+1] = 1;
    while(k){
        if(k & 1)
            A = A*B;
        B = B*B;
        k >>= 1;
    }
    cout << A[1][1] << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
/*

*/