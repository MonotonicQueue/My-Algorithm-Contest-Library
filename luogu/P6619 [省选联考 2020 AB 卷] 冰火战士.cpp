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
const int N = 2e6+10;
int n,Q;
struct Ques{
    int op,t,x,y;
}q[N];
int lsh[N];
struct BIT{
    int t[N];
    inline void add(int x,int y){
        while(x <= n){
            t[x] += y;
            x += x&(-x);
        }
    }
    inline int ask(int x){
        int res = 0;
        while(x){
            res += t[x];
            x -= x&(-x);
        }
        return res;
    }
    inline int get(int x){
        return t[x];
    }
}T[2];
int main(){
    Q = read();
    for(int i=1;i<=Q;i++){
        q[i].op = read(); q[i].t = read();
        if(q[i].op == 1){
            q[i].x  = read(); q[i].y = read();
            lsh[++n] = q[i].x;
        }
    }
    sort(lsh+1,lsh+1+n);
    n = unique(lsh+1,lsh+1+n)-lsh-1;
    for(int i=1;i<=Q;i++)
        if(q[i].op == 1) q[i].x = lower_bound(lsh+1,lsh+1+n,q[i].x)-lsh;
    int sum1 = 0;
    for(int ii=1;ii<=Q;ii++){
        int op = q[ii].op;
        if(op == 1){
            int t = q[ii].t,x = q[ii].x,y = q[ii].y;
            T[t].add(x+t,y); sum1 += t*y;
        }else{
            int t = q[q[ii].t].t,x = q[q[ii].t].x,y = q[q[ii].t].y;
            T[t].add(x+t,-y); sum1 -= t*y;
        }
        int p1 = 0,p2 = 0;
        int s0 = 0,s1 = sum1;
        for(int i=20;~i;i--){
            int np = p1+(1<<i);
            if(np > n) continue;
            int ns0 = s0+T[0].get(np),ns1 = s1-T[1].get(np);
            if(ns0 < ns1) p1 = np,s0 = ns0,s1 = ns1;
        }
        int f1 = s0,f2 = 0;
        s0 = 0,s1 = sum1;
        if(p1 < n){
            f2 = min(T[0].ask(p1+1),sum1-T[1].ask(p1+1));
            for(int i=20;~i;i--){
                int np = p2+(1<<i);
                if(np > n) continue;
                int ns0 = s0+T[0].get(np),ns1 = s1-T[1].get(np);
                if(ns0 < ns1) p2 = np,s0 = ns0,s1 = ns1;
                else if(min(ns0,ns1) == f2) p2 = np,s0 = ns0,s1 = ns1;
            }
        }
        if(max(f1,f2) == 0) puts("Peace");
        else if(f1 <= f2) cout << lsh[p2] << " " << f2*2 << "\n";
        else cout << lsh[p1] << " " << f1*2 << "\n";
    }
    return 0;
}