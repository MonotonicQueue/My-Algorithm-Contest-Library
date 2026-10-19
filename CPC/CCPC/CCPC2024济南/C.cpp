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
int n,tot;
vector<tuple<int,int,int,int>> ans;
void dfs(int x){
    if(x == 0) return ;
    if(x & 2){
        dfs((x-2)/2); tot++;
        ans.emplace_back(tot,tot+1,tot,1);
    }else{
        dfs(x-2); tot++;
        ans.emplace_back(tot,tot+1,tot,tot);
    }
}
int main(){
    n = read();
    dfs(n-1);
    tot++;
    cout << tot << "\n";
    for(auto [a,b,c,d] : ans)
        printf("POP %d GOTO %d; PUSH %d GOTO %d\n",a,b,c,d);
    printf("HALT; PUSH %d GOTO %d",tot,tot);
	return 0;
}