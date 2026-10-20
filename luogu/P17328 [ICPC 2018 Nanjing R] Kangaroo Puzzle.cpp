#include <bits/stdc++.h>
using namespace std;
string s = "UDLR";
int main(){
    srand(time(NULL));
    for(int i=1;i<=50000;i++) putchar(s[rand()%4]);
    return 0;
}