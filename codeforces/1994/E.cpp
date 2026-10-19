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
int k,n,a[N];

int main(){
    int T = read();
    while(T--){
        k = read();
        priority_queue<int> q;
        for(int i=1;i<=k;i++){
            n = read(); q.push(n);
            for(int j=1;j<n;j++) read();
        }
        int ans = 0;
        for(int i=19;~i;i--){
            int x = q.top();
            if((1<<i) > x) continue;
            ans |= (1<<i);
            q.pop();
            q.push(x-(1<<i));
        }
        cout << ans << "\n";
    }
	return 0;
}
