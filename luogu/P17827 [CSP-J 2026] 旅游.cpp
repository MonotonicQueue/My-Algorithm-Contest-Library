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
string s1,s2,c1,c2;
void solve(){
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if(s1[2] <= 'C' && s2[2] <= 'C' || s1[2] > 'C' && s2[2] > 'C'){
				cout << "1";
				bool flag[6] = {0,0,0,0,0,0};
				flag[s1[2]-'A'] = 1; flag[s2[2]-'A'] = 1;
				if((flag[0] && flag[1]) || (flag[1] && flag[2]) || (flag[3] && flag[5])){
					cout << "1\n";
				}else cout << "0\n";
			}else cout << "00\n";
		}else cout << "000\n";
	}else cout << "0000\n";
}
int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
