#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
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
int n,a[N];
int solve(){
    deque<pii> q1,q2;
    for(int i=1;i<=n;i++) q1.push_back(mk(a[i],i));
    int ans = 0;
    while(true){
        if(q1.size()+q2.size() == 2) return ans = 1;
        int x,id,y;
        y = q1.front().fi; q1.pop_front();
        if(q2.empty() || (!q1.empty() && q1.back() > q2.back())) x = q1.back().fi,id = q1.back().se,q1.pop_back();
        else x = q2.back().fi,id = q2.back().se,q2.pop_back();
        pii now = mk(x-y,id);
        if(q1.empty() || q1.front() > now){
            ans = q1.size()+q2.size()+2;
            int cnt = 0;
            while(true){
                cnt++;
                if(q1.size()+q2.size() == 1){
                    if(cnt % 2 == 0) ans--;
                    return ans;
                }
                int x,id;
                if(q2.empty() || (!q1.empty() && q1.back() > q2.back())) x = q1.back().fi,id = q1.back().se,q1.pop_back();
                else x = q2.back().fi,id = q2.back().se,q2.pop_back();
                now = mk(x-now.fi,id);
                if((!q1.empty() && q1.front() < now) || (!q2.empty() && q2.front() < now)){
                    if(cnt % 2 == 0) ans--;
                    return ans;
                }
            }
            return ans;
        }else q2.push_front(now);
    }
}
int main(){
    // freopen("snakes.in","r",stdin);
    // freopen("snakes.out","w",stdout);
    int T = read();
    for(int TTT=1;TTT<=T;TTT++){
        if(TTT == 1){
            n = read();
            for(int i=1;i<=n;i++) a[i] = read();
        }else{
            int k = read();
            for(int i=1;i<=k;i++){
                int id = read();
                a[id] = read();
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}