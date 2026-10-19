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
int ask(int x,int y){
    cout << "? " << x << " " << y << endl;
    return read();
}
void print(int x){
    cout << "! " << x << endl;
}
int main(){
    int T = read();
    while(T--){
        int l = 2,r = 999,res = 0;
        while(l <= r){
            int m1 = (l+l+r)/3,m2 = (l+r+r)/3;
            int rs = ask(m1,m2);
            if(rs == (m1+1)*(m2+1)) res = m1,r = m1-1;
            else if(rs == m1*(m2+1)) res = m2,r = m2-1,l = m1+1;
            else l = m2+1;
        }
        print(res);
    }
    return 0;
}
/*
222444
690753
693565  
632778  
632021  
630436  
632025
*/