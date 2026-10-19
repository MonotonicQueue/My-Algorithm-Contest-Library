namespace fastio{
    char ibuf[1 << 20],*p1 = ibuf, *p2 = ibuf;
    #define get() p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++
    template<typename T> inline void read(T &t){
        T x = 0, f = 1;
        char c = get();
        while(!isdigit(c)){
            if(c == '-') f = -f;
            c = get();
        }
        while(isdigit(c)) x = x * 10 + c - '0', c = get();
        t = x * f;
    }
    template<typename T, typename ... Args> inline void read(T &t, Args&... args){
        read(t);
        read(args...);
    }
    template<typename T> void write(T t){
        if(t < 0) putchar('-'), t = -t;
        if(t >= 10) write(t / 10);
        putchar(t % 10 + '0');
    }
    template<typename T, typename ... Args> void write(T t, Args... args){
        write(t), putchar(' '), write(args...);
    }
    template<typename T> void writeln(T t){
        write(t);
        puts("");
    }
    template<typename T> void writes(T t){
        write(t), putchar(' ');
    }
    #undef get
};
using namespace fastio;