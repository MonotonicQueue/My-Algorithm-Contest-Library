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
const int N = 2e5+10;
int n,fa[N][20],Z[N],ft[N],dep[N];
char s[N];
vector<int> v[N],vv[N];
int get(int x){
    return ft[x] == x ? x : ft[x] = get(ft[x]);
}
int main(){
    n = read();
    scanf("%s",s+1);
    dep[1] = 1;
    for(int i=2,j=0;i<=n;i++){
        while(j && s[j+1] != s[i]) j = fa[j][0];
        if(s[j+1] == s[i]) j++;
        fa[i][0] = j;
        dep[i] = dep[j]+1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=18;j++) fa[i][j] = fa[fa[i][j-1]][j-1];
    Z[1] = n;
	for(int i=2,l=0,r=0;i<=n;i++){
		if(i <= r) Z[i] = min(Z[i-l+1],r-i+1);
		while(i+Z[i] <= n && s[i+Z[i]] == s[1+Z[i]]) Z[i]++;
		if(i+Z[i]-1 > r) r = i+Z[i]-1,l = i;
	}
    for(int i=1;i<=n;i++){
        v[Z[i]].push_back(i);
        ft[i] = Z[i] ? i : i+1;
    }
    ft[n+1] = n+1;
    for(int i=1;i<=n;i++){
        vv[i].push_back(i);
        int p = i;
        while(p+i <= n){
            int q = get(p+1);
            if(q == n+1) break;
            p = q+i-1;
            vv[i].push_back(p);
        }
        for(int j : v[i]) ft[j] = j+1;
    }
    int Q = read();
    while(Q--){
        int x = read(),k = read();
        if(k == 1){
            cout << "1\n";
            continue;
        }
        int p = x;
        for(int i=19;~i;i--)
            if(fa[p][i] && (vv[fa[p][i]].size() < k || vv[fa[p][i]][k-1] > x)) p = fa[p][i];
        p = fa[p][0];
        cout << dep[p] << "\n";
    }
	return 0;
}
