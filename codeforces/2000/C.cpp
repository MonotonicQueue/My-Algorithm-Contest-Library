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
const int N = 1e6+10;
int n,a[N],m,cnt;
char s[N];
int mat[N],c[N];
bool chk(){
    int len = strlen(s+1);
    if(len != n) return false;
    for(int i=0;i<=26;i++) mat[i] = 1e9+1;
    map<int,int> mp; mp.clear();
    for(int i=1;i<=n;i++){
        int c = s[i]-'a';
        if(mat[c] != 1e9+1){
            if(mat[c] != a[i]) return false;
        }else mat[c] = a[i],mp[a[i]]++;
        if(mp[a[i]] > 1) return false;
    }
    return true;
}
int main(){
    int T = read();
    while(T--){
        n = read(); cnt = 0;
        for(int i=1;i<=n;i++) a[i] = read();
        m = read();
        for(int i=1;i<=m;i++){
            cin >> (s+1);
            puts(chk() ? "Yes" : "No");
        }
        
    }
    return 0;
}
