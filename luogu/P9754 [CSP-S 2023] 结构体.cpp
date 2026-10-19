#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second 
using namespace std;
const int N = 110;
int Q,cnt=4;
map<string,int > mp,c;
struct node{
	ll x,y;
	int k;
	string t[N],n[N];
	ll l[N],r[N];
}a[N]; 
int m;
struct NNode{
	int id;
	ll l,r;
	string n;
}b[N];
string res;
bool ok;
void dfs(ll x,int id){
	if(id <= 4){
		return ;
	}
	for(int i=1;i<=a[id].k;i++){
		if(a[id].l[i] <= x && x <= a[id].r[i]){
			res += "."+a[id].n[i];
			dfs(x-a[id].l[i],mp[a[id].t[i]]);
			return ;
		}
	}
	ok = true;
}
int main(){
//	ios::sync_with_stdio(false);
	cin >> Q; 
	mp["byte"] = 1; mp["short"] = 2;
	mp["int"] = 3; mp["long"] = 4;
	a[1].x = a[1].y = 1;
	a[2].x = a[2].y = 2;
	a[3].x = a[3].y = 4;
	a[4].x = a[4].y = 8;
	ll T = 0;
	while(Q--){
		int op;
		cin >> op;//cout << op << " "; 
		if(op == 1){
			int k; string s;
			cin >> s >> k;
			int id = ++cnt;
			mp[s] = id;
			a[id].k = k;
			ll ans1 = 0,ans2 = 0;
			for(int i=1;i<=k;i++){
				string t,n;
				cin >> t >> n;
				a[id].t[i] = t; a[id].n[i] = n;
				ll x = a[mp[t]].x,y = a[mp[t]].y;
				ans2 = max(ans2,y);
				if(ans1 % y != 0) ans1 = ((ans1-1)/y+1)*y;
				a[id].l[i] = ans1;
				ans1 = ans1+x;
				a[id].r[i] = ans1-1;
			//	cout <<  " "<< a[id].l[i] << " " << a[id].r[i] <<"\n"; 
			}
			ans1 = ((ans1-1)/ans2+1)*ans2;
			cout << ans1 << " " << ans2 << "\n";
			a[id].x = ans1; a[id].y = ans2;
		}else if(op == 2){
			
			string t,n;
			cin >> t >> n;
			b[++m].id = mp[t];
			b[m].n = n;
			if(T % a[b[m].id].y != 0)
			T = (T/a[b[m].id].y+1)*a[b[m].id].y;
			cout <<T << "\n"; 
			b[m].l = T;
			b[m].r = T+a[mp[t]].x-1;
			c[n] = m;
			T = b[m].r+1;
		}else if(op == 3){
			string s,n = "";
			cin >> s;
			int len = s.size();
			ll ans = 0;
			int flag = 0;
			for(int i=0;i<len;i++){
				if(s[i] == '.'){
					if(!flag){
						flag = b[c[n]].id;
						ans = b[c[n]].l;
						n = "";
					}else{
						for(int j=1;j<=a[flag].k;j++){
							if(a[flag].n[j] == n){
								ans += a[flag].l[j];
								flag = mp[a[flag].t[j]];
								break;
							}
						}
						n = "";
					}
				}else n = n+s[i];
			}
			if(flag)
				for(int j=1;j<=a[flag].k;j++){
					if(a[flag].n[j] == n){
						ans += a[flag].l[j];
						flag = mp[a[flag].t[j]];
						break;
					}
				}
			else ans = b[c[n]].l;
			//if(ans == 0) cout << s <<" "; 
			cout << ans << "\n";
		}else{
			ll t; cin >> t;
			res = ""; ok = false;
			for(int i=1;i<=m;i++){
				if(b[i].l <= t && t <= b[i].r){
					res += b[i].n;
					dfs(t-b[i].l,b[i].id);
					break;
				}
			}
			if(ok || res == "") cout << "ERR\n";
			else cout << res << "\n"; 
		}
	}
	return 0;
} 
/*
1
0 0 1 1 5
*/