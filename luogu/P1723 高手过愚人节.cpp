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
const int N = 2e7+10;
int n,tot;
char s[N],t[N];
int p[N];
void manacher(){
    int R = 0,C = 0;
    for(int i=1;i<tot;i++){
        if(i <= R) p[i] = min(R-i+1,p[2*C-i]);
        else p[i] = 1;
        while(t[i+p[i]] == t[i-p[i]]) p[i]++;
        if(i+p[i] > R) R = p[i]+i-1,C = i;
    }
}
int main(){
    int T = read();
    while(T--){
        memset(p,0,sizeof(p));
        cin >> s+1;
        n = strlen(s+1);
        t[0] = '&'; tot = 0;
        for(int i=1;i<=n;i++) t[++tot] = '|',t[++tot] = s[i];
        t[++tot] = '|'; t[++tot] = '?';
        manacher(); 
        int ans = 0;
        for(int i=1;i<tot;i++) ans = max(ans,p[i]-1);
        cout << ans << "\n";
    }
    return 0;
}
