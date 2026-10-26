#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
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
int n,res[N];
char s[N];
int t[N];
void add(int x,int y){
    while(x <= n){
        t[x] = min(t[x],y);
        x += x&(-x);
    }
}
int ask(int x){
    int res = 1e9;
    while(x){
        res = min(res,t[x]);
        x -= x&(-x);
    }
    return res;
}
int main(){
    memset(t,0x3f,sizeof(t));
    n = read();
    scanf("%s",s+1);
    int c0 = 0,c1 = 0,c2 = 0;
    for(int i=n;i;i--){
        if(s[i] == '1') c1++;
        if(s[i] == '2') c2++;
        if(s[i] == '0') c0++;
        int l = n-i+1;
        // cerr << c1 << " " << c2 << " " << c0 << "\n";
        int u = l-2*c1,v = l-2*c2;
        if(s[i] == '0' && (l&1) && u >= 0 && v >= 0){
            // cout << u << " " << v << "\n";
            add(u,v);
        }
        if(c1*2-l >= 0){
            res[1] += 1;
            res[c1*2-l+1] -= 1;
        }else if(c2*2-l >= 0){
            res[1] += 2;
            res[c2*2-l+1] -= 2;
        }else if(c0*2-l < 0){
            if(l & 1){
                // cout << i << " " << u << " " << v << "\n";
                int k = ask(u);
                if(k > v){
                    res[1]++;
                    res[2]--;
                }
            }
        }
        
    }
    int k = 0;
    while(res[k+1]){
        k++;
        res[k] += res[k-1];
    }
    if(k == 0){
        cout << 0;
        return 0;
    }
    for(int i=1;i<=k;i++){
        res[i+1] += res[i]/10;
        res[i] %= 10;
        if(res[k+1]) k++;
    }
    while(k >= 2 && !res[k]) k--;
    while(k){
        cout << res[k];
        k--;
    }
	return 0;
}