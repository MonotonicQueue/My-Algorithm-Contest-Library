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
const int D = 10;
struct Matrix{
    int mat[D][D];
    Matrix(){
        memset(mat,0x3f,sizeof(mat));
    }
    int* operator[](const int &x){
        return mat[x];
    }
    Matrix operator*(const Matrix &o)const{
        Matrix res;
        for(int i=0;i<D;i++)
            for(int j=0;j<D;j++)
                for(int k=0;k<D;k++) res[i][j] = min(res[i][j],mat[i][k]+o.mat[k][j]);
        return res;
    }
};
int n,k;
Matrix trans[D];
char s[N];
void init(int c){
    for(int i=1;i<D;i++){
        trans[c][i][i] = i;
        trans[c][i][0] = i;
    }
    trans[c][0][c] = 0;
}
struct Queue{
    vector<pair<Matrix,Matrix>> st1,st2;
    inline void push(Matrix x){
        if(!st1.empty()) st1.push_back(mk(x,st1.back().se*x));
        else st1.push_back(mk(x,x));
    }
    inline void pop(){
        if(st2.empty()){
            st2 = st1; st1.clear();
            reverse(st2.begin(),st2.end());
            st2[0].se = st2[0].fi;
            for(int i=0;i<int(st2.size()-1);i++)
                st2[i+1].se = st2[i+1].fi*st2[i].se;
        }
        st2.pop_back();
    }
    int ask(){
        if(st1.empty()) return st2.back().se[0][0];
        if(st2.empty()) return st1.back().se[0][0];
        int ans = 1e9;
        for(int i=0;i<D;i++) ans = min(ans,st2.back().se[0][i]+st1.back().se[i][0]);
        return ans;
    }
}Q;
void solve(){
    n = read(); k = read();
    scanf("%s",s+1);
    for(int i=1;i<D;i++) init(i);
    for(int i=1;i<k;i++)
        Q.push(trans[s[i]-'0']);
    for(int i=k;i<=n;i++){
        Q.push(trans[s[i]-'0']);
        cout << Q.ask() << " ";
        Q.pop();
    }
}
int main(){
    int T = 1;
    while(T--) solve();
    return 0;
}
