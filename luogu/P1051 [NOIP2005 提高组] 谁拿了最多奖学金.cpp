#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 110;
struct stu{
	string name;
	int a1,a2;//a1期末平均成绩,a2班级评议成绩
	char b1,b2;//b1是否是学生干部,b2是否是西部省份学生
	int c;//论文数 
	int sum;//奖学金 
	int id;
}s[MAX];
bool cmp(stu a , stu b){
	return a.sum != b.sum ? a.sum > b.sum : a.id < b.id;
}
int  ans;
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> s[i].name >> s[i].a1 >> s[i].a2 >> s[i].b1 >> s[i].b2 >> s[i].c , s[i].id = i;
	for(int i=1;i<=n;i++){
		if(s[i].a1 > 80 && s[i].c) s[i].sum+=8000 , ans+=8000;
		if(s[i].a1 > 85 && s[i].a2 > 80) s[i].sum+=4000 , ans+=4000;
		if(s[i].a1 > 90) s[i].sum+=2000 , ans+=2000;
		if(s[i].a1 > 85 && s[i].b2 == 'Y')s[i].sum+= 1000, ans+=1000;
		if(s[i].a2 > 80 && s[i].b1 == 'Y') s[i].sum+= 850, ans+=850;
	}
	sort(s+1,s+1+n,cmp);
	cout << s[1].name << "\n";
	cout << s[1].sum << "\n";
	cout << ans;
	return 0;
}