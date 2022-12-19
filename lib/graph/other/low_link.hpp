template <typename G, typename T = int>
struct low_link
{
public:
    std::vector<int> articulation;
    std::vector<edge<T>> bridge;

    low_link(G &g) : n(g.size()), g(g), ord(g.size(), -1), low(g.size(), -1)
    {
        int k = 0;
        for (int u = 0; u < n; u++)
        {
            if (ord[u] == -1)
            {
                dfs(u, -1, k);
            }
        }
    }

private:
    int n;
    const G &g;
    std::vector<int> ord;
    std::vector<int> low;

    void dfs(int u, int last_edge_id, int &k)
    {
        low[u] = ord[u] = k++;
        int c = 0;
        bool is_artification = false;
        for (edge<T> e : g[u])
        {
            int v = e.to;
            if (e.id == last_edge_id)
            {
                continue;
            }
            if (ord[v] == -1)
            {
                c++;
                dfs(v, e.id, k);
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
    }
};
