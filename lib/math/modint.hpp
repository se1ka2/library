struct mint
{
    int val;

    mint() : val(0) {}

    mint(long long v) : val(v)
    {
        if (abs(val) >= MOD)
        {
            val %= MOD;
        }
        if (val < 0)
        {
            val += MOD;
        }
    }

    mint &operator++()
    {
        val++;
        if (val == MOD)
        {
            val = 0;
        }
        return *this;
    }

    mint &operator--()
    {
        if (val == 0)
        {
            val = MOD;
        }
        val--;
        return *this;
    }

    mint &operator+=(const mint &x)
    {
        val += x.val;
        if (val >= MOD)
        {
            val -= MOD;
        }
        return *this;
    }

    mint &operator-=(const mint &x)
    {
        val -= x.val;
        if (val < 0)
        {
            val += MOD;
        }
        return *this;
    }

    mint &operator*=(const mint &x)
    {
        val = (int)((long long)val * x.val % MOD);
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
        return pow(MOD - 2);
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
        int v;
        is >> v;
        x = mint(v);
        return is;
    }
};
