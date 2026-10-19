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
const int N = 2e5+10;
int n,m,tot;
char ch[N],s[N],t[N];
ll ans;
void work(int len){
	for(int i=1,j=1;i<=m;i++){
		if(s[i] != s[j]) return ;
		if(j == len) j = 1;
		else j++;
	}
	tot = 0;
	for(int i=1,j=1;i<=n;i++){
		if(j == 1 && ch[i] == 'a') continue;
		t[++tot] = ch[i];
		if(ch[i] == s[j]) j++;
		if(j > len) break;
	}
	bool flag = false;
	int sum = 0,mn = 1e9,cnt = 0;
	for(int i=1,j=1;i<=n;i++){
		if(j == 1 && ch[i] == 'a'){
			sum++;
			continue;
		}
		if(cnt && flag) mn = min(mn,sum);
		flag = false;
		sum = 0;
		if(ch[i] != t[j]) return ;
		if(j == tot) j = 1,cnt++,flag = true;
		else j++;
	}
	int lmn = 0,rmn = 0;
	for(int i=1;i<=n;i++){
		if(ch[i] != 'a') break;
		lmn++;
	}
	for(int i=n;i;i--){
		if(ch[i] != 'a') break;
		rmn++;
	}
	if(mn == 1000000000) mn = 0;
	if(cnt > 1){
		for(int i=0;i<=min(lmn,mn);i++){
			ans += min(rmn,mn-i)+1;
		}
	}else{
		ans += 1ll*(lmn+1)*(rmn+1);
	}
}
int main(){
	int T = read();
    while(T--){
        cin >> ch+1;
        n = strlen(ch+1);
		m = ans = 0;
        for(int i=1;i<=n;i++)
			if(ch[i] != 'a') s[++m] = ch[i];
		if(!m){
			cout << n-1 << "\n";
			continue;
		}
		for(int i=1;i*i<=m;i++){
			if(m % i == 0){
				work(i);
				if(m != i*i) work(m/i);
			}
		}
		cout << ans << "\n";
    }
	return 0;
}
