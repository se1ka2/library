mint modpow(mint x, long long n)
{
    mint res = 1, r = x;
    while (n)
    {
        if (n & 1)
        {
            res *= r;
        }
        r *= r;
        n >>= 1;
    }
    return res;
}

struct combination
{
    int maxn;
    std::vector<mint> fact;
    std::vector<mint> ifact;

    combination(int maxn) : maxn(maxn)
    {
        fact.resize(maxn + 1);
        ifact.resize(maxn + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxn; i++)
        {
            fact[i] = fact[i - 1] * i;
        }
        ifact[maxn] = modpow(fact[maxn], MOD - 2);
        for (int i = maxn - 1; i >= 0; i--)
        {
            ifact[i] = ifact[i + 1] * (i + 1);
        }
    }

    mint operator()(int n, int k)
    {
        assert(n <= maxn);
        if (k > n || k < 0)
        {
            return 0;
        }
        return fact[n] * ifact[k] * ifact[n - k];
    }
};
