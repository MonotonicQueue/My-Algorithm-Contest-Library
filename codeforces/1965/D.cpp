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
const int N = 1010;
int n,m,a[N*N];
int b[N];
void work1(){
    multiset<int> s;
    for(int i=1;i<m;i++) s.insert(a[i]);
    auto del = [&](int x){
        if(s.find(x) == s.end()) return ;
        s.erase(s.find(x));
    };
    int sum = *s.rbegin(); del(sum);
    int totsum = sum;
    for(int i=1;i<=(n+1)/2-1;i++){
        int x = *s.rbegin();
        b[i] = b[n-i+1] = sum-x;
        sum = totsum;
        for(int j=1;j<=i;j++) sum -= 2*b[j];
        del(sum);
        for(int j=i;j;j--) sum += b[j],del(sum),del(sum);
        int sss = 0;
        for(int j=i;j;j--){
            sss += b[j];
            del(sss); del(sss);
        }
        sum = x;
    }
    b[(n+1)/2] = totsum;
    for(int i=1;i<(n+1)/2;i++) b[(n+1)/2] -= 2*b[i];
    if(n % 2 == 0) b[n/2] = b[n/2+1] = b[n/2]/2;
}
void work2(){
    map<int,int> mp;
    for(int i=1;i<m;i++) mp[a[i]]++;
    vector<int> v;
    for(int i=1;i<m;i++)
        if(mp[a[i]] & 1) v.push_back(a[i]),mp[a[i]] = 0;
    sort(v.begin(),v.end());
    if(n & 1){
        b[(n+1)/2] = v[0];
        for(int i=1;i<int(v.size());i++) b[(n+1)/2+i] = b[(n+1)/2-i] = (v[i]-v[i-1])/2;
    }else{
        b[n/2] = b[n/2+1] = v[0]/2;
        for(int i=1;i<int(v.size());i++) b[n/2+i+1] = b[n/2-i] = (v[i]-v[i-1])/2;
    }
    multiset<int> s;
    auto del = [&](int x){
        if(s.find(x) == s.end()) return ;
        s.erase(s.find(x));
    };
    for(int i=1;i<m;i++) s.insert(a[i]);
    for(int i=2;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++) sum += b[j],del(sum);
    }
    b[1] = b[n] = *s.begin();
}
void solve(){
    n = read(); m = n*(n+1)/2;
    for(int i=1;i<m;i++) a[i] = read();
    sort(a+1,a+m);
    if(a[m-1] != a[m-2]) work1();
    else work2();
    for(int i=1;i<=n;i++) cout << b[i] << " ";
    cout << "\n";
}
signed main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
3
1 2 3 4 1
*/