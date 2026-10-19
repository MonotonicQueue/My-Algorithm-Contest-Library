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
const int N = 2e5+10;
int n,L;
struct node{
    int l,r;
    int val(){
        if(l == -1) return r;
        return l;
    }
};
bool cmp(node x,node y){
    return x.val() < y.val();
}
int main(){
    int T = read();
    while(T--){
        n = read(); L = read();
        int cnt = 0;
        vector<node> v;
        for(int i=1;i<=n;i++){
            int l = read(),r = read();
            if(l == -1 && r == -1) cnt++;
            else v.push_back(node{l,r});
        }
        v.push_back(node{-1,0});
        v.push_back(node{L+1,-1});
        sort(v.begin(),v.end(),cmp);
        bool flag = true;
        int mn = 0,mx = 0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i].r == -1){
                if(v[i+1].l == -1){
                    flag &= v[i].l < v[i+1].r;
                    mx += v[i+1].r-v[i].l-1;
                }else{
                    flag &= v[i].l < v[i+1].l;
                    mx += v[i+1].l-v[i].l-1;
                }
            }else{
                if(v[i+1].l == -1){
                    flag &= v[i].r < v[i+1].r;
                    mx += v[i+1].r-v[i].r-1;
                }else{
                    flag &= v[i].r < v[i+1].l;
                    mx += v[i+1].l-v[i].r-1;
                    if(v[i+1].l-v[i].r > 1) mn++;
                }
            }
        }
        if(flag && mn <= cnt && cnt <= mx) puts("TAK");
        else puts("NIE");
    }
    return 0;
}
