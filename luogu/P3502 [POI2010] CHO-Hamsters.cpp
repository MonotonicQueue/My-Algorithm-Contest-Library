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
const int N = 210;
const int S = 1e5+10;
const ll inf = 1e18;
int n,m;
string s[N];
int kmp[S],a[N][N];
inline void calc(int x,int y){
    int lenx = s[x].size()-1,leny = s[y].size()-1;
    int i,j;
    for(i=2,j=0;i<=leny;i++){
        while(j && s[y][i] != s[x][j+1]) j = kmp[j];
        if(s[y][i] == s[x][j+1]) j++;
    }
    a[y][x] = lenx-j;
}
inline void work(int id){
    int len = s[id].size()-1;
    for(int i=2,j=0;i<=len;i++){
        while(j && s[id][i] != s[id][j+1]) j = kmp[j];
        if(s[id][i] == s[id][j+1]) j++;
        kmp[i] = j;
    }
//    for(int i=1;i<=len;i++) cout << kmp[i] << " ";
//	cout << "\n"; 
    for(int i=1;i<=n;i++)
        if(i != id) calc(id,i);
        else a[i][i] = len-kmp[len];
}
struct Matrix{
	ll mat[N][N];
	Matrix(){
		for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) mat[i][j] = inf;
	}
}M;
Matrix operator*(Matrix x,Matrix y){
    Matrix z;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                z.mat[i][j] = min(z.mat[i][j],x.mat[i][k]+y.mat[k][j]);
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
int len[N];
int main(){
	cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> s[i];
    for(int i=1;i<=n;i++) s[i] = " "+s[i];
    for(int i=1;i<=n;i++) len[i] = s[i].size()-1,work(i);
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++) cout << a[i][j] << " ";
//        cout << "\n";
//    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) M.mat[i][j] = a[i][j];
    if(m == 1){
        int ans = 1e9;
        for(int i=1;i<=n;i++) ans = min(ans,len[i]);
        cout << ans;
    }else{
        M = fpow(M,m-1);
        ll ans = inf;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans = min(ans,len[i]+M.mat[i][j]);
            }
        }
        cout << ans;
    }
	return 0;
}

