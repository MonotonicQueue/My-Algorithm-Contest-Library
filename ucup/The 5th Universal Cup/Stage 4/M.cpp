#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e5+10;
int n;
string s[4];
int cnt[4],a[4];
bool flag[4];
void solve(){
    cin >> n;
    for(int i=0;i<4;i++)
        cin >> s[i];
    for(int i=0;i<4;i++){
        cnt[i] = 0;
        a[i] = 2000;
        flag[i] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(s[j][i] == 'H'){
                cnt[j]++;
            }else{
                cnt[j] = 0;
                if(s[j][i] == 'C'){

                }else if(s[j][i] == 'J'){
                    a[j] -= 50;
                }else if(s[j][i] == 'A'){
                    a[j] -= 100;
                }else{
                    a[j] -= 200;
                }
            }
        }
        for(int j=0;j<4;j++){
            if(cnt[j] == 100){
                cnt[j] = 0;
                for(int k=0;k<4;k++)
                    if(j != k) a[k] += 30;
            }
        }
        for(int j=0;j<4;j++){
            a[j] = min(a[j],2000);
            if(a[j] <= 0){
                flag[j] = true;
            }
        }
        // for(int i=0;i<4;i++) cout << a[i] << " ";
        // cout << "\n";
    }
    
    for(int i=0;i<4;i++){
        if(flag[i]) cout << "0 ";
        else cout << a[i] << " ";
    }
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
