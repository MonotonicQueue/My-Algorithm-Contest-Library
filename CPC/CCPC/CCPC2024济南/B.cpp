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
const int N = 100;
int n;
struct node{
    int cnt,t;
}a[N];
int t5,t6;
void solve(){
    n = read();
    for(int i=1;i<=4;i++) a[i].cnt = 0;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        if(s[1] == 'D') a[1].cnt++;
        if(s[1] == 'C') a[2].cnt++;
        if(s[1] == 'H') a[3].cnt++;
        if(s[1] == 'S') a[4].cnt++;
    }
    for(int i=1;i<=4;i++) a[i].t = read()*3;
    t5 = read(),t6 = read();
    int ans = 0;
    for(int i=1;i<=4;i++) ans += a[i].cnt/5,a[i].cnt %= 5;
    
    while(true){
        sort(a+1,a+5,[](node x,node y){return x.cnt+x.t > y.cnt+y.t;});
        int rest = 0;
        for(int i=2;i<=4;i++) rest += a[i].cnt;
        if(a[1].cnt+rest < 5) break;
        int k = min(a[1].t,min(rest,5-a[1].cnt));
        a[1].cnt += k; rest -= k;
        a[1].t -= k;
        for(int i=4;i>=2;i--)
            while(a[i].cnt && k) a[i].cnt--,k--;
        assert(k == 0);
        if(a[1].cnt == 5){
            ans++;
            a[1].cnt = 0;
            continue;
        }
        if(t6 && rest){
            a[1].cnt++; rest--; t6 = 0;
            k = 1;
            for(int i=4;i>=2;i--)
                while(a[i].cnt && k) a[i].cnt--,k--;
            if(a[1].cnt == 5){
                ans++;
                a[1].cnt = 0;
                continue;
            }
        }
        if(t5 && rest){
            a[1].cnt++; rest--; t5 = 0;
            k = 1;
            for(int i=4;i>=2;i--)
                while(a[i].cnt && k) a[i].cnt--,k--;
            if(a[1].cnt == 5){
                ans++;
                a[1].cnt = 0;
                continue;
            }
        }
        break;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}
