struct prime_sturcture
{
public:
    prime_sturcture(int max_n) : max_n(max_n), p(max_n + 1, true)
    {
        p[0] = p[1] = false;
        for (int i = 2; i <= max_n; i++)
        {
            if (p[i])
            {
                prime_list.push_back(i);
                for (int j = i * 2; j <= max_n; j += i)
                {
                    p[j] = false;
                }
            }
        }
    }

    bool is_prime(int n)
    {
        assert(n <= max_n);
        return p[n];
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
    std::vector<bool> p;
    std::vector<int> prime_list;
};
