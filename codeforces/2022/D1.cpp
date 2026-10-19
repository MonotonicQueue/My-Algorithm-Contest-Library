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
int ask(int x,int y){
    cout <<"? " <<  x << " " << y << endl;
    int res = read();
    assert(res != -1);
    return res;
}
void output(int x){
    cout << "! " << x << endl;
}

int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i+=2){
            if(i == n){
                output(i);
                break;
            }
            if(ask(i,i+1) != ask(i+1,i)){
                int pos = i+1 == n ? 1 : n;
                if(ask(i,pos) != ask(pos,i)) output(i);
                else output(i+1);
                break;
            }
        }
    }
    return 0;
}