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
int n,cnt;
struct FHQ_Tree{
    int ls,rs;
    int siz,pri;
}t[N];
mt19937 rnd(time(0));
int newNode(){
    ++cnt;
    t[cnt].ls = t[cnt].rs = 0;
    t[cnt].siz = 1;
    t[cnt].pri = rnd();
    return cnt;
}
inline void push_up(int rt){
    t[rt].siz = t[t[rt].ls].siz+1+t[t[rt].rs].siz;
}
void split(int rt,int x,int &L,int &R){
    if(!rt) return L = R = 0,void();
    if(t[t[rt].ls].siz+1 <= x){
        L = rt;
        split(t[rt].rs,x-t[t[rt].ls].siz-1,t[rt].rs,R);
    }else{
        R = rt;
        split(t[rt].ls,x,L,t[rt].ls);
    }
    push_up(rt);
}
int merge(int L,int R){
    if(!L || !R) return L+R;
    if(t[L].pri > t[R].pri){
        t[L].rs = merge(t[L].rs,R);
        push_up(L);
        return L;
    }else{
        t[R].ls = merge(L,t[R].ls);
        push_up(R);
        return R;
    }
}
int main(){
    
    return 0;
}
