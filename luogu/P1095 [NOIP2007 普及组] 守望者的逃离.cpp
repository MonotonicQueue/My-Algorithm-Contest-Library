#include<stdio.h>
int f[101000];
int main(){
	int m,s,t;
	scanf("%d%d%d",&m,&s,&t);
	int i,s1=0,s2=0;
	for(i=1;i<=t;i++){
		s1+=17;
		if(m>=10) s2+=60,m-=10;
		else m+=4;
		if(s2>s1) s1=s2;
		if(s1 >= s){
			printf("Yes\n%d",i);
			return 0;
		}
	}
	printf("No\n%d",s1);
	return 0;
}