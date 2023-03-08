template <typename GRAPH>
std::vector<int> eulerian_trail(GRAPH &g, int r = 0, bool return_edges = true)
{
    int n = g.size();
    int m = g.edge_size();
    std::vector<int> trail;
    std::vector<bool> used(m);

    auto dfs = [&](auto self, int u, int last_edge_id) -> void
    {
        for (auto e : g[u])
        {
            if (!used[e.id])
            {
                used[e.id] = true;
                self(self, e.to, e.id);
            }
        }
        if (!return_edges)
        {
            trail.push_back(u);
        }
        else if (last_edge_id != -1)
        {
            trail.push_back(last_edge_id);
        }
    };

    bool even_degree = true;
    for (int u = 0; u < n; u++)
    {
        even_degree &= !((int)g[u].size() % 2);
    }
    assert(even_degree);
    dfs(dfs, r, -1);
    bool connected = true;
    for (int i = 0; i < m; i++)
    {
        connected &= used[i];
    }
    assert(connected);
    return trail;
}
