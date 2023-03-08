struct PrimeStructure
{
public:
    PrimeStructure(int max_n) : max_n(max_n), largest_prime_factor(max_n + 1, -1)
    {
        for (int i = 2; i <= max_n; i++)
        {
            if (largest_prime_factor[i] == -1)
            {
                prime_list.push_back(i);
                for (int j = i; j <= max_n; j += i)
                {
                    largest_prime_factor[j] = i;
                }
            }
        }
    }

    bool is_prime(int n)
    {
        assert(n >= 0 && n <= max_n);
        return largest_prime_factor[n] == n;
    }

    std::vector<int> factorize(int n)
    {
        assert(n >= 1 && n <= max_n);
        std::vector<int> res;
        while (n > 1)
        {
            int p = largest_prime_factor[n];
            res.push_back(p);
            n /= p;
        }
        return res;
    }

    int size()
    {
        return prime_list.size();
    }

    const int operator[](int i) const
    {
        assert(i < (int)prime_list.size());
        return prime_list[i];
    }

    std::vector<int>::const_iterator begin()
    {
        return prime_list.begin();
    }

    std::vector<int>::const_iterator end()
    {
        return prime_list.end();
    }

private:
    int max_n;
    std::vector<int> largest_prime_factor;
    std::vector<int> prime_list;
};
