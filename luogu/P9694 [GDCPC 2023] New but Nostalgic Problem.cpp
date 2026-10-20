#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define mk make_pair
#define pii pair<ll,ll>
#define ull unsigned ll
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch)) ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e6+10;
int n,k;
char s[N];
int son[N][26],cnt,siz[N],sum[N],ed[N];
void insert(){
    int m = strlen(s+1),p = 0;
    for(int i=1;i<=m;i++){
        int c = s[i]-'a';
        if(!son[p][c]){
            son[p][c] = ++cnt;
            siz[cnt] = sum[cnt] = 0;
            sum[p]++;
        }
        p = son[p][c]; siz[p]++;
    }
    ed[p]++;
}
void dfs(int p,int k){
	k -= ed[p];
    if(k <= sum[p]) return ;
    int sz = 0,c = sum[p];
    for(int i=0;i<26;i++){
        if(!son[p][i]) continue;
        int y = son[p][i];
        c--;
        if(sz+c+siz[y] < k){
            sz += siz[y];
            continue;
        }
        putchar('a'+i);
        dfs(y,k-sz-c);
        break;
    }
}
void solve(){
    n = read(); k = read();
    for(int i=0;i<=cnt;i++){
    	sum[i] = siz[i] = ed[i] = 0;
    	for(int j=0;j<26;j++) son[i][j] = 0;
	}
    cnt = 0;
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        insert();
    }
    if(k <= sum[0]) return puts("EMPTY"),void();
    dfs(0,k);
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
5 4
ab
abc
abd
b
abcde
*/