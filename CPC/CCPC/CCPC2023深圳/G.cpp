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
const int N = 310;
const int M = 6e4+10;
int n,Q,m,k;
char s[N][M],t[M];
vector<int> v[M][30];
bitset<N> st[M][30];
int cnt[N];
int main(){
    n = read(); Q = read(); m = read(); k = read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int c = s[i][j]-'a';
            v[j][c].push_back(i);
            for(int ch=0;ch<26;ch++)
                if(c != ch) st[j][ch][i] = 1;
        }
    }
    while(Q--){
        scanf("%s",t+1);
        for(int i=1;i<=n;i++) cnt[i] = 0;
        bitset<N> now; now.reset();
        int ans = n;
        for(int i=1;i<=m;i++){
            int c = t[i]-'a';
            if((now & st[i][c]) == st[i][c]) continue;
            for(int ch=0;ch<26;ch++)
                if(ch != c) for(int x : v[i][ch]){
                        cnt[x]++;
                        if(cnt[x] == k+1) now[x] = 1,ans--;
                    }
        }
        cout << ans << "\n";
    }
	return 0;
} 
/*
6 4 4 1
kaki
kika
manu
nana
tepu
tero

kaka
mana
teri
anan
*/