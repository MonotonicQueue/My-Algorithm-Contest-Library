#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2e5+10;
int n,k,p[N],q[N];
int tot;
struct node{
    int x; bool type;
}a[N];
int st[N][20],Lg[N];
int query(int l,int r){
    if(l > r) return -1;
    int t = Lg[r-l+1];
    return min(st[l][t],st[r-(1<<t)+1][t]);
}
set<int> s;
int get(int i,node x){
    if(p[i] < x.x){
        if(p[i] & 1) return p[i]+1;
        else return p[i]-1;
    }else if(p[i] > x.x+2){
        if(p[i] & 1) return p[i]-1;
        else return p[i]+1;
    }else{
        if(!x.type){
            if(p[i] == x.x) return x.x+1;
            else if(p[i] == x.x+1) return x.x+2;
            else return x.x;
        }else{
            if(p[i] == x.x) return x.x+2;
            else if(p[i] == x.x+1) return x.x;
            else return x.x+1;
        }
    }
}
bool cmp(node x,node y){
    s.clear();
    s.insert(q[x.x]); s.insert(q[x.x+1]); s.insert(q[x.x+2]);
    s.insert(q[y.x]); s.insert(q[y.x+1]); s.insert(q[y.x+2]);
    if(min(x.x+2,y.x+2)+1 <= max(x.x,y.x)-1) s.insert(query(min(x.x+2,y.x+2)+1,max(x.x,y.x)-1));
    for(int i : s){
        int nx = get(i,x),ny = get(i,y);
        if(nx < ny) return true;
        if(nx > ny) return false;
    }
    return false;
}
void work(){
    /*
    tpye 0:
    x   x+1 x+2
    x+1 x+2 x
    
    type 1:
    x   x+1 x+2
    x+2 x  x+1
    */
    tot = 0;
    for(int i=1;i<n;i+=2){
        a[++tot] = node{i,0};
        a[++tot] = node{i,1};
    }
    for(int i=1;i<=n;i++) q[p[i]] = i;
    
    for(int i=1;i<=n;i++) st[i][0] = q[i];
    for(int j=1;j<=18;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]); 
    nth_element(a+1,a+k,a+1+tot,cmp);
    for(int i=1;i<=n;i++) cout << get(i,a[k]) << " ";
    cout << "\n";
}
void solve(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) p[i] = read();
    if(n & 1){
        if(k > n-1) return puts("-1"),void();
        work();
    }else{
        if(k > 1) return puts("-1"),void();
        for(int i=1;i<=n;i++){
            if(p[i] & 1) cout << p[i]+1 << " ";
            else cout << p[i]-1 << " ";
        }
        cout << "\n";
    }
}
int main(){
    for(int i=2;i<=200000;i++) Lg[i] = Lg[i>>1]+1;
    int T = read();
    while(T--) solve();
	return 0;
} 
/*
1
7 5
4 3 5 2 7 1 6 


5 2 4 1 6 3 7
*/