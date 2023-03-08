struct UnionFind
{
public:
    UnionFind(int n) : n(n), par(n), sz(n, 1), num_of_components(n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }

    int find(int i)
    {
        assert(0 <= i && i < n);
        return (i == par[i]) ? i : par[i] = find(par[i]);
    }

    bool same(int i, int j)
    {
        assert(0 <= i && i < n);
        assert(0 <= j && j < n);
        return find(i) == find(j);
    }

    void unite(int i, int j)
    {
        assert(0 <= i && i < n);
        assert(0 <= j && j < n);
        i = find(i), j = find(j);
        if (i == j)
        {
            return;
        }
        if (sz[i] < sz[j])
        {
            std::swap(i, j);
        }
        par[j] = i;
        sz[i] += sz[j];
        num_of_components--;
    }

    int size()
    {
        return n;
    }

    int size(int i)
    {
        assert(0 <= i && i < n);
        return sz[find(i)];
    }

    int count()
    {
        return num_of_components;
    }

    bool is_root(int i)
    {
        assert(0 <= i && i < n);
        return i == find(i);
    }

    int operator[](int i)
    {
        return find(i);
    }

private:
    int n;
    std::vector<int> par;
    std::vector<int> sz;
    int num_of_components;
};
