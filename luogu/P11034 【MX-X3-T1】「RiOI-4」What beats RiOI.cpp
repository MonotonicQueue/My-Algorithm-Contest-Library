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
bool chk(string s){
    for(int i=0;i<s.size();i++)
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a'-'A';
    for(int i=0;i<s.size()-3;i++)
        if(s[i] == 'r' && s[i+1] == 'i' && s[i+2] == 'o' && s[i+3] == 'i')
            return true;
    return false;
}
int main(){
    string s,t;
    cin >> s >> t;
    bool f1 = chk(s),f2 = chk(t);
    if(f1 && f2) puts("Either is ok!");
    else if(f1) cout << s << " for sure!";
    else if(f2) cout << t << " for sure!";
    else cout << "Try again!";
    return 0;
}