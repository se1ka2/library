template <typename GRAPH>
std::vector<int> topological_sort(GRAPH &g)
{
    int n = g.size();
    std::vector<int> d(n);
    for (int u = 0; u < n; u++)
    {
        for (int v : g[u])
        {
            d[v]++;
        }
    }
    std::queue<int> que;
    for (int u = 0; u < n; u++)
    {
        if (!d[u])
        {
            que.push(u);
        }
    }
    std::vector<int> res;
    while (que.size())
    {
        int u = que.front();
        res.push_back(u);
        que.pop();
        for (int v : g[u])
        {
            d[v]--;
            if (!d[v])
            {
                que.push(v);
            }
        }
    }
    assert((int)res.size() == n);
    return res;
}
