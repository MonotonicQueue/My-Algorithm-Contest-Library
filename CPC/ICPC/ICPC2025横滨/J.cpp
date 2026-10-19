#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 1010;
int n,m;
char a[N][N],b[N][N];

bool work1(int lst){
	/*
	lst=0 -> I
	lst=1 -> P
	*/
	for(int i=1;i<=n;i++){
		int I=-1,C=-1,P=-1;
		for(int j=1;j<=m;j++){
			if(a[i][j] == 'I'){
				if(I != -1 && I != (j & 1)) return false;
				I = j & 1;
			}
			if(a[i][j] == 'P'){
				if(P != -1 && P != (j & 1)) return false;
				P = j & 1;
			}
			if(a[i][j] == 'C'){
				if(C != -1 && C != (j & 1)) return false;
				C = j & 1;
			}
		}
		if(I >= 0 && P >= 0) return false;
		if(I >= 0){
			if(I == C || lst == 0) return false;
			for(int j=1;j<=m;j++){
				b[i][j] = ((j&1) == I ? 'I' : 'C');
			}
			lst = 0;
		}
		if(P >= 0){
			if(P == C || lst == 1) return false;
			for(int j=1;j<=m;j++){
				b[i][j] = ((j&1) == P ? 'P' : 'C');
			}
			lst = 1;
		}
		if(I == -1 && P == -1){
			if(C == -1){
				C = 1;
			}
			// cout << lst << "\n";
			for(int j=1;j<=m;j++){
				b[i][j] = ((j&1) == C ? 'C' : (lst ? 'I' : 'P'));
			}
			lst ^= 1;
			// cout << lst << "\n";
		}
		
	}
	return true;
}
bool work2(int lst){
	/*
	lst=0 -> I
	lst=1 -> P
	*/
	for(int j=1;j<=m;j++){
		int I=-1,C=-1,P=-1;
		for(int i=1;i<=n;i++){
			if(a[i][j] == 'I'){
				if(I != -1 && I != (i & 1)) return false;
				I = i & 1;
			}
			if(a[i][j] == 'P'){
				if(P != -1 && P != (i & 1)) return false;
				P = i & 1;
			}
			if(a[i][j] == 'C'){
				if(C != -1 && C != (i & 1)) return false;
				C = i & 1;
			}
		}
		if(I >= 0 && P >= 0) return false;
		if(I >= 0){
			if(I == C || lst == 0) return false;
			for(int i=1;i<=n;i++){
				b[i][j] = ((i&1) == I ? 'I' : 'C');
			}
			lst = 0;
		}
		if(P >= 0){
			if(P == C || lst == 1) return false;
			for(int i=1;i<=n;i++){
				b[i][j] = ((i&1) == P ? 'P' : 'C');
			}
			lst = 1;
		}
		if(I == -1 && P == -1){
			if(C == -1){
				C = 1;
			}
			for(int i=1;i<=n;i++){
				b[i][j] = ((i&1) == C ? 'C' : (lst ? 'I' : 'P'));
			}
			lst ^= 1;
		}
	}
	return true;
}
bool work3(int lst){
	/*
	lst=0 -> IP
	lst=1 -> CC
	*/
	for(int i=1;i<=n;i++){
		int I=-1,C=-1,P=-1;
		for(int j=1;j<=m;j++){
			if(a[i][j] == 'I'){
				if(I != -1 && I != (j & 1)) return false;
				I = j & 1;
			}
			if(a[i][j] == 'P'){
				if(P != -1 && P != (j & 1)) return false;
				P = j & 1;
			}
			if(a[i][j] == 'C'){
				C = j & 1;
			}
		}
		if(C >= 0){
			if(I >= 0 || P >= 0) return false;
		}
		if(C >= 0){
			if(lst) return false;
			for(int j=1;j<=m;j++){
				b[i][j] = 'C';
			}
			lst = 1;
		}
		if(I >= 0 || P >= 0){
			if(P == I || lst == 0) return false;
			if(P == -1) P = (I^1);
			for(int j=1;j<=m;j++){
				b[i][j] = ((j&1) == P ? 'P' : 'I');
			}
			lst = 0;
		}
		if(I == -1 && P == -1 && C == -1){
			if(lst){
				for(int j=1;j<=m;j++)
					b[i][j] = ((j&1) ? 'P' : 'I');
			}else{
				for(int j=1;j<=m;j++)
					b[i][j] = 'C';
			}
			lst ^= 1;
		}
		
	}
	return true;
}
bool work4(int lst){
	/*
	lst=0 -> IP
	lst=1 -> CC
	*/
	for(int j=1;j<=m;j++){
		int I=-1,C=-1,P=-1;
		for(int i=1;i<=n;i++){
			if(a[i][j] == 'I'){
				if(I != -1 && I != (i & 1)) return false;
				I = i & 1;
			}
			if(a[i][j] == 'P'){
				if(P != -1 && P != (i & 1)) return false;
				P = i & 1;
			}
			if(a[i][j] == 'C'){
				C = i & 1;
			}
		}
		if(C >= 0){
			if(I >= 0 || P >= 0) return false;
		}
		if(C >= 0){
			if(lst) return false;
			for(int i=1;i<=n;i++){
				b[i][j] = 'C';
			}
			lst = 1;
		}
		if(I >= 0 || P >= 0){
			if(P == I || lst == 0) return false;
			if(P == -1) P = (I^1);
			for(int i=1;i<=n;i++){
				b[i][j] = ((i&1) == P ? 'P' : 'I');
			}
			lst = 0;
		}
		if(I == -1 && P == -1 && C == -1){
			if(lst){
				for(int i=1;i<=n;i++)
					b[i][j] = ((i&1) ? 'P' : 'I');
			}else{
				for(int i=1;i<=n;i++)
					b[i][j] = 'C';
			}
			lst ^= 1;
		}
		
	}
	return true;
}
void solve(){
	n = read(); m = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin >> a[i][j];
	if(work1(0)){
		puts("yes");
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++) cout << b[i][j];
		return ;
	}
	if(work1(1)){
		puts("yes");
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++) cout << b[i][j];
		return ;
	}
	if(work2(0)){
		puts("yes");
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++) cout << b[i][j];
		return ;
	}
	if(work2(1)){
		puts("yes");
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++) cout << b[i][j];
		return ;
	}
	if(work3(0)){
		puts("yes");
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++) cout << b[i][j];
		return ;
	}
	if(work3(1)){
		puts("yes");
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++) cout << b[i][j];
		return ;
	}
	if(work4(0)){
		puts("yes");
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++) cout << b[i][j];
		return ;
	}
	if(work4(1)){
		puts("yes");
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++) cout << b[i][j];
		return ;
	}
	puts("no");
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}