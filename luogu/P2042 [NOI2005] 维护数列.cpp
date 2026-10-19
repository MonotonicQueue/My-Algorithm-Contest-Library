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
const int N = 5e5+10;
int n,m,cnt,stk[N],top;
struct FHQ_Tree{
    int ls,rs,add,tag;
    int siz,pri,val;
    int lmx,rmx,mx,sum;
}t[N];
mt19937 rnd(time(0));
int newNode(int x){
    int cnt = stk[top--];
    t[cnt].add = -1e9; t[cnt].tag = 0;
    t[cnt].ls = t[cnt].rs = 0;
    t[cnt].siz = 1;
    t[cnt].sum =  t[cnt].val = t[cnt].mx = t[cnt].lmx = t[cnt].rmx = x;
    t[cnt].pri = rnd();
    return cnt;
}
#define lc t[rt].ls
#define rc t[rt].rs
inline void push_up(int rt){
    t[rt].siz = t[lc].siz+1+t[rc].siz;
    t[rt].sum = t[lc].sum+t[rt].val+t[rc].sum;
    t[rt].mx = max(max(t[lc].mx,t[rc].mx),t[rt].val);
    t[rt].mx = max(t[rt].mx,max(t[lc].rmx+t[rt].val,max(t[rc].lmx+t[rt].val,t[lc].rmx+t[rt].val+t[rc].lmx)));
    t[rt].lmx = max(t[lc].lmx,max(t[lc].sum+t[rt].val,t[lc].sum+t[rt].val+t[rc].lmx));
    t[rt].rmx = max(t[rc].rmx,max(t[rc].sum+t[rt].val,t[rc].sum+t[rt].val+t[lc].rmx));
}
void change(int rt,int d){
    if(!rt) return ;
    t[rt].val = t[rt].add = d;
    t[rt].sum = d*t[rt].siz;
    if(d >= 0) t[rt].mx = t[rt].lmx = t[rt].rmx = d*t[rt].siz;
    else t[rt].mx = t[rt].lmx = t[rt].rmx = d;
}
void rev(int rt){
    if(!rt) return ;
    t[rt].tag ^= 1;
    swap(lc,rc);
    swap(t[rt].lmx,t[rt].rmx);
}
void push_down(int rt){
    
    if(t[rt].add != -1e9){
        change(lc,t[rt].add);
        change(rc,t[rt].add);
        t[rt].add = -1e9;
    }
    if(t[rt].tag){
        rev(lc); rev(rc);
        t[rt].tag ^= 1;
    }
}
void split(int rt,int x,int &L,int &R){
    if(!rt) return L = R = 0,void();
    push_down(rt);
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
    push_down(L); push_down(R);
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
void clear(int rt){
    if(!rt) return ;
    stk[++top] = rt;
    clear(lc); clear(rc);
}
int main(){
    t[0].mx = t[0].lmx = t[0].rmx = -1e9;
    n = read(); m = read();
    for(int i=1;i<=500000;i++) stk[++top] = i;
    int root = 0;
    for(int i=1;i<=n;i++){
        int x = read();
        root = merge(root,newNode(x));
    }
    while(m--){
        string op; cin >> op;
        int L,R;
        if(op == "INSERT"){
            int pos = read();
            split(root,pos,L,R);
            int tot = read();
            while(tot--){
                int x = read();
                L = merge(L,newNode(x));
            }
            root = merge(L,R);
        }else if(op == "DELETE"){
            int pos = read()-1,tot = read();
            split(root,pos,L,R);
            int p;
            split(R,tot,p,R);
            clear(p);
            root = merge(L,R);
        }else if(op == "MAKE-SAME"){
            int pos = read()-1,tot = read(),c = read();
            split(root,pos,L,R);
            int p;
            split(R,tot,p,R);
            change(p,c);
            root = merge(merge(L,p),R);
        }else if(op == "REVERSE"){
            int pos = read()-1,tot = read();
            split(root,pos,L,R);
            int p;
            split(R,tot,p,R);
            rev(p);
            root = merge(merge(L,p),R);
        }else if(op == "GET-SUM"){
            int pos = read()-1,tot = read();
            split(root,pos,L,R);
            int p;
            split(R,tot,p,R);
            cout << t[p].sum << "\n";
            root = merge(merge(L,p),R);
        }else{
            cout << t[root].mx << "\n";
        }
    }
    return 0;
}
