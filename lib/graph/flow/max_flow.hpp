template <typename T = int>
struct edge
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

template <typename T = int>
struct mf_graph
{
public:
    mf_graph() {}

    mf_graph(int n) : n(n), m(0)
    {
        g.resize(n);
        d.resize(n);
        nx.resize(n);
    }

    void add_directed_edge(int from, int to, T cap)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        epos.push_back(std::pair<int, int>(from, (int)g[from].size()));
        g[from].push_back((edge<T>){from, to, cap, 0, (int)g[to].size(), m++});
        g[to].push_back((edge<T>){to, from, 0, cap, (int)g[from].size() - 1, -1});
    }

    T get_maximum_flow(int source, int sink)
    {
        T res = 0;
        while (true)
        {
            bfs(sink);
            if (d[source] == -1)
            {
                return res;
            }
            fill(nx.begin(), nx.end(), 0);
            for (T f; (f = dfs(source, sink, -1)) > 0;)
            {
                res += f;
            }
        }
    }

    edge<T> &get_edge(int id)
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

    inline const std::vector<edge<T>> &operator[](const int &u) const
    {
        return g[u];
    }

    inline std::vector<edge<T>> &operator[](const int &u)
    {
        return g[u];
    }

private:
    int n;
    int m;
    std::vector<std::vector<edge<T>>> g;
    std::vector<int> d;
    std::vector<int> nx;
    std::vector<std::pair<int, int>> epos;

    T dfs(int u, int s, T f)
    {
        if (u == s)
        {
            return f;
        }
        for (int &i = nx[u]; i < (int)g[u].size(); i++)
        {
            edge<T> &e = g[u][i];
            int v = e.to;
            if (d[v] >= d[u] || e.cap == 0)
            {
                continue;
            }
            f = (f == -1) ? e.cap : std::min(f, e.cap);
            T fl = dfs(v, s, f);
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
    }

    void bfs(int s)
    {
        fill(d.begin(), d.end(), -1);
        std::queue<int> que;
        d[s] = 0;
        que.push(s);
        while (que.size())
        {
            int u = que.front();
            que.pop();
            for (edge<T> &e : g[u])
            {
                int v = e.to;
                if (e.flow > 0 && d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    que.push(v);
                }
            }
        }
    }
};
