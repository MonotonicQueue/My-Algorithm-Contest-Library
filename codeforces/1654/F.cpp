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
const int N = (1<<18)+10;
int n,m,rk[N],pr[N];
int k,t[N];
char s[N];
bool cmp(int x,int y){
    if(pr[x] == pr[y]) return pr[x^k] < pr[y^k];
    return pr[x] < pr[y];
}
int main(){
    n = read(); m = 1<<n;
    scanf("%s",s);
    for(int i=0;i<m;i++) pr[i] = s[i]-'a';
    for(int i=0;i<m;i++) rk[i] = i;
    for(int i=1;i<=n;i++){
        k = (1<<(i-1));
        sort(rk,rk+m,cmp);
        int p = 1; t[rk[0]] = 1;
        for(int j=1;j<m;j++){
            if(cmp(rk[j-1],rk[j])) t[rk[j]] = ++p;
            else t[rk[j]] = p;
        }
        for(int j=0;j<m;j++) pr[j] = t[j];
    }
    for(int i=0;i<m;i++) putchar(s[i^rk[0]]);
	return 0;
}
