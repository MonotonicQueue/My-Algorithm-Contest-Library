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
string s;
int main(){
    cin >> s;
    string ans = "";
    for(int i=0;i<s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'Z') ans += s[i]-'A'+'a';
        if(s[i] == ']') break;
    }
    cout << "/";
    cout << ans;
    return 0;
}
