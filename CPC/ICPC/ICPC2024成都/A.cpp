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
const int N = 1e5+10;
int n,lst[N];
char s[N],t[N];
bool chk(int x){
    if(x < 5) return false;
    if(x > n) return false;
    return true;
}
bool chk1(){
    for(int i=1;i<=n;i++)
        if(s[i] == '-') return true;
    return false;
}
void solve(){
    scanf("%s",s+1);
    n = strlen(s+1);
    for(int i=1;i<=n;i++) t[i] = '*';
    vector<pii> ans;
    lst[0] = 0;
    for(int i=1;i<=n;i++){
        lst[i] = lst[i-1];
        if(s[i] == '>') lst[i] = i;
    }
    if(s[n] == '-' || s[1] != '>') return puts("No"),void();
    if(s[n] != '>' || s[n-1] != '>' || s[n-2] != '>') return puts("No"),void();
    if(!chk1()) return puts("No"),void();
    int l = 0;
    for(int i=n;i;i--){
        if(s[i] == '-'){
            l = i+1;
            break;
        }
    }
    if(l == 0) return puts("No"),void();
    // cout << n << " " <<  l << "\n";
    vector<int> v;
    for(int i=1;i<l;i++)
        if(s[i] == '>') v.push_back(i);
    for(int i=n;i>=l+2;i--) ans.push_back(mk(1,i));
    for(int x : v){
        if(x != 1){
            ans.push_back(mk(x,l+2-x+1));
        }
    }
    cout << "Yes " << ans.size() << "\n";
    for(auto it : ans) cout << it.fi << " " << it.se << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 


