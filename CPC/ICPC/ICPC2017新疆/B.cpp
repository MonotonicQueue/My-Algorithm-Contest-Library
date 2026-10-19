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
void solve(){
    vector<int> v;
    for(int i=1;i<=4;i++){
        v.push_back(read());
    }
    sort(v.begin(),v.end());
    cout << v[2]*v[3]-v[0]*v[1] << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
/*
1
6
-3 4 2 -1 1 0
*/