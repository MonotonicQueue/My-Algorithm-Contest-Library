#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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

void solve(){
    string s;
    cin >> s;
    s = " "+s;
    int n = s.size()-1;
    for(int i=1;i<n;i++){
        if(s[i] == s[i+1]){
            cout << s[i] << s[i+1] << "\n";
            return ;
        }
    }
    for(int i=1;i+2<=n;i++){
        if(s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]){
            cout << s[i] << s[i+1] << s[i+2] << "\n";
            return ;
        }
    }
    cout << "-1\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
/*
abc
a b c
ab bc

abab
a b
ab ba
aba bab

ababa
a b
ab ba
aba bab
abab baba
ababa
*/