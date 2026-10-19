#include<bits/stdc++.h>
#define int ll
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
const int N = 30;
int n,fa[N],col[N];
char s[N][N];
vector<int> v[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    fa[get(y)] = get(x);
}
signed main(){
    n = read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    int cnt0 = 0,cnt1 = 0;
    for(int i=1;i<=n;i++) fa[i] = i;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(s[i][j] == 'S') cnt0++,merge(i,j);
            else if(s[i][j] == 'F') cnt1++,merge(i,j);
    for(int i=1;i<=n;i++) v[get(i)].push_back(i);
    sort(v+1,v+1+n,[](vector<int>a,vector<int>b){return a.size()>b.size();});
    int siz = n-n/4;
    for(int i=1;i<=n;i++){
        if(siz >= v[i].size()) siz -= v[i].size();
        else for(int x : v[i]) col[x] = 1;
    }
    if(cnt0 < cnt1){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            if(s[i][j] != '?') continue;
            if(col[i] || col[j]) s[i][j] = 'S';
            else s[i][j] = 'F';
        }
    }else{
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            if(s[i][j] != '?') continue;
            if(col[i] || col[j]) s[i][j] = 'F';
            else s[i][j] = 'S';
        }
    }
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++) cout << s[i][j];
    return 0;
}
