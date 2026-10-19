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
int a[10][10];
bool chk(){
    for(int i=1;i<=5;i++){
        bool flag = true;
        for(int j=1;j<=5;j++){
            flag &= a[i][j];
        }
        if(flag) return true;
    }
    for(int i=1;i<=5;i++){
        bool flag = true;
        for(int j=1;j<=5;j++){
            flag &= a[j][i];
        }
        if(flag) return true;
    }
    bool flag = true;
    for(int i=1;i<=5;i++)
        flag &= a[i][i];
    if(flag) return  true;
    for(int i=1;i<=5;i++)
        if(!a[i][5-i+1]) return false;
    return true;
}
int main(){
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++) a[i][j] = read();
    puts(chk() ? "Yes" : "No");
    return 0;
}