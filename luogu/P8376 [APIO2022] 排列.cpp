// #include "perm.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> construct_permutation(long long k){
    vector<int> ans;
    int n = 0;
    auto work = [&](auto self,long long x)->void{
        if(x <= 4){
            while(--x) ans.insert(ans.begin(),n++);
            return ;
        }
        if(x % 2 == 0) self(self,x/2),ans.push_back(n++);
        else if(x % 4 == 1) self(self,x-1),ans.insert(ans.begin(),n++);
        else self(self,x-3),ans.insert(ans.begin()+2,n++);
    };
    work(work,k);
	return ans;
}