template <typename GRAPH>
struct LowLink
{
public:
    using EDGE = typename GRAPH::Edge;
    std::vector<int> articulation;
    std::vector<EDGE> bridge;

    LowLink() {}

    LowLink(GRAPH &g) : n(g.size()), g(g)
    {
        std::vector<int> ord(n, -1);
        std::vector<int> low(n, -1);
        int k = 0;

        auto dfs = [&](auto self, int u, int last_edge_id) -> void
        {
            low[u] = ord[u] = k++;
            int c = 0;
            bool is_artification = false;
            for (auto e : g[u])
            {
                int v = e.to;
                if (e.id == last_edge_id)
                {
                    continue;
                }
                if (ord[v] == -1)
                {
                    c++;
                    self(self, v, e.id);
                    if (last_edge_id != -1 && ord[u] <= low[v])
                    {
                        is_artification = true;
                    }
                    if (ord[u] < low[v])
                    {
                        bridge.push_back(e);
                    }
                    low[u] = std::min(low[u], low[v]);
                }
                low[u] = std::min(low[u], ord[v]);
            }
            is_artification |= (last_edge_id == -1 && c >= 2);
            if (is_artification)
            {
                articulation.push_back(u);
            }
        };

        for (int u = 0; u < n; u++)
        {
            if (ord[u] == -1)
            {
                dfs(dfs, u, -1);
            }
        }
    }

private:
    int n;
    const GRAPH &g;
};
