template <typename M>
struct segment_tree
{
    using S = typename M::value_type;

public:
    segment_tree() {}

    segment_tree(int n) : n(n)
    {
        for (sz = 1; sz <= n; sz <<= 1)
        {
        }
        dat.assign(sz * 2, M::e());
    }

    segment_tree(std::vector<S> &a) : n(a.size())
    {
        for (sz = 1; sz <= n; sz <<= 1)
        {
        }
        dat.resize(sz * 2);
        for (int i = 0; i < n; i++)
        {
            dat[i + sz] = a[i];
        }
        for(int i = sz - 1; i > 0; i--)
        {
            dat[i] = M::op(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    void update(int i, S x)
    {
        assert(i >= 0 && i < sz);
        int k = i + sz;
        dat[k] = x;
        while (k >>= 1)
        {
            dat[k] = M::op(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    S query(int l, int r)
    {
        assert(l >= 0 && l <= r && r <= n);
        l += sz, r += sz;
        S x = M::e(), y = M::e();
        for (; l != r; l >>= 1, r >>= 1)
        {
            if (l % 2)
            {
                x = M::op(x, dat[l++]);
            }
            if (r % 2)
            {
                y = M::op(dat[--r], y);
            }
        }
        return M::op(x, y);
    }

    S operator[](const int i) const
    {
        return dat[i + sz];
    }

private:
    int n, sz;
    std::vector<S> dat;
};
