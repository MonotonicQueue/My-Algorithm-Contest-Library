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
int mod;
string s;
map<ull,ll> mp;
mt19937_64 rnd(time(0));
const int N = 1<<18;
struct Matrix{
	ll mat[2][2];
	Matrix(){
		mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
	}
	ll* operator[](const int &x){
		return mat[x];
	}
	Matrix operator*(const Matrix &o)const{
		Matrix res;
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
					res[i][j] = (res[i][j]+mat[i][k]*o.mat[k][j]%mod)%mod;
		return res;
	}
}T[2][N+10];

signed main(){
	cin >> s; mod = read();
	T[0][0][0][0] = T[0][0][1][1] = T[1][0][0][0] = T[1][0][1][1] = 1;
	T[0][1][0][1] = T[0][1][1][0] = T[0][1][1][1] = 1;
	for(int i=2;i<=N;i++) T[0][i] = T[0][i-1]*T[0][1];
	T[1][1] = T[0][N];
	for(int i=2;i<=N;i++) T[1][i] = T[1][i-1]*T[1][1];
	ll len = 0;
	while(true){
		ll x = (rnd()<<28>>28);
		Matrix C = T[0][x&(N-1)]*T[1][x>>18];
		ull val = 1ull*C[0][0]<<32|(C[0][1]);
		if(mp[val]){
			len = abs(mp[val]-x);
			break;
		}
		mp[val] = x;
	}
	ll n = 0;
	for(int i=0;i<(int)s.size();i++) n = (n*10+s[i]-'0')%len;
	cout << (T[0][n&(N-1)]*T[1][n>>18])[0][1];
    return 0;
}