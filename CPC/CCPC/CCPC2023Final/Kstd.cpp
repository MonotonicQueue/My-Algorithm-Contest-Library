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

int n;

char str[5005][5005];

int f[5005][5005], hang[5005][5005], lie[5005][5005], s[5005][5005], g[5005][5005];

bool Med;
signed main() {
	// Mry;
	n = ri();
	F(i, 1, n) {
		scanf("%s", str[i] + 1);
	}
	F(i, 1, n) {
		hang[i][0] = 1;
		int lst1 = 0, lst0 = inf;
		F(j, 1, n) {
			if(str[i][j] == '0' && lst0 == inf) lst0 = j;
			if(str[i][j] == '1') lst1 = j;
			hang[i][j] = max(0, min(j + 1, lst0) - lst1);
		}
	}
	F(i, 1, n) {
		F(j, 1, n) {
			s[i][j] = s[i - 1][j] + (str[i][j] == '0'); // 第j列前i行0的个数
		}
	}
	F(j, 1, n) {
		lie[0][j] = 1;
		int lst1 = 0, lst0 = 1e9;
		F(i, 1, n) {
			if(str[i][j] == '0' && lst0 == 1e9) lst0 = i;
			if(str[i][j] == '1') lst1 = i;
			lie[i][j] = max(0, min(i + 1, lst0) - lst1);
		}
	}
	auto add = [&](int &x, int y) -> void {
		x += y;
		if(x >= mod) x -= mod;
	};
	g[n + 1][n + 1] = 1;
	dF(i, n + 1, 1) {
		dF(j, n + 1, 1) {
			add(f[i][j], g[i][j]);
			add(g[i - 1][j], 1ll * g[i][j] * hang[i - 1][j - 1] % mod);
			add(f[i][j - 1], 1ll * f[i][j] * lie[i - 1][j - 1] % mod); // 
			if(i >= 2 && j >= 3 && s[i - 1][j - 1] == 0 && str[i - 1][j - 2] != '1') {
				add(g[i - 1][j - 1], 1ll * f[i][j] * hang[i - 1][j - 3] % mod);
			}
		}
	}
	cout << f[1][1] << '\n';
	// Try;
	return 0;
}