#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 1e5+10;
int n;
char s[N];
int cnt[N],a[N];
int main(){
	// freopen("anti.in","r",stdin);
	// freopen("anti.out","w",stdout);
	int C = read(),T = read();
	while(T--){
		n = read();
		scanf("%s",s+1);
		for(int i=0;i<26;i++) cnt[i] = 0;
		for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
		int mx = cnt[0],pos = 0;
		for(int i=1;i<26;i++)
			if(mx < cnt[i]) mx = cnt[i],pos = i;
		vector<vector<int>> ans;
		if(mx <= n/2){
			for(int i=1;i<=n;i++) a[i] = i;
			sort(a+1,a+1+n,[](int x,int y){return s[x] < s[y];});
			if(n & 1) ans.push_back({a[1],a[1+n/2],a[n]});
			else ans.push_back({a[1],a[1+n/2]});
			for(int i=2;i<=n/2;i++) ans.push_back({a[i],a[i+n/2]});
		}else{
			if(mx == n){
				puts("Shuiniao");
				continue;
			}
			if(mx == n-1){
				if((n & 1) && s[(n+1)/2] != pos+'a') puts("Shuiniao");
				else{
					puts("Huoyu");
					cout << "1\n";
					cout << n << " ";
					for(int i=1;i<=n;i++) cout << i << " ";
					cout << "\n";
				}
				continue;
			}
			int l = 0,r = 0;
			for(int i=1;i<=n;i++) if(s[i] != pos+'a'){ans.push_back({l = i}); break;}
			for(int i=n;i>=1;i--) if(s[i] != pos+'a'){ans.push_back({r = i}); break;}
			for(int i=1;i<=l-1;i++) if(s[i] == pos+'a') ans[1].push_back(i);
			for(int i=l+1;i<=n;i++) if(s[i] == pos+'a') ans[0].push_back(i);
			for(int i=l+1;i<=r-1;i++) if(s[i] != pos+'a') ans.push_back({i});
			for(auto &it : ans){
				if(it.size() >= 2) continue;
				if(ans[0].size() > 2) it.push_back(ans[0].back()),ans[0].pop_back();
				else it.push_back(ans[1].back()),ans[1].pop_back();
			}
		}
		puts("Huoyu");
		cout << ans.size() << "\n";
		for(auto &it : ans){
			sort(it.begin(),it.end());
			cout << it.size() << " ";
			for(int x : it) cout << x << " ";
			cout << "\n";
		}
	}
    return 0;
}
