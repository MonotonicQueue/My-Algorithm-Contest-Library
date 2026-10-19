#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 3e6+10;
const int D[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
struct node{
    int day,month,year;
}a[N],b[N];
int getday(int month,int year){
    if(month != 2) return D[month];
    if(year < 0){
        year += 1;
        if(year % 4 == 0) return 29;
        return 28;
    }else{
        if(year > 1582){
            if(year % 400 == 0) return 29;
            if(year % 100 == 0) return 28;
            if(year % 4 == 0) return 29;
            return 28;
        }else{
            if(year % 4 == 0) return 29;
            return 28;
        }
    }
}
int main(){
    // freopen("julian.in","r",stdin);
    // freopen("julian.out","w",stdout);
    a[0] = {1,1,-4713};
    for(int i=1;i;i++){
        a[i] = a[i-1];
        a[i].day += 1;
        if(a[i].day == getday(a[i].month,a[i].year)+1){
            a[i].day = 1;
            a[i].month += 1;
            if(a[i].month == 13){
                a[i].month = 1;
                a[i].year += 1;
                if(a[i].year == 0) a[i].year = 1;
            }
        }
        if(a[i].year == 1582 && a[i].month == 10 && a[i].day == 5) a[i].day = 15;
        if(a[i].year == 1600 && a[i].month == 1 && a[i].day == 1){
            // cout << i << "\n";
            break;
        }
    }
    b[0] = {31,12,1599};
    int day_400years = 0;
    for(int i=1;i;i++){
        b[i] = b[i-1];
        b[i].day += 1;
        if(b[i].day == getday(b[i].month,b[i].year)+1){
            b[i].day = 1;
            b[i].month += 1;
            if(b[i].month == 13){
                b[i].month = 1;
                b[i].year += 1;
            }
        }
        if(b[i].year == 2000){
            day_400years = i-1;
            break;
        }
    }
    int Q = read();
    while(Q--){
        ll r = read();
        if(r <= 2305447){
            printf("%d %d %d",a[r].day,a[r].month,abs(a[r].year));
            if(a[r].year < 0) printf(" BC\n");
            else printf("\n");
        }else{
            r -= 2305447;
            ll y = r/day_400years*400;
            r %= day_400years;
            y += b[r].year;
            printf("%d %d %lld\n",b[r].day,b[r].month,y);
        }
    }
    return 0;
}
