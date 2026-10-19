struct frac{
    ll u,d;
    friend bool operator<(frac a,frac b){
        return a.u*b.d<b.u*a.d;
    }
    friend bool operator<=(frac a,frac b){
        return a.u*b.d<=b.u*a.d;
    }
    friend bool operator>(frac a,frac b){
        return a.u*b.d>b.u*a.d;
    }
    friend bool operator>=(frac a,frac b){
        return a.u*b.d>=b.u*a.d;
    }
    void operator+=(frac b){
        u*=b.d;
        b.u*=d;
        u+=b.u;
        d*=b.d;
    }
    friend frac operator+(frac a,frac b){
        a+=b;
        return a;
    }
    void operator-=(frac b){
        b.u=-b.u;
        u*=b.d;
        b.u*=d;
        u+=b.u;
        d*=b.d;
    }
    friend frac operator-(frac a,frac b){
        a-=b;
        return a;
    }
    void operator*=(frac b){
        u*=b.u;
        d*=b.d;
    }
    friend frac operator*(frac a,frac b){
        a*=b;
        return a;
    }
    void operator/=(frac b){
        swap(b.u,b.d);
        if(b.d<0){
            b.u=-b.u;
            b.d=-b.d;
        }
        u*=b.u;
        d*=b.d;
    }
    friend frac operator/(frac a,frac b){
        a/=b;
        return a;
    }
    friend bool operator==(frac a,frac b){
        return a.u*b.d==b.u*a.d;
    }
};