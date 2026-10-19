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
int n;
map<pii,int> mp;
int ask(int x,int y){
    assert(x != y);
    if(mp.find(mk(x,y)) != mp.end()) return mp[mk(x,y)];
    cout << "? " <<  x << " " << y << endl;
    return mp[mk(x,y)] = read();
}
void output(int x){
    cout << "! " << x << endl;
}
int main(){
    int T = read();
    while(T--){
        n = read();
        mp.clear();
        int i = 1;
        if((n & 1) && n > 3){
            if(!(ask(1,2)^ask(2,3)^ask(3,1))){
                if(ask(1,2) == ask(2,1)){output(3); continue;}
                if(ask(1,3) == ask(3,1)){output(2); continue;}
                output(1); continue;
            }
            i = 4;
        }
        for(;i<=n;i+=2){
            if(i == n){
                output(i);
                break;
            }
            if(i == n-1 || ask(i,i+1) != ask(i+1,i)){
                int pos = i+1 == n ? 1 : n;
                if(ask(i,pos) != ask(pos,i)) output(i);
                else output(i+1);
                break;
            }
        }
    }
    return 0;
}