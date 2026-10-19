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
int n,m;
int d[N],tot;
void div(int x){
    tot = 0;
    for(int i=1;i<=x;i++)
        if(x % i == 0) d[++tot] = i;
}
int ans[N];
signed main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        div(n);
        int p = 0;
        for(int i=tot;i;i--){
            p = d[i];
            // if(p > m) break;
            bool flag = true;
            vector<int> v1,v2;
            for(int i=1;i<=n;i++)
                if(i % p == 0) v1.push_back(i);
                else v2.push_back(i);
            for(int i=1;i<=n;i++){
                if(i % m == 0){
                    if(v1.empty()){
                        flag = false;
                        break;
                    }
                    ans[i] = v1.back();
                    v1.pop_back();
                }else{
                    if(!v2.empty()){
                        if(i <= n-n%m && v2.back() > v1.back()){
                            flag = false;
                            break;
                        }
                        ans[i] = v2.back(),v2.pop_back();
                    }
                    else ans[i] = v1.back(),v1.pop_back();
                }
            } 
            if(flag) break;  
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
