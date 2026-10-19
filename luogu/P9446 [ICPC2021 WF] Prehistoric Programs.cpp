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
const int M = 1e7+10;
int n;
char ch[M];
struct node{
    int sum,minn,id;
};
vector<node> a,b;
bool cmp1(node x,node y){
    return x.minn > y.minn;
}
bool cmp2(node x,node y){
    return x.minn-x.sum < y.minn-y.sum;
}
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        cin >> ch+1;
        int len = strlen(ch+1);
        int sum = 0,minn = 0;
        for(int j=1;j<=len;j++){
            sum += ch[j] == '(' ? 1 : -1;
            minn = min(sum,minn);
        }
        if(sum >= 0) a.emplace_back(node{sum,minn,i});
        else         b.emplace_back(node{sum,minn,i});
    }
    sort(a.begin(),a.end(),cmp1);
    sort(b.begin(),b.end(),cmp2);
    int sum = 0,minn = 0;
    for(auto x : a) minn = min(minn,sum+x.minn),sum += x.sum;
    for(auto x : b) minn = min(minn,sum+x.minn),sum += x.sum;
    if(sum || minn) puts("impossible");
    else{
        for(auto x : a) cout << x.id << "\n";
        for(auto x : b) cout << x.id << "\n";
    }
	return 0;
}
