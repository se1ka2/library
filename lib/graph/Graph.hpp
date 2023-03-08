template <typename T = int>
struct Graph
{
public:
    using value_type = T;

    struct Edge
    {
        int from, to;
        T cost;
        int id;

        operator int() const
        {
            return to;
        }
    };

    Graph() {}

    Graph(int n) : n(n), m(0), g(n) {}

    void add_directed_edge(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back((Edge){from, to, cost, m++});
    }

    void add_undirected_edge(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back((Edge){from, to, cost, m});
        g[to].push_back((Edge){to, from, cost, m++});
    }

    int size()
    {
        return n;
    }

    int edge_size()
    {
        return m;
    }

    inline const std::vector<Edge> &operator[](const int &u) const
    {
        return g[u];
    }

    inline std::vector<Edge> &operator[](const int &u)
    {
        return g[u];
    }

private:
    int n, m;
    std::vector<std::vector<Edge>> g;
};
