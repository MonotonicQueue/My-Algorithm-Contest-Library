#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
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
int n,d,k,p[N];
vector<int> a[N];
mt19937 rnd(time(0));
void solve1(){
    int T = 5;
    auto chk = [&](int x,int y){
        int sum = 0;
        for(int i=0;i<d;i++) sum = (sum+a[x][i]*a[y][i])&1;
        return sum == 0;
    };
    while(T--){
        shuffle(p+1,p+1+n,rnd);
        vector<int> s(d);
        for(int i=1;i<=n;i++){
            int sum = 0;
            for(int j=0;j<d;j++) sum = (sum+s[j]*a[p[i]][j]) & 1;
            if(sum != (i-1) % 2){
                for(int k=1;k<i;k++)
                    if(chk(p[i],p[k])){
                        cout << min(p[i],p[k]) << " " << max(p[k],p[i]) << "\n";
                        return ;
                    }
            }
            for(int j=0;j<d;j++) s[j] = (s[j]+a[p[i]][j]) & 1;
        }
    }
    cout << "-1 -1\n";
}
void solve2(){
    int T = 1;
    auto chk = [&](int x,int y){
        int sum = 0;
        for(int i=0;i<d;i++) sum = (sum+a[x][i]*a[y][i])%3;
        return sum == 0;
    };
    while(T--){
        shuffle(p+1,p+1+n,rnd);
        vector<vector<int>> s(d);
        for(int i=0;i<d;i++) s[i].resize(d);
        for(int I=1;I<=n;I++){
            int sum = 0;
            int x = p[I];
            for(int i=0;i<d;i++)
                for(int j=0;j<d;j++) sum += s[i][j]*a[x][i]*a[x][j]%3;
            sum %= 3;
            if(sum != (I-1) % 3){
                for(int k=1;k<I;k++)
                    if(chk(x,p[k])){
                        cout << min(x,p[k]) << " " << max(x,p[k]) << "\n";
                        return ;
                    }
            }
            for(int i=0;i<d;i++)
                for(int j=0;j<d;j++) s[i][j] = (s[i][j]+a[x][i]*a[x][j])%3;
        }
    }
    cout << "-1 -1\n";
}
int main(){
    n = read(); d = read(); k = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=d;j++){
            int x = read() % k;
            a[i].emplace_back(x);
        }
    for(int i=1;i<=n;i++) p[i] = i;
    if(k == 2) solve1();
    if(k == 3) solve2();
	return 0;
}