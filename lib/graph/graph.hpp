template <typename T = int>
struct edge
{
    int from, to;
    T cost;
    int id;

    operator int() const
    {
        return to;
    }
};

template <typename T = int>
struct graph
{
    int n, m;
    std::vector<std::vector<edge<T>>> g;

    graph() {}

    graph(int n) : n(n), m(0)
    {
        g.resize(n);
    }

    void add_directed_edge(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back((edge<T>){from, to, cost, m++});
    }

    void add_undirected_edge(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back((edge<T>){from, to, cost, m});
        g[to].push_back((edge<T>){to, from, cost, m++});
    }

    int size()
    {
        return n;
    }

    int edge_size()
    {
        return m;
    }

    inline const std::vector<edge<T>> &operator[](const int &u) const
    {
        return g[u];
    }

    inline std::vector<edge<T>> &operator[](const int &u)
    {
        return g[u];
    }
};
