#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 4e5+10;
int n,a[N];
int son[N*30][2],cnt;
void insert(int x){
    int p = 0;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1;
        if(!son[p][c]) son[p][c] = ++cnt;
        p = son[p][c];
    }
}
int query(int x){
    int res = 0,p = 0;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1;
        if(son[p][!c]){
            p = son[p][!c];
            res += (1<<i);
        }else p = son[p][c];
    }
    return max(res,x);
}
int sum[N],pre[N],suf[N];
int main(){
	n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]^a[i];
        insert(sum[i]);
        pre[i] = max(pre[i-1],query(sum[i]));
    }
    cnt = 0;
    memset(son,0,sizeof(son));
    for(int i=n;i;i--){
        sum[i] = sum[i+1]^a[i];
        insert(sum[i]);
        suf[i] = max(suf[i+1],query(sum[i]));
    }
    int ans = 0;
    for(int i=1;i<n;i++) ans = max(ans,pre[i]+suf[i+1]);
    cout << ans;
	return 0;
}