template <typename T>
struct lca_structure
{
    int n, l;
    std::vector<int> dpt;
    std::vector<std::vector<int>> anc;

    lca_structure() {}

    lca_structure(T &t) : n(t.size()), dpt(t.dpt)
    {
        for (l = 1; l <= n; l++)
        {
            if ((1 << (l - 1)) >= n)
            {
                break;
            }
        }
        anc.assign(l, std::vector<int>(n));
        for (int u = 0; u < n; u++)
        {
            anc[0][u] = t.par[u];
        }
        for (int i = 1; i < l; i++)
        {
            for (int u = 0; u < n; u++)
            {
                anc[i][u] = (anc[i - 1][u] == -1) ? -1 : anc[i - 1][anc[i - 1][u]];
            }
        }
    }

    int ancestor(int u, int k)
    {
        for (int j = 0; j < l; j++)
        {
            if ((k >> j) & 1)
            {
                u = anc[j][u];
            }
            if (u == -1)
            {
                return u;
            }
        }
        return u;
    }

    int operator()(int u, int v)
    {
        if (dpt[u] < dpt[v])
        {
            std::swap(u, v);
        }
        u = ancestor(u, dpt[u] - dpt[v]);
        if (u == v)
        {
            return u;
        }
        for (int j = l - 1; j >= 0; j--)
        {
            if (anc[j][u] != anc[j][v])
            {
                u = anc[j][u];
                v = anc[j][v];
            }
        }
        return anc[0][u];

    }
};
