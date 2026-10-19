#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 1e5+10;
int n;
char s[2][N],t[2][N];
int pa[N],pb[N],cnta[N][2],cntb[N][2];
void solve(){
	n = read();
	scanf("%s",s[0]+1); scanf("%s",s[1]+1);
	scanf("%s",t[0]+1); scanf("%s",t[1]+1);
	memset(cnta,0,sizeof(cnta));
	memset(cntb,0,sizeof(cntb));
	int ans = 0,cta = 0,ctb = 0;
	for(int i=1;i<=n;i++){
		cta += t[0][i] != t[0][i-1];
		ctb += t[1][i] != t[1][i-1];
		pa[i] = cta; pb[i] = ctb;
		cnta[cta][s[0][i]-'0']++;
		cntb[ctb][s[1][i]-'0']++;
	}
	for(int i=1;i<=n;i++){
		int ta = pa[i],tb = pb[i];
		if(t[0][i] == '0' && t[1][i] == '0'){
			ans += s[0][i] == s[1][i];
		}else if(t[0][i] == '1' && t[1][i] == '0'){
			if(cnta[ta][s[1][i]-'0']) ans++,cnta[ta][s[1][i]-'0']--;
		}else if(t[0][i] == '0' && t[1][i] == '1'){
			if(cntb[tb][s[0][i]-'0']) ans++,cntb[tb][s[0][i]-'0']--;
		}
	}
	for(int i=1;i<=n;i++){
		int ta = pa[i],tb = pb[i];
		if(t[0][i] == '1' && t[1][i] == '1'){
			if(cnta[ta][0] && cntb[tb][0]) ans++,cnta[ta][0]--,cntb[tb][0]--;
			if(cnta[ta][1] && cntb[tb][1]) ans++,cnta[ta][1]--,cntb[tb][1]--;
		}
	}
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
