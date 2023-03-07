template <typename T = int>
struct MaximumFlow
{
public:
    struct Edge
    {
        int from, to;
        T cap, flow;
        int rev;
        int id;

        operator int() const
        {
            return to;
        }
    };

    MaximumFlow() {}

    MaximumFlow(int n) : n(n), m(0), g(n) {}

    void add_directed_edge(int from, int to, T cap)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        epos.push_back(std::pair<int, int>(from, (int)g[from].size()));
        g[from].push_back((Edge){from, to, cap, 0, (int)g[to].size(), m++});
        g[to].push_back((Edge){to, from, 0, cap, (int)g[from].size() - 1, -1});
    }

    T get_maximum_flow(int source, int sink)
    {
        assert(0 <= source && source < n);
        assert(0 <= sink && sink < n);

        std::vector<int> d(n);
        std::vector<int> nx(n);

        auto bfs = [&]()
        {
            fill(d.begin(), d.end(), -1);
            std::queue<int> que;
            d[sink] = 0;
            que.push(sink);
            while (que.size())
            {
                int u = que.front();
                que.pop();
                for (Edge &e : g[u])
                {
                    int v = e.to;
                    if (e.flow > 0 && d[v] == -1)
                    {
                        d[v] = d[u] + 1;
                        que.push(v);
                    }
                }
            }
        };

        auto dfs = [&](auto self, int u, T f)
        {
            if (u == sink)
            {
                return f;
            }
            for (int &i = nx[u]; i < (int)g[u].size(); i++)
            {
                Edge &e = g[u][i];
                int v = e.to;
                if (d[v] >= d[u] || e.cap == 0)
                {
                    continue;
                }
                f = (f == -1) ? e.cap : std::min(f, e.cap);
                T fl = self(self, v, f);
                if (fl > 0)
                {
                    e.cap -= fl;
                    e.flow += fl;
                    g[e.to][e.rev].cap += fl;
                    g[e.to][e.rev].flow -= fl;
                    return fl;
                }
            }
            return 0;
        };

        T res = 0;
        while (true)
        {
            bfs();
            if (d[source] == -1)
            {
                return res;
            }
            fill(nx.begin(), nx.end(), 0);
            for (T f; (f = dfs(dfs, source, -1)) > 0;)
            {
                res += f;
            }
        }
    }

    Edge &get_edge(int id)
    {
        assert(0 <= id && id < m);
        return g[epos[id].first][epos[id].second];
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
    int n;
    int m;
    std::vector<std::vector<Edge>> g;
    std::vector<std::pair<int, int>> epos;
};
