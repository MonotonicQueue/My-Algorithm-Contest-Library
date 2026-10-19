#define ll long long
struct FastMod {
    typedef unsigned long long ULL;
    typedef __uint128_t LLL;
    ULL b, m;
    void init(ULL b) { this->b = b, m = ULL((LLL(1) << 64) / b); }
    ULL operator()(ULL a) const {
        ULL q = (ULL)((LLL(m) * a) >> 64);
        ULL r = a - q * b;
        return r >= b ? r - b : r;
    }
}mod;
inline ll operator%(ll x, const FastMod &mod) { return mod(x); }