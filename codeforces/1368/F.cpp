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
const int N = 1e3+10;
int n,k,R;
int a[N];
int main(){
    n = read();
    k = sqrt(n);
    R = n-k-(n-1)/k;
    if(R <= 0){
        cout << 0 << "\n";
        return 0;
    }
    int cnt = 0;
    while(cnt != R){
        cout << k << " ";
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(a[i] || i % k == 1) continue;
            cout << i << " ";
            a[i] = 1;
            sum++; cnt++;
            if(sum == k) break;
        }
        cout << endl;
        int x = read();
        for(int i=0;i<k;i++){
            int id = (x+i-1)%n+1;
            if(a[id]){
                a[id] = 0;
                cnt--;
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}