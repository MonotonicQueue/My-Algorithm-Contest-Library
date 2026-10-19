#include<bits/stdc++.h>
using namespace std;
bool pd(string s){
	if(s[0] != 'R') return false;
	bool f = 0;
	if(s[1] > '9' || s[1] < '0') return false;
	for(int i=2;i<s.size();i++)
		if((s[i] > '9' || s[i] < '0'))
			if(s[i] == 'C' && f == 0) f = 1;
			else return false;
	return f ? true : false;  
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	//cout << char('A'-1) << endl;
	while(n--){
		string str;
		cin >> str;
		if(pd(str)){
			//cout << 1;
			int i = 0;
			int t[100],now = 0;
			int heng = 0,lie = 0;
			for(i=1;str[i] != 'C';i++)
				heng = heng*10+str[i]-'0';
			for(i=i+1;i < str.size();i++)
				lie = lie*10+str[i]-'0';
			while(lie){
				if(lie%26){
					t[++now] = lie%26;
					lie/=26;
				}
				else{
					t[++now] = 26;
					lie=lie/26-1;
				}
			}
			while(now){
				cout << char(t[now]+'A'-1);
				now--;
			}
			cout << heng << "\n";
		}
		else{
			//cout << 0;
			int i = 0;
			for(i;str[i] <='Z' && str[i] >= 'A';i++);
			int heng = 0,lie = 0;
			for(int  j = 0;j < i;j++)
				lie = lie*26+str[j]-'A'+1;
			for(int j = i;j < str.size();j++)
				heng = heng*10+str[j]-'0';
			cout << "R" << heng << "C" << lie << "\n";
		}
	}
	return 0;
}