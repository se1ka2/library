template <typename G, typename T = int>
void low_link_sub(int u, int last_edge_id, int &k, G &g, std::vector<int> &ord, std::vector<int> &low, std::vector<edge<T>> &bridge)
{
    ord[u] = k++;
    low[u] = ord[u];
    for (edge<T> e : g[u])
    {
        int v = e.to;
        if (e.id == last_edge_id)
        {
            continue;
        }
        if (ord[v] == -1)
        {
            low_link_sub(v, e.id, k, g, ord, low, bridge);
        }
        low[u] = std::min(low[u], low[v]);
        if (ord[u] < low[v])
        {
            bridge.push_back(e);
        }
    }
}

template <typename G, typename T = int>
std::vector<edge<T>> low_link(G &g)
{
    int n = g.size();
    std::vector<int> ord(n, -1);
    std::vector<int> low(n, -1);
    std::vector<edge<T>> bridge;
    int k = 0;
    for (int u = 0; u < n; u++)
    {
        if (ord[u] == -1)
        {
            low_link_sub(u, -1, k, g, ord, low, bridge);
        }
    }
    return bridge;
}
