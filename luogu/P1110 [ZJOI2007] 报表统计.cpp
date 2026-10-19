#include<bits/stdc++.h>
using namespace std;
const int N=500000+10,INF=2e9;
int read(){
	int x=0,hhh=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') hhh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*hhh;
}
int ans2=INF;
struct sghhh{ int q,h; }a[N];
struct treap{
	int l,r,val,dat,cnt,size;
}tr[N<<2];
int tot,root,root2,n,m;
int New(int val){
	tr[++tot].val=val;
	tr[tot].dat=rand();
	tr[tot].cnt=tr[tot].size=1;
	return tot;
}
void Update(int p){ tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+tr[p].cnt; }
void Build(){
	New(-INF),New(INF);
	root=1,tr[1].r=2;
	New(-INF),New(INF);
	root2=3,tr[3].r=4;
	Update(root);
}
void zip(int &p){
	int q=tr[p].l;
	tr[p].l=tr[q].r,tr[q].r=p,p=q;
	Update(tr[p].r),Update(p);
}
void zap(int &p){
	int q=tr[p].r;
	tr[p].r=tr[q].l,tr[q].l=p,p=q;
	Update(tr[p].l),Update(p);
}
void Insert(int &p,int val){
	if(p==0) { p=New(val); return; }
	if(val==tr[p].val) { ++tr[p].cnt,Update(p); return; }
	if(val<tr[p].val)
	{
		Insert(tr[p].l,val);
		if(tr[p].dat<tr[tr[p].l].dat) zip(p);
	}
	else
	{
		Insert(tr[p].r,val);
		if(tr[p].dat<tr[tr[p].r].dat) zap(p);
	}
	Update(p);
}
int Getpre(int val){
	int ans=1,p=root;
	while(p)
	{
		if(val==tr[p].val)
		{
			if(tr[p].cnt>1) ans=p;
			else if(tr[p].l>0)
			{
				p=tr[p].l;
				while(tr[p].r) p=tr[p].r;
				ans=p;
			}
			break;
		}
		if(tr[p].val<val&&tr[p].val>tr[ans].val) ans=p;
		p=val<tr[p].val?tr[p].l:tr[p].r;
	}
	return tr[ans].val;
}
int Getnext(int val){
	int ans=2,p=root;
	while(p)
	{
		if(val==tr[p].val)
		{
			if(tr[p].cnt>1) ans=p;
			else if(tr[p].r>0)
			{
				p=tr[p].r;
				while(tr[p].l) p=tr[p].l;
				ans=p;
			}
			break;
		}
		if(tr[p].val>val&&tr[p].val<tr[ans].val) ans=p;
		p=val<tr[p].val?tr[p].l:tr[p].r;
	}
	return tr[ans].val;
}
int Getvalbyrank(int p,int rank){
	if(p==0) return INF;
	if(tr[tr[p].l].size>=rank) return Getvalbyrank(tr[p].l,rank);
	if(tr[tr[p].l].size+tr[p].cnt>=rank) return tr[p].val;
	return Getvalbyrank(tr[p].r,rank-tr[tr[p].l].size-tr[p].cnt);
}
void Remove(int &p,int val){
	if(p==0) return;
	if(val==tr[p].val)
	{
		if(tr[p].cnt>1)
		{
			--tr[p].cnt,Update(p);
			return;
		}
		if(tr[p].l||tr[p].r)
		{
			if(tr[p].r==0||tr[tr[p].l].dat>tr[tr[p].r].dat) zip(p),Remove(tr[p].r,val);
			else zap(p),Remove(tr[p].l,val);
			Update(p);
		}
		else p=0;
		return;
	}
	val<tr[p].val?Remove(tr[p].l,val):Remove(tr[p].r,val);
	Update(p);
}
int main()
{
	n=read(),m=read();
	Build();
	a[1].q=a[1].h=read(),Insert(root,a[1].q);
	for(int i=2;i<=n;++i)
	{
		a[i].q=a[i].h=read(),Insert(root,a[i].q);
		int sg=abs(a[i].q-a[i-1].h);
		Insert(root2,sg);
		sg=Getpre(a[i].h);
		if(sg!=-INF) ans2=min(ans2,a[i].h-sg);
		sg=Getnext(a[i].h);
		if(sg!=INF)  ans2=min(ans2,sg-a[i].h);
	}
	while(m--)
	{
		char op[20];
		scanf("%s",op+1);
		if(op[1]=='I')
		{
			int i=read(),k=read();
			if(i!=n) Remove(root2,abs(a[i].h-a[1+i].q)),Insert(root2,abs(k-a[i+1].q));
			Insert(root2,abs(k-a[i].h));
			a[i].h=k;
			Insert(root,k);
			int yz=Getpre(k),eb=Getnext(k);
			if(yz!=-INF) ans2=min(ans2,k-yz);
			if(eb!=INF) ans2=min(ans2,eb-k);
		}
		else if(op[5]=='G') printf("%d\n",Getvalbyrank(root2,2));
		else printf("%d\n",ans2);
	}
	return 0;
}