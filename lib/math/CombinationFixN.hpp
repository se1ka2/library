template <typename M>
struct CombinationFixN
{
public:
    CombinationFixN(long long n, int maxk) : n(n), maxk(maxk)
    {
        nP.resize(maxk + 1);
        fact.resize(maxk + 1);
        ifact.resize(maxk + 1);
        nP[0] = 1;
        fact[0] = 1;
        for (int i = 1; i <= maxk; i++)
        {
            nP[i] = nP[i - 1] * (n + 1 - i);
            fact[i] = fact[i - 1] * i;
        }
        ifact[maxk] = fact[maxk].inv();
        for (int i = maxk - 1; i >= 0; i--)
        {
            ifact[i] = ifact[i + 1] * (i + 1);
        }
    }

    M operator()(int k)
    {
        assert(k <= maxk);
        if (k > n || k < 0)
        {
            return 0;
        }
        return nP[k] * ifact[k];
    }

private:
    long long n;
    int maxk;
    std::vector<M> nP;
    std::vector<M> fact;
    std::vector<M> ifact;
};
