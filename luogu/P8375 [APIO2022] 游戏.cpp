// #include "game.h"
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int n,k,l[N],r[N];
vector<int> in[N],out[N];
void init(int _n, int _k) {
    n = _n; k = _k;
    for(int i=0;i<k;i++)
        l[i] = i,r[i] = i;
    for(int i=k;i<n;i++)
        l[i] = -1,r[i] = k;
}
bool add(int,int);
bool add(int u){
	for(int x : in [u]) if(add(x,u)) return true;
	for(int x : out[u]) if(add(u,x)) return true;
	return false;
}
bool add(int u,int v){
    if(u < k && v < k) return v <= u;
	if(r[u] < l[v]) return false;
	if(r[v] < l[u]) return true;
	if(l[u] == l[v] && r[u] == r[v]) return false;
	int midu = (l[u]+r[u]) >> 1,midv = (l[v]+r[v]) >> 1;
	if(l[u] <= l[v] && r[v] <= midu){
		r[u] = midu;
		return l[u] == r[u] || add(u);
	}
	if(midv <  l[u] && r[u] <= r[v]){
		l[v] = midv+1;
		return l[v] == r[v] || add(v);
	}
	return false;
}
int add_teleporter(int u, int v) {
	out[u].emplace_back(v);
    in [v].emplace_back(u);
    return add(u,v);
}
