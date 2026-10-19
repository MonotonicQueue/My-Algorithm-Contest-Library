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
char s[N];
bool chk(){
    int n = strlen(s+1);
    if(n <= 2) return false;
    if(s[1] != '1' || s[2] != '0') return false;
    if(s[3] == '0') return 0;
    int x = 0;
    for(int i=3;i<=n;i++){
        x = x*10+s[i]-'0';
        if(x >= 2) return true;
    }
    return false;
}
int main(){
    int T = read();
    while(T--){
        cin >> (s+1);
        puts(chk() ? "Yes" : "No");
    }
    return 0;
}
