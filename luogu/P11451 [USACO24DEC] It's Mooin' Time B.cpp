#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 2e4+10;
int n,k;
char s[N];
int cnt[30][30];
bool flag[30][30];
vector<string> ans;
void add(int x,int y){
    if(x+2 > n || x < 1) return ;
    if(s[x+1] != s[x+2]) return ;
    if(s[x] == s[x+1]) return ;
    int a = s[x]-'a',b = s[x+1]-'a';
    cnt[a][b] += y;
    if(cnt[a][b] >= k && !flag[a][b]){
        string t = "";
        t += s[x];
        t += s[x+1];
        t += s[x+2];
        ans.push_back(t);
        flag[a][b] = true;
    }
}
int main(){
    n = read(); k = read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) add(i,1);
    for(int i=1;i<=n;i++){
        char o = s[i];
        for(char c='a';c<='z';c++){
            for(int k=i-2;k<=i;k++) add(k,-1);
            s[i] = c;
            for(int k=i-2;k<=i;k++) add(k,1);
        }
        for(int k=i-2;k<=i;k++) add(k,-1);
        s[i] = o;
        for(int k=i-2;k<=i;k++) add(k,1);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << "\n";
    return 0;
}