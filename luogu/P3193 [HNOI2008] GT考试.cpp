#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 25;
int n,m,mod;
char ch[N];
int kmp[N];
struct Matrix{
	int mat[N][N];
	Matrix(){
		memset(mat,0,sizeof(mat));
	}
}A,B;
Matrix operator*(Matrix x,Matrix y){
    Matrix z;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<m;k++)
                z.mat[i][j] = (z.mat[i][j]+x.mat[i][k]*y.mat[k][j])%mod;
    return z;
}
Matrix fpow(Matrix x,int k){
    Matrix res = x; k--;
    while(k){
        if(k & 1)
            res = res*x;
        x = x*x;
        k >>= 1;
    }
    return res;
}
int calc(int x,char s){
    while(x && ch[x+1] != s) x = kmp[x];
    if(ch[x+1] == s) x++;
    return x;
}
int main(){
	cin >> n >> m >> mod;
    cin >> ch+1;
    for(int i=2,j=0;i<=m;i++){
        while(j && ch[i] != ch[j+1]) j = kmp[j];
        if(ch[i] == ch[j+1]) j++;
        kmp[i] = j;
    }
    for(int i=0;i<m;i++)
        for(char s='0';s<='9';s++){
            int j = calc(i,s);
            if(j != m) A.mat[i][j]++;
        }
    B.mat[0][0] = 1;
    A = fpow(A,n);
    B = B*A;
    int ans = 0;
    for(int i=0;i<m;i++) ans = (ans+A.mat[0][i])%mod;
    cout << ans;
	return 0;
}

