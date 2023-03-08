template <typename GRAPH>
struct SCC
{
public:
    std::vector<std::vector<int>> group;

    SCC() {}

    SCC(GRAPH &g) : n(g.size()), k(0), g(g), cmp(n)
    {
        std::vector<std::vector<int>> rg(n);
        std::vector<bool> used(n);
        std::vector<int> vs;

        auto dfs = [&](auto self, int u) -> void
        {
            used[u] = true;
            for (int v : g[u])
            {
                if (!used[v])
                {
                    self(self, v);
                }
            }
            vs.push_back(u);
        };

        auto rdfs = [&](auto self, int u) -> void
        {
            used[u] = true;
            cmp[u] = k;
            for (int v : rg[u])
            {
                if (!used[v])
                {
                    self(self, v);
                }
            }
        };

        for (int u = 0; u < n; u++)
        {
            for (int v : g[u])
            {
                rg[v].push_back(u);
            }
        }
        for (int u = 0; u < n; u++)
        {
            if (!used[u])
            {
                dfs(dfs, u);
            }
        }
        fill(used.begin(), used.end(), false);
        for (int i = n - 1; i >= 0; i--)
        {
            if (!used[vs[i]])
            {
                rdfs(rdfs, vs[i]);
                k++;
            }
        }
        group.resize(k);
        for (int u = 0; u < n; u++)
        {
            group[cmp[u]].push_back(u);
        }
    }

    GRAPH get_dag()
    {
        std::vector<bool> b(k);
        GRAPH dag(k);
        for (int x = 0; x < k; x++)
        {
            for (int u : group[x])
            {
                for (int v : g[u])
                {
                    int y = cmp[v];
                    if (!b[y])
                    {
                        dag.add_directed_edge(x, y);
                        b[y] = true;
                    }
                }
            }
            for (int u : group[x])
            {
                for (int v : g[u])
                {
                    b[cmp[v]] = false;
                }
            }
        }
        return dag;
    }

    int number_of_component()
    {
        return k;
    }

    const int operator[](const int &u) const
    {
        return cmp[u];
    }

private:
    int n;
    int k;
    const GRAPH &g;
    std::vector<int> cmp;
};
