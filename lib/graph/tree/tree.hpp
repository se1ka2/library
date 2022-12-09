template <typename T = int>
struct tree
{
    int n;
    int root;
    std::vector<std::vector<edge<T>>> t;
    std::vector<edge<T>> par;
    std::vector<int> dpt;
    std::vector<int> s;
    std::vector<int> topological_order;
    std::vector<std::vector<int>> anc;

    tree() {}

    tree(graph<T> &g, int root, bool by_bfs = true, bool g_is_tree = true) : n(g.size()), root(root)
    {
        if (g_is_tree)
        {
            assert(g.edge_size() == n - 1);
        }
        t.resize(n);
        par.resize(n);
        dpt.assign(n, -1);
        s.resize(n);
        par[root] = edge<T>{root, -1};
        dpt[root] = 0;
        topological_order.push_back(root);
        if (by_bfs)
        {
            std::queue<int> que;
            que.push(root);
            while (que.size())
            {
                int u = que.front();
                que.pop();
                for (edge<T> e : g[u])
                {
                    int v = e.to;
                    if (dpt[v] >= 0)
                    {
                        continue;
                    }
                    add_child(u, e);
                    que.push(v);
                }
            }
        }
        else
        {
            build_tree_by_dfs(root, g);
        }
        bool connected = true;
        for (int u = 0; u < n; u++)
        {
            if (dpt[u] == -1)
            {
                connected = false;
            }
        }
        assert(connected);
        std::reverse(topological_order.begin(), topological_order.end());
    }

    void build_tree_by_dfs(int u, graph<T> &g)
    {
        for (edge<T> e : g[u])
        {
            int v = e.to;
            if (dpt[v] >= 0)
            {
                continue;
            }
            add_child(u, e);
            build_tree_by_dfs(v, g);
        }
    }

    void add_child(int u, edge<T> &e)
    {
        int v = e.to;
        t[u].push_back(e);
        par[v] = edge<T>{v, u, e.cost, e.id};
        dpt[v] = dpt[u] + 1;
        topological_order.push_back(v);
    }

    int size(int u)
    {
        if (s[u])
        {
            return s[u];
        }
        s[u] = 1;
        for (int v : t[u])
        {
            s[u] += size(v);
        }
        return s[u];
    }

    int size()
    {
        return n;
    }

    inline const std::vector<edge<T>> &operator[](const int &u) const
    {
        return t[u];
    }
};
