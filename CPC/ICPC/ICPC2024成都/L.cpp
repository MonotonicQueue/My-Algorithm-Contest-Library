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

int main(){
    int x = read(),y = read(),z = read();
    cout << "100\n";
    for(int i=1;i<=50;i++) cout << x << " ";
    for(int i=51;i<=95;i++) cout << y << " ";
    for(int i=96;i<=99;i++) cout << z << " ";
    cout << z+1;
	return 0;
} 


