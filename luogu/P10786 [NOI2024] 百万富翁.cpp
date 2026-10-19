// #include "richest.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> ask(vector<int> a,vector<int> b);
const int N = 1e6+10;
int cnt[N];
inline void clear(int n){
    for(int i=0;i<n;i++) cnt[i] = 0;
}
vector<int> work(vector<int> c,int k,bool flag=0){
    int n = c.size();
    int t = n/k,d = n%k;
    vector<int> siz;
    for(int i=1;i<=t;i++)
        siz.push_back(k);
    if(flag) siz.push_back(18),siz[0]--,siz[1]--,siz[2]--,siz[3]--,t++;
    else for(int i=0;i<d;i++) siz[i]++;
    vector<int> a,b;
    int l = 0;
    vector<int> ll,rr;
    for(int i=0;i<t;i++){
        ll.push_back(a.size());
        int r = l+siz[i]-1;
        for(int j=l;j<=r;j++)
            for(int jj=j+1;jj<=r;jj++)
                a.push_back(c[j]),b.push_back(c[jj]);
        rr.push_back(a.size()-1);
        l += siz[i];
    }
    vector<int> rs = ask(a,b);
    vector<int> res;
    for(int x : c) cnt[x] = 0;
    for(int i=0;i<t;i++){
        for(int j=ll[i];j<=rr[i];j++){
            cnt[rs[j]]++;
            if(cnt[rs[j]] == siz[i]-1) res.push_back(rs[j]);
        }
    }
    return res;
}
int find(vector<int> c){
    int n = c.size();
    clear(1000000);
    vector<int> a,b,rs;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            a.push_back(c[i]);
            b.push_back(c[j]);
        }
    rs = ask(a,b);
    for(int x : rs){
        cnt[x]++;
        if(cnt[x] == n-1) return x;
    }
    return -1;
}
int richest(int n, int T, int S) {
    clear(n);
    if(n == 1000){
       vector<int> c;
       for(int i=0;i<n;i++) c.push_back(i);
       return find(c);
    }else{
        vector<int> c;
        for(int i=0;i<n;i++) c.push_back(i);
        c = work(c,2); c = work(c,2);
        c = work(c,2); c = work(c,2);
        c = work(c,3); c = work(c,6);
        c = work(c,19,1); return find(c);
    }
    return 1;
}
/*
g++ grader.cpp richest.cpp -o richest -O2 -std=c++14 -static
1000 1 499500 43243
1000000 20 2000000 34234
*/