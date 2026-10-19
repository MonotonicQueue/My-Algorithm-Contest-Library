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
const int N = 65;
ll n;
ll ask(ll l,ll r){
	if(l > n) return 0;
	r = min(r,n);
	printf("xor %lld %lld\n",l,r);
	fflush(stdout);
	return read();
}
void ans(ll a,ll b,ll c){
	printf("ans %lld %lld %lld\n",a,b,c);
	fflush(stdout);
}

void solve(){
	n = read();
	vector<pair<int,ll> >v;
	for(int i=0;(1ll << i) <= n;i++){
		ll res = ask(1ll<<i,(1ll<<(i+1))-1);
		if(res) v.push_back(mk(i,res));
	}
	if(v.size() == 3){
		ans(v[0].se,v[1].se,v[2].se);
	}else if(v.size() == 2){
		ll c = 0,id = 0,sum = 0,pre = 0;
		if((v[0].se >> v[0].fi) & 1) c = v[0].se,id = v[1].fi,sum = v[1].se;
		else c = v[1].se,id = v[0].fi,sum = v[0].se;
		pre = 1ll << id;
		for(int i=id-1;~i;i--){
			ll res = ask(pre|(1ll<<i),pre|((1ll<<(i+1))-1));
			if((sum >> i) & 1){
				ans(c,sum^res,res);
				return ;
			}else{
				if(res) pre |= 1ll<<i;
			}
		}
	}else{
		ll sum = v[0].se,id = v[0].fi,c = 0;
		ll pre = 1ll << id;
		// cout << pre << " " << id << "\n";
		for(int i=id-1;~i;i--){
			if((pre|(1ll << i)) > n) continue;
			ll res = ask(pre|(1ll<<i),pre|((1ll<<(i+1))-1));
			if(!c){
				if((sum >> i) & 1){
					if(res^sum){
						c = res;
						sum ^= res;
					}else pre |= 1ll << i;
				}else{
					if(res){
						c = sum^res;
						sum = res;
						pre |= 1ll << i;
					}
				}
			}else{
				if((sum >> i) & 1){
					ans(c,sum^res,res);
					return ;
				}else{
					if(res) pre |= 1ll<<i;
				}
			}
		}
	}
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 