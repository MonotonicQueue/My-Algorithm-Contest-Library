#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, inv2 = 499122177, rt = 3;
inline int Mod(int x) { return x + ((x >> 31) & mod); }
inline int add(int x, int y) { return Mod(x + y - mod); }
inline int sub(int x, int y) { return Mod(x - y); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
int qpow(int a, int b) {
    if (!b) return 1;
    int t = qpow(a, b >> 1);
    t = mul(t, t);
    if (b & 1) return mul(t, a);
    return t;
}
const int maxn = 100000;
namespace polynomial {
typedef vector<int> poly;
int rev[4 * maxn + 5];
inline void change(int len, int cnt) {
    for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
}
void ntt(poly& a, int len, bool type) {
    for (int i = 0; i < len; i++)
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int mid = 1; mid < len; mid <<= 1) {
        int r = mid << 1;
        int k = qpow(rt, (mod - 1) / r);
        for (int i = 0; i < len; i += r) {
            int w = 1;
            for (int j = 0; j < mid; j++, w = mul(w, k)) {
                int x = a[i + j], y = mul(w, a[i + mid + j]);
                a[i + j] = add(x, y), a[i + mid + j] = sub(x, y);
            }
        }
    }
    if (type) {
        reverse(a.begin() + 1, a.end());
        int inv = qpow(len, mod - 2);
        for (int i = 0; i < len; i++) a[i] = mul(a[i], inv);
    }
}
poly polymul(poly a, poly b) {
    int len = a.size() + b.size() - 1;
    int l = 1, c = 0;
    while (l < len) l <<= 1, c++;
    a.resize(l), b.resize(l);
    change(l, c);
    ntt(a, l, 0), ntt(b, l, 0);
    for (int i = 0; i < l; i++) a[i] = mul(a[i], b[i]);
    ntt(a, l, 1);
    a.resize(len);
    return a;
}
poly polyinv(const poly& a, int len) {
    if (len == 1) return {qpow(a[0], mod - 2)};
    int l = 1, c = 0;
    while (l < (len << 1)) l <<= 1, c++;
    poly&& b = polyinv(a, (len + 1) >> 1);
    b.resize(l);
    poly f(l);
    copy(a.begin(), a.begin() + len, f.begin());
    change(l, c);
    ntt(b, l, 0), ntt(f, l, 0);
    for (int i = 0; i < l; i++) b[i] = mul(sub(2, mul(f[i], b[i])), b[i]);
    ntt(b, l, 1);
    b.resize(len);
    return b;
}
poly polyint(const poly& a, int len) {
    poly b(len);
    for (int i = 1; i < len; i++) b[i] = mul(a[i - 1], qpow(i, mod - 2));
    return b;
}
poly polyder(const poly& a, int len) {
    poly b(len);
    for (int i = 1; i < len; i++) b[i - 1] = mul(i, a[i]);
    return b;
}
poly polyln(const poly& a, int len) {
    int l = 1, c = 0;
    while (l < (len << 1)) l <<= 1, c++;
    poly&& f = polyder(a, len);
    f.resize(l);
    poly&& g = polyinv(a, len);
    g.resize(l);
    ntt(f, l, 0), ntt(g, l, 0);
    change(l, c);
    for (int i = 0; i < l; i++) f[i] = mul(f[i], g[i]);
    ntt(f, l, 1);
    return polyint(f, len);
}
poly polyexp(const poly& a, int len) {
    if (len == 1) return {1};
    int l = 1, c = 0;
    while (l < (len << 1)) l <<= 1, c++;
    poly&& b = polyexp(a, (len + 1) >> 1);
    b.resize(l);
    poly f(l);
    copy(a.begin(), a.begin() + len, f.begin());
    poly&& g = polyln(b, len);
    g.resize(l);
    change(l, c);
    ntt(b, l, 0), ntt(f, l, 0), ntt(g, l, 0);
    for (int i = 0; i < l; i++) b[i] = mul(add(1, sub(f[i], g[i])), b[i]);
    ntt(b, l, 1);
    b.resize(len);
    return b;
}
} // namespace polynomial
using namespace polynomial;
int fac[maxn + 5], ifac[maxn + 5];
void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    ifac[n] = qpow(fac[n], mod - 2);
    for (int i = n - 1; ~i; i--) ifac[i] = mul(ifac[i + 1], i + 1);
}
inline int c2(int x) { return 1LL * x * (x - 1) / 2 % (mod - 1); }
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    init(n);
    int A[4] = {0, 0, 0, 0}, Ai[4];
    for (int i = 0; i <= k; i++) {
        scanf("%d", &A[i]);
        Ai[i] = qpow(A[i], mod - 2);
    }
    poly T(n + 1), T1(n + 1);
    T[1] = T1[1] = 1;
    for (int i = 2; i <= n; i++) {
        T[i] = mul(mul(qpow(i, i - 2), qpow(A[1], c2(i))), ifac[i]);
        T1[i] = mul(mul(T[i], qpow(Ai[2], c2(i))), i);
    }
    poly f(n + 1), g = polymul(T1, T1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = mod - T1[i];
    f = polyln(f, n + 1);
    poly cT(n + 1);
    for (int i = 1; i <= n; i++) {
        cT[i] = mul(mul(mod - add(f[i], add(T1[i], mul(g[i], inv2))), inv2), qpow(mul(A[2], Ai[0]), c2(i)));
        T[i] = add(mul(T[i], qpow(Ai[0], c2(i))), cT[i]);
    }
    T = polyexp(T, n + 1);
    for (int i = 2; i <= n; i++) printf("%d ", mul(T[i], mul(qpow(A[0], c2(i)), fac[i])));
}
