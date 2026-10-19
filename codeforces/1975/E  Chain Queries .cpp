#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
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
int n,Q;
int col[N],fa[N];
vector<int> G[N];
void dfs(int x,int fr){
	fa[x] = fr;
	for(int y : G[x]){
		if(y == fr) continue;
		dfs(y,x);
	}
}
int cnt[N],num_son2,num_son_more,num_black,num_father_white,xor_2;
bool chk(){
	if(num_black == 0) return false;
	if(num_black == 1) return true;
	if(num_father_white > 1) return false;
	if(num_son_more) return false;
	if(num_son2 > 1) return false;
	if(num_son2 == 1 && col[fa[xor_2]]) return false;
	return true;
}
int main(){
	int T = read();
	while(T--){
		n = read(); Q = read();
		for(int i=1;i<=n;i++) col[i] = read();
		for(int i=1;i<=n;i++){
			G[i].clear();
			cnt[i] = 0;
		}
		num_son2 = num_son_more = num_black = num_father_white = xor_2 = 0;
		for(int i=1;i<n;i++){
			int x = read(),y = read();
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++) if(col[i]){
			cnt[fa[i]]++,num_black++;
			if(!col[fa[i]]) num_father_white++;
		}
		for(int i=1;i<=n;i++)
			if(col[i]){
				if(cnt[i] >= 3) num_son_more++;
				else if(cnt[i] == 2) num_son2++,xor_2 ^= i;
			}
		while(Q--){
			int x = read();
			if(col[x]){
				num_black--;
				if(!col[fa[x]]) num_father_white--;
				num_father_white += cnt[x];
				if(cnt[x] >= 3) num_son_more--;
				else if(cnt[x] == 2) num_son2--,xor_2 ^= x;
				cnt[fa[x]]--;
				if(col[fa[x]]){
					if(cnt[fa[x]] == 2) num_son_more--,num_son2++,xor_2 ^= fa[x];
					else if(cnt[fa[x]] == 1) num_son2--,xor_2 ^= fa[x];
				}
				
			}else{
				num_black++;
				if(!col[fa[x]]) num_father_white++;
				num_father_white -= cnt[x];
				if(cnt[x] >= 3) num_son_more++;
				else if(cnt[x] == 2) num_son2++,xor_2 ^= x;
				cnt[fa[x]]++;
				if(col[fa[x]]){
					if(cnt[fa[x]] == 3) num_son_more++,num_son2--,xor_2 ^= fa[x];
					else if(cnt[fa[x]] == 2) num_son2++,xor_2 ^= fa[x];
				}
				
			}
			col[x] ^= 1;
			puts(chk() ? "YES" : "NO");
		}
	}
	return 0;
}
