template <typename G, typename T = int>
void eulerian_trail_sub(int u, int last_edge_id, bool return_edge_id, G &g, std::vector<int> &trail, std::vector<bool> &used)
{
    for (edge<T> e : g[u])
    {
        if (used[e.id])
        {
            continue;
        }
        used[e.id] = true;
        eulerian_trail_sub(e.to, e.id, return_edge_id, g, trail, used);
    }
    if (!return_edge_id)
    {
        trail.push_back(u);
    }
    else if (last_edge_id != -1)
    {
        trail.push_back(last_edge_id);
    }
}

template <typename G>
std::vector<int> eulerian_trail(G &g, int r = 0, bool return_edge_id = true)
{
    int n = g.size(), m = g.edge_size();
    bool even_degree = true;
    for (int u = 0; u < n; u++)
    {
        even_degree &= !((int)g[u].size() % 2);
    }
    assert(even_degree);
    std::vector<int> trail;
    std::vector<bool> used(m);
    eulerian_trail_sub(r, -1, return_edge_id, g, trail, used);
    bool cover_all_edge = true;
    for (int i = 0; i < m; i++)
    {
        cover_all_edge &= used[i];
    }
    assert(cover_all_edge);
    return trail;
}
