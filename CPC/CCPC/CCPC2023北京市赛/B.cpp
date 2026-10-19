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
const int N = 1e5+10;
int n;
char s[N];
bitset<N> now,A,B;
int main(){
    n = read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i] == '1') A[i] = 1;
        if(s[i] == '?') B[i] = 1;
    }
    int Block = 1000;
    for(int i=1;i<=n;i++){
        now = A;
        if(i <= Block){
            for(int j=i+1;j<=n;j++)
                if(B[j] && now[j-i]) now[j] = 1;
        }else{
            for(int j=i;j<=n;j+=i)
                now |= (now << i) & B;
        }
        cout << now.count() << "\n";
    }
	return 0;
}