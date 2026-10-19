#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e6+10;
int n;
char ch[N];
int t[N];
void add(int x,int y){
    while(x <= n){
        t[x] += y;
        x += x&(-x);
    }
}
int ask(int x){
    int res = 0;
    while(x){
        res += t[x];
        x -= x&(-x);
    }
    return res;
}
struct Que{
    priority_queue<int,vector<int>,greater<int>> A,B;
    int size(){
        return A.size()-B.size();
    }
    int top(){
        while(!B.empty() && A.top() == B.top()) A.pop(),B.pop();
        return A.top();
    }
    bool empty(){
        return A.size() == B.size();
    }
    void insert(int x){
        A.push(x);
    }
    void erase(int x){
        B.push(x);
    }
}s[N];

vector<int> p[N];
int len[N],nxt[N],lst[N];
int main(){
    n = read();
    scanf("%s",ch+1);
    len[0] = len[1] = 1;
    for(int i=2;i<=n;i++) len[i] = len[i>>1]+1;
    nxt[0] = 1; lst[n+1] = n;
    for(int i=1;i<=n;i++) add(i,1),nxt[i] = i+1,lst[i] = i-1;
    for(int i=1;i<=n;i++){
        if(ch[i] == '0') continue;
        for(int j=i,now=0;j<=n;j=nxt[j]){
            now = now*2+ch[j]-'0';
            if(now > n) break;
            s[now].insert(i);
            p[i].push_back(now);
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i].empty()) cout << "-1 0\n";
        else{
            cout << ask(s[i].top()) << " " << s[i].size() << "\n";
            int x = s[i].top();
            for(int j=x,CNT=1;CNT<=len[i]&&j<=n;j=nxt[j],CNT++){
                nxt[lst[j]] = nxt[j];
                lst[nxt[j]] = lst[j];
                add(j,-1);
                for(int y : p[j]) s[y].erase(j);
                p[j].clear();
            }
            for(int CNT=0,j=lst[x];CNT<=20&&j;CNT++,j=lst[j]){
                if(ch[j] == '1'){
                    for(int y : p[j]) s[y].erase(j);
                    p[j].clear();
                    for(int k=j,now=0;k<=n;k=nxt[k]){
                        now = now*2+ch[k]-'0';
                        if(now > n) break;
                        s[now].insert(j);
                        p[j].push_back(now);
                    }
                }
            }
        }
    }
    return 0;
}
