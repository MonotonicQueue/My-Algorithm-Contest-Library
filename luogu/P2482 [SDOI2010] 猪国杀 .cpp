#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXPLAYER = 15;
const int MAXCARD = 2100;
int n;                                               //玩家数 
struct Player{
	int s,nxt,lst;                                   //体力
	string id;                                       //MP主猪,ZP忠猪,FP反猪
	int cl;                                          //手牌数 
	char c[MAXCARD];                                 //P桃，K杀，D闪，F决斗，N南猪入侵，W万箭齐发，J无懈可击
	bool f;                                          //1表示装备诸哥连弩，0反之 
	bool dead;                                       //0表示活着，1死亡 
}player[MAXPLAYER];
bool ed = false;
int m,cl = 1;                                        //牌堆中牌数,现在摸到的牌数 
char card[MAXCARD];                                  //牌堆中牌
string sf[MAXPLAYER];                                //主猪眼中身份 
int fz;                                              //反贼数 
void mp(int x){                                      //摸牌 
	if(cl > m){
		player[x].c[++player[x].cl] = card[m];
	}
	else{
		player[x].c[++player[x].cl] = card[cl];	
	}
	cl++;
}
void js(int x,int y){                                 //判断击杀 
	for(int i=1;i<=player[y].cl;i++)
		if(player[y].c[i] == 'P'){
			player[y].c[i] = 'U';
			player[y].s++;
			return;
		}
	player[y].dead = 1;
	player[player[y].lst].nxt = player[y].nxt;
	player[player[y].nxt].lst = player[y].lst;
	if(y == 1){ed = true; return;}
	if(player[y].id == "FP") fz--;
	if(!fz){ed = true;return;}
	if(player[y].id == "FP"){mp(x);mp(x);mp(x);}
	if(player[x].id == "MP" && player[y].id == "ZP") player[x].cl = 0,player[x].f = false;
}
void kil(int x,int y){                                //杀 
	for(int i=1;i<=player[y].cl;i++)
		if(player[y].c[i] == 'D'){
			player[y].c[i] = 'U';
			return;
		}
	player[y].s--;
	if(!player[y].s) js(x,y);
}
bool wxkj(int x,int y,bool z){                         //无懈可击  z：0表示抵无懈可击 
	int i = x;
	while(true){
		if(z){
			if(player[i].id == sf[y] || (player[i].id == "MP" && sf[y] == "ZP") || (player[i].id == "ZP" && sf[y] == "MP"))
				for(int j=1;j<=player[i].cl;j++)
					if(player[i].c[j] == 'J'){
						player[i].c[j] = 'U';
						sf[i] = player[i].id;
						return !wxkj(i,x,0);
					}
		}
		else{
			if((sf[x] == "FP" && (player[i].id == "MP" || player[i].id == "ZP")) || (player[i].id == "FP" && (sf[x] == "MP" || sf[x] == "ZP")))
				 for(int j=1;j<=player[i].cl;j++)
					if(player[i].c[j] == 'J'){
						player[i].c[j] = 'U';
						sf[i] = player[i].id;
						return !wxkj(i,x,0);
					}
			
		}
		i = player[i].nxt;
		if(i == x) break;
	}
	return false; 
}
void nzrq(int x){                                     //南猪入侵 
	for(int i=player[x].nxt;i!=x;i=player[i].nxt){
		if(wxkj(x,i,1)) continue;
		int j;
		for(j=1;j<=player[i].cl;j++){
			if(player[i].c[j] == 'K'){
				player[i].c[j] = 'U';
				break;
			}
		}
		if(j > player[i].cl){
			player[i].s--;
			if(!player[i].s) js(x,i);
			if(i == 1 && sf[x] == "U") sf[x] = "LFP";
			if(ed) return;
		}
	}
}
void wjqf(int x){                                     //万箭齐发 
	for(int i=player[x].nxt;i!=x;i=player[i].nxt){
		if(wxkj(x,i,1)) continue;
		int j;
		for(j=1;j<=player[i].cl;j++){
			if(player[i].c[j] == 'D'){
				player[i].c[j] = 'U';
				break;
			}
		}
		if(j > player[i].cl){
			player[i].s--;
			if(i == 1 && sf[x] == "U") sf[x] = "LFP";
			if(!player[i].s) js(x,i);
			if(ed) return;
		}
	}
}
void jd(int x,int y){                                 //决斗 
	if(wxkj(x,y,1)) return;
	if(x == 1 && player[y].id == "ZP"){
		player[y].s--;
		if(!player[y].s) js(x,y);
		return;
	}
	int j,k;
	j = k = 1;
	while(true){
		for(;j<=player[y].cl;j++)
			if(player[y].c[j] == 'K')
				break;
		if(j > player[y].cl){
			player[y].s--;
			if(!player[y].s) js(x,y);
			return;
		}
		else player[y].c[j] = 'U';
		for(;k<=player[x].cl;k++)
			if(player[x].c[k] == 'K')
				break;
		if(k > player[x].cl){
			player[x].s--;
			if(!player[x].s) js(y,x);
			return;
		}
		else player[x].c[k] = 'U';
	}
}
void slove(){
	char nc;
	ed = (fz == 0);
	if(ed) return;
	for(int i=1;i;i=player[i].nxt){
		mp(i); mp(i);
		bool k = true; //判断是否能使用过杀
		for(int j=1;j<=player[i].cl;j++){
			nc = player[i].c[j];
			if(nc == 'U') continue;
			if(player[i].dead) break;
			if(nc == 'P'){
				if(player[i].s != 4) player[i].s++,player[i].c[j] = 'U';
				continue;
			}
			else if(nc == 'K'){
				if(!k && !player[i].f) continue;
				if(player[i].id == "MP" && sf[player[i].nxt] != "FP" && sf[player[i].nxt] != "LFP") continue;
				if(player[i].id == "ZP" && sf[player[i].nxt] != "FP") continue;
				if(player[i].id == "FP" && sf[player[i].nxt] != "MP" && sf[player[i].nxt] != "ZP") continue;
				player[i].c[j] = 'U';
				kil(i,player[i].nxt);
				sf[i] = player[i].id;
				k = false;
				if(ed) return;
				continue;
			}
			else if(nc == 'Z'){
				player[i].f = true;
				player[i].c[j] = 'U';
				j = 0;
				continue;
			}
			else if(nc == 'W'){
				wjqf(i);
				player[i].c[j] = 'U';
				if(ed) return;
				j=0;
				continue;
			}
			else if(nc == 'N'){
				nzrq(i);
				player[i].c[j] = 'U';
				if(ed) return;
				j=0;
				continue;
			}
			else if(nc == 'F'){
				if(player[i].id == "FP"){
					player[i].c[j] = 'U';
					jd(i,1);
					sf[i] = player[i].id;
					if(ed) return;
					j=0;
					continue;
				}
				for(int k=player[i].nxt;k!=i;k=player[k].nxt){
					if(player[i].id == "MP" && (sf[k] == "FP" || sf[k] == "LFP") || player[i].id == "ZP" && sf[k] == "FP"){
						player[i].c[j] = 'U';
						jd(i,k);
						sf[i] = player[i].id;
						if(ed) return;
						j=0;
						break;
					}
				}
				continue;
			}
		} 
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> player[i].id;
		for(int j=1;j<=4;j++) cin >> player[i].c[j];
		if(player[i].id == "FP") fz++;
		player[i].s = player[i].cl = 4;
		player[i].f = false;
		player[i].dead = false;
		player[i].nxt = i+1; player[i].lst = i-1;
	}
	player[1].lst = n; player[n].nxt = 1;
	for(int i=1;i<=m;i++) cin >> card[i];
	sf[1] = "MP"; for(int i=2;i<=n;i++) sf[i] = "U";
	slove();
	if(player[1].dead) cout << "FP\n";
	else cout << "MP\n";
	for(int i=1;i<=n;i++){
		if(player[i].dead) cout << "DEAD\n";
		else{
			for(int j=1;j<=player[i].cl;j++)
				if(player[i].c[j] != 'U' && player[i].c[j] != ' ')
					cout << player[i].c[j] << " ";
			cout <<"\n";
		}
	} 
	return 0;
}