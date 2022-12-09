template <typename T = int>
struct scc_graph
{
    int n, m;
    std::vector<std::vector<edge<T>>> g, rg;
    std::vector<int> cmp;

    scc_graph() {}

    scc_graph(int n) : n(n)
    {
        g.resize(n);
        rg.resize(n);
        cmp.resize(n);
    }

    void add_directed_edge(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back((edge<T>){from, to, cost, m});
        rg[to].push_back((edge<T>){to, from, cost, m++});
    }

    void dfs(int u, vector<bool> &used, vector<int> &vs)
    {
        used[u] = true;
        for (int v : g[u])
        {
            if (!used[v])
            {
                dfs(v, used, vs);
            }
        }
        vs.push_back(u);
    }

    void rdfs(int u, int k, vector<bool> &used)
    {
        used[u] = true;
        cmp[u] = k;
        for (int v : rg[u])
        {
            if (!used[v])
            {
                rdfs(v, k, used);
            }
        }
    }

    int build()
    {
        std::vector<bool> used(n, false);
        std::vector<int> vs;
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                dfs(i, used, vs);
            }
        }
        fill(used.begin(), used.end(), false);
        int k = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (!used[vs[i]])
            {
                rdfs(vs[i], k, used);
                k++;
            }
        }
        return k;
    }

    graph<int> get_dag()
    {
        int k = build();
        std::vector<std::vector<int>> p(k);
        for (int u = 0; u < n; u++)
        {
            for (int v : g[u])
            {
                p[cmp[u]].push_back(cmp[v]);
            }
        }
        std::vector<int> b(k);
        graph<int> dag(k);
        for (int x = 0; x < k; x++)
        {
            for (int y : p[x])
            {
                if (!b[y])
                {
                    dag.add_directed_edge(x, y);
                    b[y] = 1;
                }
            }
            for (int y : p[x])
            {
                b[y] = 0;
            }
        }
        return dag;
    }

    int size()
    {
        return n;
    }

    int edge_size()
    {
        return m;
    }

    inline const std::vector<edge<T>> &operator[](const int &u) const
    {
        return g[u];
    }
};
