template <typename GRAPH>
std::vector<typename GRAPH::value_type> dijkstra(GRAPH &g, int s)
{
    using T = typename GRAPH::value_type;
    using P = std::pair<T, int>;
    int n = g.size();
    assert(s >= 0 && s < n);
    std::vector<T> d(n, -1);
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    d[s] = 0;
    que.push(P(0, s));
    while (que.size())
    {
        auto [dist, u] = que.top();
        que.pop();
        if (d[u] < dist)
        {
            continue;
        }
        for (auto e : g[u])
        {
            int v = e.to;
            if (d[v] == -1 || d[v] > d[u] + e.cost)
            {
                d[v] = d[u] + e.cost;
                que.push(P(d[v], v));
            }
        }
    }
    return d;
}
