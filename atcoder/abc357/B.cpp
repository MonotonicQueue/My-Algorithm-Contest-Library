#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 110;
string s;
int main(){
	cin >> s;
    int cnt1 = 0,cnt2 = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] >= 'a' && s[i] <= 'z') cnt1++;
        else cnt2++;
    }
    for(int i=0;i<s.size();i++){
        if(cnt1 > cnt2){
            if(s[i] >= 'A' && s[i] <= 'Z') cout << char(s[i]-'A'+'a');
            else cout << s[i];
        }else{
            if(s[i] >= 'a' && s[i] <= 'z') cout << char(s[i]-'a'+'A');
            else cout << s[i];
        }
    }
	return 0;
}
