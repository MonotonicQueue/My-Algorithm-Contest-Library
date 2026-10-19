// 高精度
const int BigNumLen = 100005;
struct BigNum
{
    int len, num[BigNumLen];
    bool isNeg; // 是否为负数
    BigNum()
    {
        len = 1;
        isNeg = false;
        memset(num, 0, sizeof(num));
    }
    BigNum(long long x)
    {
        if (x < 0)
        {
            isNeg = true;
            x = -x;
        }
        else
            isNeg = false;
        this->len = 0;
        while (x)
        {
            num[++this->len] = x % 10;
            x /= 10;
        }
    }
    BigNum(string s)
    {
        if (s[0] == '-')
        {
            isNeg = true;
            s = s.substr(1);
        }
        else
            isNeg = false;
        this->len = s.size();
        for (int i = 0; i < s.size(); i++)
            this->num[s.size() - i] = s[i] - '0';
    }
    BigNum &operator=(const BigNum &other)
    {
        if (this == &other) // 检查自我赋值情况
            return *this;
 
        this->len = other.len;
        this->isNeg = other.isNeg;
        memcpy(this->num, other.num, sizeof(other.num));
 
        return *this;
    }
    friend BigNum operator-(const BigNum &a)
    {
        BigNum res = a;
        res.isNeg = !res.isNeg;
        return res;
    }
    friend BigNum ABS(const BigNum &a)
    {
        if (a.isNeg)
            return -a;
        return a;
    }
    friend bool operator>(const BigNum &a, const BigNum &b)
    {
        if (a.isNeg != b.isNeg)
            return b.isNeg;
        if (a.len != b.len)
            return a.isNeg ? a.len < b.len : a.len > b.len;
        for (int i = a.len; i > 0; --i)
        {
            if (a.num[i] != b.num[i])
                return a.isNeg ? a.num[i] < b.num[i] : a.num[i] > b.num[i];
        }
        return false;
    }
    friend bool operator<(const BigNum &a, const BigNum &b)
    {
        return b > a;
    }
    friend bool operator>=(const BigNum &a, const BigNum &b)
    {
        return !(a < b);
    }
    friend bool operator<=(const BigNum &a, const BigNum &b)
    {
        return !(a > b);
    }
 
    friend BigNum operator+(const BigNum &a, const BigNum &b)
    {
        BigNum res;
        if (a.isNeg == b.isNeg)
        {
            res.isNeg = a.isNeg;
            res.len = max(a.len, b.len);
            int carry = 0;
            for (int i = 1; i <= res.len; ++i)
            {
                res.num[i] = a.num[i] + b.num[i] + carry;
                carry = res.num[i] / 10;
                res.num[i] %= 10;
            }
            if (carry)
                res.num[++res.len] = carry;
        }
        else
        {
            BigNum absA = ABS(a);
            BigNum absB = ABS(b);
            if (absA > absB)
            {
                res = absA - absB;
                res.isNeg = a.isNeg;
            }
            else
            {
                res = absB - absA;
                res.isNeg = b.isNeg;
            }
        }
        return res;
    }
    friend BigNum &operator+=(BigNum &a, const BigNum &b)
    {
        a = a + b;
        return a;
    }
 
    friend BigNum operator-(const BigNum &a, const BigNum &b)
    {
        BigNum res;
        if (a.isNeg == b.isNeg)
        {
            BigNum absA = ABS(a);
            BigNum absB = ABS(b);
            if (absA >= absB)
            {
                res.isNeg = a.isNeg;
                res.len = a.len;
                for (int i = 1; i <= a.len; ++i)
                {
                    if (absA.num[i] < absB.num[i])
                    {
                        absA.num[i] += 10;
                        absA.num[i + 1] -= 1;
                    }
                    res.num[i] = absA.num[i] - absB.num[i];
                }
                while (res.len > 1 && res.num[res.len] == 0)
                    --res.len;
            }
            else
            {
                res = absB - absA;
                res.isNeg = !a.isNeg;
            }
        }
        else
        {
            res = a + (-b);
        }
        if (res.len == 1 && res.num[1] == 0) // 防止出现-0的情况
            res.isNeg = false;
        return res;
    }
    friend BigNum &operator-=(BigNum &a, const BigNum &b)
    {
        a = a - b;
        return a;
    }
 
    friend BigNum operator*(const BigNum &a, const BigNum &b)
    {
        BigNum res;
        res.len = a.len + b.len - 1;
        for (int i = 1; i <= a.len; ++i)
        {
            for (int j = 1; j <= b.len; ++j)
            {
                res.num[i + j - 1] += a.num[i] * b.num[j];
            }
        }
        for (int i = 1; i <= res.len; ++i)
        {
            res.num[i + 1] += res.num[i] / 10;
            res.num[i] %= 10;
        }
        while (res.num[res.len + 1] > 0)
        {
            ++res.len;
            res.num[res.len + 1] += res.num[res.len] / 10;
            res.num[res.len] %= 10;
        }
        while (res.len > 1 && res.num[res.len] == 0)
            --res.len;                 // 检查最高位是否为0
        res.isNeg = a.isNeg ^ b.isNeg; // 如果a和b的符号不同，那么结果为负数
        if (res.len == 1 && res.num[1] == 0)
            res.isNeg = false; // 如果结果为0，确保isNeg为false
        return res;
    }
    friend BigNum &operator*=(BigNum &a, const BigNum &b)
    {
        a = a * b;
        return a;
    }
 
    friend BigNum operator/(const BigNum &a, const long long &b)
    {
        if (b == 0)
            throw runtime_error("Division by zero!"); // 除数为0时抛出异常
        BigNum res = a;
        long long remainder = 0;
        long long absB = abs(b);
        for (int i = res.len; i > 0; --i)
        {
            long long temp = remainder * 10 + res.num[i];
            res.num[i] = temp / absB;
            remainder = temp % absB;
        }
        while (res.len > 1 && res.num[res.len] == 0)
            --res.len;
        res.isNeg = (b < 0) ^ res.isNeg; // 如果除数b为负数，那么结果的符号与被除数a的符号相反
        if (res.len == 1 && res.num[1] == 0)
            res.isNeg = false; // 如果结果为0，确保isNeg为false
        return res;
    }
    friend BigNum &operator/=(BigNum &a, const long long &b)
    {
        a = a / b;
        return a;
    }
 
    friend long long operator%(const BigNum &a, const long long &b)
    {
        if (b == 0)
        {
            throw std::runtime_error("Division by zero is not allowed.");
        }
        long long remainder = 0;
        long long absB = abs(b);
        for (int i = a.len; i > 0; --i)
        {
            long long temp = remainder * 10 + a.num[i];
            remainder = temp % absB;
        }
        return a.isNeg ? -remainder : remainder;
    }
    friend BigNum &operator%=(BigNum &a, const long long &b)
    {
        long long remainder = a % b;
        a = BigNum(remainder);
        return a;
    }
 
    friend BigNum operator^(const BigNum &a, long long b)
    {
        BigNum res(1);
        BigNum base = a;
        while (b)
        {
            if (b & 1)
                res *= base;
            base *= base;
            b >>= 1;
        }
        return res;
    }
 
    friend ostream &operator<<(ostream &out, const BigNum &b)
    {
        if (b.isNeg)
            out << '-';
        for (int i = b.len; i >= 1; i--)
            out << b.num[i];
        return out;
    }
};