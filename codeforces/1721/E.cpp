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
const int N = 1e6+114514;
int n,m,kmp[N],nxt[N][26];
char s[N],t[N];
int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    for(int i=2,j=0;i<=n;i++){
        while(j && s[j+1] != s[i]) j = kmp[j];
        if(s[j+1] == s[i]) j++;
        kmp[i] = j;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<26;j++)
            nxt[i][j] = nxt[kmp[i]][j];
        if(i != n) nxt[i][s[i+1]-'a'] = i+1;
    }
    int Q = read();
    while(Q--){
        scanf("%s",t+1);
        m = strlen(t+1);
        for(int i=n+1;i<=n+m;i++) s[i] = t[i-n];
        int tmp[26];
        for(int i=0;i<26;i++) tmp[i] = nxt[n][i];
        for(int i=n+1,j=kmp[n];i<=n+m;i++){
            nxt[i-1][s[i]-'a'] = i;
            j = kmp[i] = nxt[j][s[i]-'a'];
            for(int c=0;c<26;c++)
                nxt[i][c] = nxt[kmp[i]][c];
            cout << j << " ";
        }
        for(int i=0;i<26;i++) nxt[n][i] = tmp[i];
        cout << "\n";
    }
    return 0;
}