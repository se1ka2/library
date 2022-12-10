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

struct combination_big
{
    long long maxn;
    int maxk;
    std::vector<mint> nP;
    std::vector<mint> inP;
    std::vector<mint> fact;
    std::vector<mint> ifact;

    combination_big(long long maxn, int maxk) : maxn(maxn), maxk(maxk), nP(maxk + 1), inP(maxk + 1), fact(maxk + 1), ifact(maxk + 1)
    {
        nP[0] = 1;
        inP[0] = 1;
        fact[0] = 1;
        ifact[0] = 1;
        for (int i = 1; i <= maxk; i++)
        {
            nP[i] = nP[i - 1] * (maxn + 1 - i);
            inP[i] = inP[i - 1] * modpow(maxn + 1 - i, MOD - 2);
            fact[i] = fact[i - 1] * i;
            ifact[i] = ifact[i - 1] * modpow(i, MOD - 2);
        }
    }

    mint operator()(long long n, int k)
    {
        assert(n <= maxn);
        assert(maxn - n + k <= maxk);
        if (k > n || k < 0)
        {
            return 0;
        }
        return nP[maxn - n + k] * inP[maxn - n] * ifact[k];
    }
};
