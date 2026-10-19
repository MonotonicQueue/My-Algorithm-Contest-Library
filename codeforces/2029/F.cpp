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
int n;
char s[N];
void solve(){
    n = read();
    scanf("%s",s+1);
    auto nxt = [&](int x)->int{
        if(x == n) return 1;
        return x+1;
    };
    int ccc = 0;
    bool f1 = false,f2 = false;
    for(int x=1;x<=n;x++){
        if(s[x] == s[nxt(x)]){
            if(s[x] == 'R') f1 = true;
            else            f2 = true;
            ccc++;
        }
    }
    if(f1 && f2) return puts("NO"),void();
    if(ccc == n) return puts("YES"),void();
    if(f2) for(int i=1;i<=n;i++) s[i] = 'R'+'B'-s[i];
    int st = 0;
    for(int i=1;i<=n;i++) if(s[i] == 'B') st = nxt(i);
    vector<int> vc;
	int ntot = 0,cnt = 0;
	for(int i=1,j=st;i<=n;i++,j=nxt(j)){
		if(s[j] == 'B') vc.push_back(ntot),cnt += (ntot&1)^1,ntot = 0;
		else ntot++;
	}
	if(vc.size() == 1 || cnt == 1){
		return puts("YES"),void();
	}
	puts("NO");
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 