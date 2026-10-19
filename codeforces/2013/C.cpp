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
const int N = 1e6+10;
int n,a[N];
bool ask(string s){
    cout << "? " << s << endl;
    return read();
}
void solve(){
    n = read();
    string t = "";
    int T = n;
    while(T){
        if(!ask(t+"0")){
            if(!ask(t+"1")){
                break;
            }else t += "1";
        }else t += "0";
        T--;
    }
    while(T--){
        if(!ask("0"+t)) t = "1"+t;
        else t = "0"+t;
    }
    cout << "! " << t << endl;
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
