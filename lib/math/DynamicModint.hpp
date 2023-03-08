struct DynamicModint
{
    using mint = DynamicModint;

public:
    int val;

    DynamicModint() : val(0) {}

    DynamicModint(long long v)
    {
        if (std::abs(v) >= mod())
        {
            v %= mod();
        }
        if (v < 0)
        {
            v += mod();
        }
        val = v;
    }

    static void set_mod(int m)
    {
        MOD = m;
    }

    mint &operator++()
    {
        val++;
        if (val == mod())
        {
            val = 0;
        }
        return *this;
    }

    mint &operator--()
    {
        if (val == 0)
        {
            val = mod();
        }
        val--;
        return *this;
    }

    mint &operator+=(const mint &x)
    {
        val += x.val;
        if (val >= mod())
        {
            val -= mod();
        }
        return *this;
    }

    mint &operator-=(const mint &x)
    {
        val -= x.val;
        if (val < 0)
        {
            val += mod();
        }
        return *this;
    }

    mint &operator*=(const mint &x)
    {
        val = (int)((long long)val * x.val % mod());
        return *this;
    }

    mint &operator/=(const mint &x)
    {
        *this *= x.inv();
        return *this;
    }

    mint operator-()
    {
        return mint() - *this;
    }

    mint pow(long long n) const
    {
        mint x = 1, r = *this;
        while (n)
        {
            if (n & 1)
            {
                x *= r;
            }
            r *= r;
            n >>= 1;
        }
        return x;
    }

    mint inv() const
    {
        return pow(mod() - 2);
    }

    friend mint operator+(const mint &x, const mint &y)
    {
        return mint(x) += y;
    }

    friend mint operator-(const mint &x, const mint &y)
    {
        return mint(x) -= y;
    }

    friend mint operator*(const mint &x, const mint &y)
    {
        return mint(x) *= y;
    }

    friend mint operator/(const mint &x, const mint &y)
    {
        return mint(x) /= y;
    }

    friend bool operator==(const mint &x, const mint &y)
    {
        return x.val == y.val;
    }

    friend bool operator!=(const mint &x, const mint &y)
    {
        return x.val != y.val;
    }

    friend std::ostream &operator<<(std::ostream &os, const mint &x)
    {
        return os << x.val;
    }

    friend std::istream &operator>>(std::istream &is, mint &x)
    {
        long long v;
        is >> v;
        x = mint(v);
        return is;
    }

private:
    static int MOD;
    static int mod()
    {
        return MOD;
    }
};

int DynamicModint::MOD = 998244353;
