#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int m,q,len,cnt;
string s;
struct node{
    int op,x;
}a[N];
int son[N][2];
int pos;
void dfs(int &x){
    x = ++cnt;
    if(s[pos] == 'x'){
        pos++;
        if(s[pos] == '<') a[x].op = 1;
        else a[x].op = 2;
        pos++;
        while(pos < len){
            if(!isdigit(s[pos])) break;
            a[x].x = a[x].x*10+s[pos]-'0';
            pos++;
        }
        assert(s[pos] == '?');
        pos++;
        dfs(son[x][0]);
        assert(s[pos] == ':');
        pos++;
        dfs(son[x][1]);
    }else{
        a[cnt].op = 3;
        while(pos < len){
            if(!isdigit(s[pos])) break;
            a[x].x = a[x].x*10+s[pos]-'0';
            pos++;
        }
    }
}
int ans[N];
void dfs0(int x,int l,int r){
    if(l > r) return ;
    if(a[x].op == 3){
        for(int i=l;i<=r;i++) ans[i] = a[x].x;
        return ;
    }
    if(a[x].op == 1){
        dfs0(son[x][0],l,a[x].x-1);
        dfs0(son[x][1],a[x].x,r);;
    }else{
        dfs0(son[x][0],a[x].x+1,r);
        dfs0(son[x][1],l,a[x].x);;
    }
}
int main(){
	// freopen("expr.in","r",stdin);
	// freopen("expr.out","w",stdout);
    m = read()+1; q =  read();
    cin >> s;
    len = s.size();
    int rt;
    dfs(rt);
    dfs0(rt,1,m);
    while(q--){
        int x = read();
        x = min(x,m);
        cout << ans[x] << "\n";
    }
    return 0;
}
