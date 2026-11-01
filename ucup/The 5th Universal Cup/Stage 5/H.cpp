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
const int N = 510;
int n;
int ask(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    cin >> x;
    return x;
}

void solve(){
    cin >> n;
    int k = 0;
    for(int i=2;i<=n;i++){
        if(ask(i-1,i)){
            k = i;
            break;
        }
    }
    if(!k){
        cout << "! ";
        for(int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
        fflush(stdout);
        return ;
    }
    deque<int> L,R;
    for(int i=1;i<k-1;i++){
        if(ask(i,k)) R.push_back(i);
        else L.push_back(i);
    }
    R.push_back(k-1);
    for(int i=k+1;i<=n;i++){
        if(ask(i,k)){
            if(R.empty()) R.push_back(i);
            else{
                if(ask(R.back(),i)) R.push_front(i);
                else R.push_back(i);    
            }
        }else{
            if(L.empty()) L.push_back(i);
            else{
                if(ask(i,L.front())) L.push_back(i);
                else L.push_front(i);  
            }
        }
    }
    cout << "! ";
    for(int x : L) cout << x << " ";
    cout << k << " ";
    for(int x : R) cout << x << " ";
    cout << "\n";
    fflush(stdout);
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
