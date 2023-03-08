#include <cassert>
#include <vector>

template <typename MODINT>
struct CombinationStructure
{
public:
    CombinationStructure()
    {
        fact = {1, 1};
        fact_inverse = {1, 1};
    }

    void size_up(int n)
    {
        int old_n = fact.size() - 1;
        if(n <= old_n)
        {
            return;
        }
        n = std::max(n, old_n * 2);
        fact.resize(n + 1);
        fact_inverse.resize(n + 1);
        for (int i = old_n + 1; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i;
        }
        fact_inverse[n] = fact[n].inv();
        for (int i = n - 1; i >= old_n + 1; i--)
        {
            fact_inverse[i] = fact_inverse[i + 1] * (i + 1);
        }
    }

    MODINT C(int n, int k)
    {
        size_up(n);
        if (k > n || k < 0)
        {
            return 0;
        }
        return fact[n] * fact_inverse[k] * fact_inverse[n - k];
    }

    MODINT P(int n, int k)
    {
        assert(k >= 0);
        size_up(n);
        if(k > n)
        {
            return 0;
        }
        return fact[n] * fact_inverse[n - k];
    }

    MODINT factorial(int n)
    {
        size_up(n);
        return fact[n];
    }

    MODINT operator()(int n, int k)
    {
        return C(n, k);
    }

private:
    int maxn;
    std::vector<MODINT> fact;
    std::vector<MODINT> fact_inverse;
};
