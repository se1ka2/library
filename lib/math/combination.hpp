struct combination
{
public:
    combination(int maxn) : maxn(maxn)
    {
        fact.resize(maxn + 1);
        ifact.resize(maxn + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxn; i++)
        {
            fact[i] = fact[i - 1] * i;
        }
        ifact[maxn] = fact[maxn].inv();
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

private:
    int maxn;
    std::vector<mint> fact;
    std::vector<mint> ifact;
};
