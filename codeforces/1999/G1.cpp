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
            int mid = (l+r) >> 1;
            if(ask(1,mid) == mid+1) res = mid,r = mid-1;
            else l = mid+1; 
        }
        print(res);
    }
    return 0;
}
