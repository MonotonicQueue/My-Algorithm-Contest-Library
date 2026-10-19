#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
const int mod = 1e9+7;
int n,m,b[N];
pii a[N];
ll v;
map<int,int> mp;
struct Matrix{
	ll mat[2][2];
	Matrix(){
		memset(mat,0,sizeof(mat));
	}
	ll* operator[](const int x){
		return mat[x];
	}
	Matrix operator*(const Matrix &o)const{
		Matrix res;
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++) res[i][j] = (res[i][j]+mat[i][k]*o.mat[k][j]%mod)%mod;
		return res;
	}
}pw1[N],pw2[N];
Matrix Mpw(int k){
	return pw2[k/100000]*pw1[k%100000];
}
void solve(){
	n = read(); m = read(); v = read();
	bool flag = false;
	mp.clear();
	int tot = 0;
	for(int i=1;i<=m;i++){
		a[i].fi = read();
		a[i].se = read();
		if(mp[a[i].fi] && mp[a[i].fi] != a[i].se) flag = true;
		if(!mp[a[i].fi] && a[i].fi != n) b[++tot] = a[i].fi;
		mp[a[i].fi] = a[i].se;
	}
	if(flag) return puts("0"),void();
	pw1[0][0][0] = pw1[0][1][1] = 1;
	pw2[0][0][0] = pw2[0][1][1] = 1;
	Matrix Mt,MM;
	Mt[0][0] = v*v%mod;
	Mt[1][0] = (v-1)*v%mod; Mt[1][1] = v;
	MM[0][0] = v*(v-1)%mod; MM[0][1] = v;
	MM[1][0] = v-1; MM[1][1] = 1;
	for(int i=1;i<=100000;i++) pw1[i] = pw1[i-1]*Mt;
	for(int i=1;i<=100000;i++) pw2[i] = pw2[i-1]*pw1[100000];
	if(!mp[1]) b[++tot] = 1;
	sort(b+1,b+1+tot);
	Matrix F;
	if(!mp[1]) F[0][0] = v;
	else F[0][0] = v-1,F[0][1] = 1;
	for(int i=2;i<=tot;i++){
		Matrix now = F*Mpw(b[i]-b[i-1]-1);
		F = now*MM;
	}
	F = F*Mpw(n-b[tot]-1);
	ll ans = 0;
	if(mp[n]) ans = (F[0][0]*v%mod+F[0][1])%mod;
	else ans = (F[0][0]*v%mod+F[0][1]*v%mod)%mod;
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
