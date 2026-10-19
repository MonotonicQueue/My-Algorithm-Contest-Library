#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
template<typename T> void debug(string s, T x) {
	cerr << "[" << s << "] = [" << x << "]\n";
}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {
	for (int i = 0, b = 0; i < (int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
	else if (s[i] == ')' || s[i] == '}') b--;
	else if (s[i] == ',' && b == 0) {
		cerr << "[" << s.substr(0, i) << "] = [" << x << "] | ";
		debug(s.substr(s.find_first_not_of(' ', i + 1)), args...);
		break;
	}
}
#ifdef ONLINE_JUDGE
#define Debug(...)
#else
#define Debug(...) debug(#__VA_ARGS__, __VA_ARGS__)
#endif
#define pb push_back
#define fi first
#define se second
#define Mry fprintf(stderr, "%.3lf MB\n", (&Med - &Mbe) / 1048576.0)
#define Try cerr << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n";
typedef long long ll;
// namespace Fread {const int SIZE = 1 << 17; char buf[SIZE], *S, *T; inline char getchar() {if (S == T) {T = (S = buf) + fread(buf, 1, SIZE, stdin); if (S == T) return '\n';} return *S++;}}
// namespace Fwrite {const int SIZE = 1 << 17; char buf[SIZE], *S = buf, *T = buf + SIZE; inline void flush() {fwrite(buf, 1, S - buf, stdout), S = buf;} inline void putchar(char c) {*S++ = c;if (S == T) flush();} struct NTR {~NTR() {flush();}} ztr;}
// #ifdef ONLINE_JUDGE
// #define getchar Fread::getchar
// #define putchar Fwrite::putchar
// #endif
inline int ri() {
	int x = 0;
	bool t = 0;
	char c = getchar();
	while (c < '0' || c > '9') t |= c == '-', c = getchar();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return t ? -x : x;
}
inline void wi(int x) {
	if (x < 0) {
		putchar('-'), x = -x;
	}
	if (x > 9) wi(x / 10);
	putchar(x % 10 + 48);
}
inline void wi(int x, char s) {
	wi(x), putchar(s);
}
bool Mbe;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int _ = 2e5 + 5;

int n, f[5005][5005][2];

char str[_];

bool Med;
signed main() {
	// Mry;
	int T = ri();
	while(T--) {
	scanf("%s", str + 1);
		n = strlen(str + 1);
		F(i, 0, n + 1) F(j, 0, n + 1) F(k, 0, 1) f[i][j][k] = -inf;
		f[0][0][0] = 0; // f[i][j][k]:考虑前i个bot，有j个人往>i的洞匹配，当前值考虑了<i的洞，要么能往右走的人的路径上无空洞
		F(i, 0, n - 1) {
			F(j, 0, i) {
				if(j) {
					if(str[i + 1] != '>') {
						f[i + 1][j - 1][0] = max(f[i + 1][j - 1][0], f[i][j][0] + 2); // 左边一个人匹配i+0.5,i+1匹配左边任意
						f[i + 1][j - 1][0] = max(f[i + 1][j - 1][0], f[i][j][1] + 1); // i匹配i+0.5,i+1匹配左边任意
						f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][1]); //i+1匹配i+0.5，i继续向右 
					}
					if(str[i + 1] != '<') {
						f[i + 1][j][1] = max(f[i + 1][j][1], f[i][j][0] + 1); // 左边一个人匹配i+0.5，i+1往右走，所以j不变
						f[i + 1][j + 1][1] = max(f[i][j + 1][1], f[i][j][1]);
						f[i + 1][j + 1][1] = max(f[i + 1][j + 1][1], f[i][j][0]);
					}
				} else {
					if(str[i + 1] != '>'){
						f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][0]);
					}
					if(str[i + 1] != '<'){
						f[i + 1][j + 1][1] = max(f[i + 1][j + 1][1], f[i][j][0]);
					}
				}
			}
		}
		int ans = 0;
		F(i, 0, n) ans = max(ans, max(f[n][i][0] + (i > 0), f[n][i][1]));
		cout << ans << '\n';
	}
	// Try;
	return 0;
}