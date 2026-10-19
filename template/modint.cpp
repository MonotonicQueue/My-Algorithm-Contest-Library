const int mod1 = 998244353,mod2 = 1e9+7,mod3 = 1e9+9;
struct modint{
    long long x1,x2,x3;
    modint operator+(const int &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1+x < mod1 ? res.x1+x : res.x1+x-mod1;
        res.x2 = res.x2+x < mod2 ? res.x2+x : res.x2+x-mod2;
        res.x3 = res.x3+x < mod3 ? res.x3+x : res.x3+x-mod3;
        return res;
    }
    modint operator-(const int &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1-x > 0 ? res.x1-x : res.x1-x+mod1;
        res.x2 = res.x2-x > 0 ? res.x2-x : res.x2-x+mod2;
        res.x3 = res.x3-x > 0 ? res.x3-x : res.x3-x+mod3;
        return res;
    }
    modint operator*(const int &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1*x%mod1;
        res.x2 = res.x2*x%mod2;
        res.x3 = res.x3*x%mod3;
        return res;
    }
    modint operator+(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1+x.x1 < mod1 ? res.x1+x.x1 : res.x1+x.x1-mod1;
        res.x2 = res.x2+x.x2 < mod2 ? res.x2+x.x2 : res.x2+x.x2-mod2;
        res.x3 = res.x3+x.x3 < mod3 ? res.x3+x.x3 : res.x3+x.x3-mod3;
        return res;
    }
    modint operator-(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1-x.x1 > 0 ? res.x1-x.x1 : res.x1-x.x1+mod1;
        res.x2 = res.x2-x.x2 > 0 ? res.x2-x.x2 : res.x2-x.x2+mod2;
        res.x3 = res.x3-x.x3 > 0 ? res.x3-x.x3 : res.x3-x.x3+mod3;
        return res;
    }
    modint operator*(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1*x.x1%mod1;
        res.x2 = res.x2*x.x2%mod2;
        res.x3 = res.x3*x.x3%mod3;
        return res;
    }
    bool operator<(const modint x)const{
        if(x1 != x.x1) return x1 < x.x1;
        if(x2 != x.x2) return x2 < x.x2;
        return x3 < x.x3;
    }
    bool operator == (const modint x)const{
        return x1 == x.x1 && x2 == x.x2 && x3 == x.x3;
    }
    bool operator != (const modint x)const{
        return x1 != x.x1 || x2 != x.x2 || x3 != x.x3;
    }
};