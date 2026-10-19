#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e6+10;
int n,q,tot=1; int trie[N][70],cnt[N];
map <char,int> mp;
inline void init(){
	for(int i=1;i<=26;i++)
		mp['A'+i-1] = i;
	for(int i=1;i<=26;i++)
		mp['a'+i-1] = i+26;
	for(int i=0;i<=10;i++)
		mp['0'+i] = i+53;
}
void insert(string s){
	int len = s.size() , p = 1;
	for(int i=0;i<len;i++){
		int c = mp[s[i]];
		if(!trie[p][c]) trie[p][c] = ++tot;
		p = trie[p][c]; cnt[p]++;
	}
}
int search(string s){
	int len = s.size() , p = 1;
	for(int i=0;i<len;i++){
		int c = mp[s[i]];
		p = trie[p][c];
		if(!p) return 0;
	}
	return cnt[p];
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	init();
	while(T--){
		
		for(int i=0;i<=tot;i++)
			for(int j=0;j<70;j++)
				trie[i][j] = 0;
		for(int i=0;i<=tot;i++) cnt[i] = 0;
		tot = 1;
		cin >> n >> q;
		while(n--){
			string s;
			cin >> s;
			insert(s);
		}
		while(q--){
			string s;
			cin >> s;
			cout << search(s) << "\n";
		}
	}
	return 0;
}

