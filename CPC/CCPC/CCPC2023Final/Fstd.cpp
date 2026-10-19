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
const int _ = 5e5 + 5;

int n, k, q;

vi d[_];

vector<pii> qr[_];

int cnt, bfn[_], Fa[_];

struct Bit {
	int C[_];
	void clear() {
		F(i, 0, n + 2) C[i] = 0;
	}
	void upd(int x, int v) {
		for(x = min(x, n); x; x -= x & -x) C[x] += v;
	}
	int qry(int x) {
		int res = 0;
		for(x = max(x, 1); x <= n; x += x & -x) res += C[x];
		return res;
	}
} A;

struct odt : map<int, int> {
	odt::iterator find(int p) {
		return --upper_bound(p);
	}
	void split(int p) {
		this->insert({p, find(p)->se});
	}
} B;

int L[_][21], R[_][21];

void bfs() {
	queue<int> q;
	q.push(1);
	cnt = 0;
	F(i, 1, n) bfn[i] = 0;
	Fa[1] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		bfn[u] = ++cnt;
		Debug(u, bfn[u]);
		for(int v : d[u]) if(!bfn[v]) q.push(v), Fa[v] = u;
	}
	F(i, 1, n) F(j, 0, 20) L[i][j] = R[i][j] = 0;
	F(i, 1, n) {
		int u = i;
		F(j, 0, 20) {
			L[u][j] = !L[u][j] ? bfn[i] : min(L[u][j], bfn[i]);
			R[u][j] = !R[u][j] ? bfn[i] : max(R[u][j], bfn[i]);
			u = Fa[u];
		}
	}
}

void pdg(int l, int r, int v) {
	Debug("pdg", l, r, v);
	B.split(l), B.split(r + 1);
	auto L = B.find(l), R = B.find(r + 1);
	while(L != R) {
		auto L2 = L;
		L2++;
		int len = L2->fi - L->fi;
		Debug("upd", L->fi, L2->fi - 1, L->se, -len);
		A.upd(L->se, -len);
		L = B.erase(L);
	}
	B[l] = v;
	Debug("upd", l, r, v);
	A.upd(v, r - l + 1);
}

void work(int u) {
	int id = u, cur = 0;
	while(u && cur <= k){
		if(L[u][k - cur]) pdg(L[u][k - cur], R[u][k - cur], id);
		if(k > cur && L[u][k - cur - 1]) pdg(L[u][k - cur - 1], R[u][k - cur - 1], id);
		if(u == 1 && cur < k){
			F(i, 0, k - cur - 2) if(L[u][i]){
				pdg(L[u][i], R[u][i], id);
			}
		}
		u = Fa[u], cur++;
	}
}

int ans[_];

void solve() {
	n = ri(), k = ri(), q = ri();
	F(i, 1, n) d[i].clear() ,qr[i].clear();
	F(i, 1, n - 1) {
		int u = ri(), v = ri();
		d[u].pb(v), d[v].pb(u);
	}
	F(i, 1, q) {
		int l = ri(), r = ri();
		qr[r].pb({l, i});
	}
	bfs();
	A.clear();
	B.clear();
	B[1] = 0;
	A.upd(0, n);
	B[n + 1] = 0;
	F(i, 1, n) {
		Debug(i);
		work(i);
		Debug(i);
		for(pii &v : qr[i]) {
			ans[v.se] = A.qry(v.fi);
		}
	}
	F(z, 1, q) {
		printf("%d\n", ans[z]);
	}
}
bool Med;
signed main() {
	// Mry;
	int T = ri();
	while(T--) solve();
	// Try;
	return 0;
}