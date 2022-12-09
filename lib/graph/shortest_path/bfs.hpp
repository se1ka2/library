template <typename G>
std::vector<int> bfs(G &g, int s)
{
    int n = g.size();
    assert(s >= 0 && s < n);
    std::vector<int> d(n, -1);
    std::queue<int> que;
    d[s] = 0;
    que.push(s);
    while (que.size())
    {
        int u = que.front();
        que.pop();
        for (int v : g.g[u])
        {
            if (d[v] == -1)
            {
                d[v] = d[u] + 1;
                que.push(v);
            }
        }
    }
    return d;
}
