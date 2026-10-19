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
const int N = 1e4+10;
int n,m,a[N],f[N],g[N];
vector<int> s[N],t[N];
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=m;i++){
        int cnt = read();
        while(cnt--){
            int x = read();
            s[i].push_back(x);
            f[i] ^= a[x];
        }
    }
    for(int i=1;i<=m;i++){
        int cnt = read();
        while(cnt--){
            int x = read();
            t[i].push_back(x);
            g[i] ^= a[x];
        }
    }
    for(int i=1;i<=m;i++){
        bool flag1 = (s[i] == t[i]),flag2 = (f[i] == g[i]);
        puts(flag1 == flag2 ? "correct" : "wrong");
    }
	return 0;
}