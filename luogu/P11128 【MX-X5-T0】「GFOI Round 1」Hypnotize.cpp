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
const int N = 310;
int n,k;
map<int,int> mp;
signed main(){
	n = read(); k = read();
    bool flag = false;
    for(int i=1;i<=n;i++){
        int x = read();
        mp[x] = 1;
        if(mp[x-k] || mp[x+k]) flag = true;
    }
    puts(flag ? "Yes" : "No");
    return 0;
}
