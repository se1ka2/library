template <typename G, typename T = int>
struct scc_structure
{
public:
    std::vector<std::vector<int>> group;

    scc_structure() {}

    scc_structure(G &g) : n(g.size()), k(0), g(g), rg(g.size()), cmp(n), used(n)
    {
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
                dfs(u);
            }
        }
        fill(used.begin(), used.end(), false);
        for (int i = n - 1; i >= 0; i--)
        {
            if (!used[vs[i]])
            {
                rdfs(vs[i], k++);
            }
        }
        group.resize(k);
        for (int u = 0; u < n; u++)
        {
            group[cmp[u]].push_back(u);
        }
    }

    graph<int> get_dag()
    {
        std::vector<bool> b(k);
        graph<int> dag(k);
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
    const G &g;
    std::vector<std::vector<int>> rg;
    std::vector<int> cmp;
    std::vector<bool> used;
    std::vector<int> vs;

    void dfs(int u)
    {
        used[u] = true;
        for (int v : g[u])
        {
            if (!used[v])
            {
                dfs(v);
            }
        }
        vs.push_back(u);
    }

    void rdfs(int u, int k)
    {
        used[u] = true;
        cmp[u] = k;
        for (int v : rg[u])
        {
            if (!used[v])
            {
                rdfs(v, k);
            }
        }
    }
};
