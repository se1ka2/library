struct BipartiteMaximumMatching
{
public:
    BipartiteMaximumMatching() {}

    BipartiteMaximumMatching(int p, int q) : p(p), q(q), g(p), match(q, -1) {}

    void add_directed_edge(int a, int b)
    {
        assert(0 <= a && a < p);
        assert(0 <= b && b < q);
        g[a].push_back(b);
    }

    int get_maximum_matching()
    {
        std::vector<bool> covered(p);
        std::vector<int> dist(p);
        std::vector<bool> used(p);
        int max_length;
        int res = 0;

        auto bfs = [&]()
        {
            std::queue<int> que;
            for (int u = 0; u < p; u++)
            {
                if (!covered[u])
                {
                    que.push(u);
                    dist[u] = 0;
                }
                else
                {
                    dist[u] = -1;
                }
            }
            while (que.size())
            {
                int u = que.front();
                que.pop();
                for (int v : g[u])
                {
                    if (match[v] == -1)
                    {
                        max_length = dist[u];
                        return;
                    }
                    if (dist[match[v]] == -1)
                    {
                        dist[match[v]] = dist[u] + 1;
                        que.push(match[v]);
                    }
                }
            }
        };

        auto dfs = [&](auto self, int u) -> bool
        {
            used[u] = true;
            for (int v : g[u])
            {
                int w = match[v];
                if (w == -1 || (!used[w] && dist[w] == dist[u] + 1 && dist[w] <= max_length && self(self, w)))
                {
                    match[v] = u;
                    covered[u] = true;
                    return true;
                }
            }
            return false;
        };

        while (true)
        {
            max_length = -1;
            bfs();
            if (max_length == -1)
            {
                return res;
            }
            used.assign(p, false);
            for (int u = 0; u < p; u++)
            {
                res += (!covered[u] && dfs(dfs, u));
            }
        }
    }

    std::vector<std::pair<int, int>> get_matching_edges()
    {
        std::vector<std::pair<int, int>> res;
        for (int v = 0; v < q; v++)
        {
            if (match[v] >= 0)
            {
                res.push_back(std::pair<int, int>(match[v], v));
            }
        }
        return res;
    }

private:
    int p, q;
    std::vector<std::vector<int>> g;
    std::vector<int> match;
};
