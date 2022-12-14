template <typename S = int, typename T = int>
struct edge
{
    int from, to;
    S cap, flow;
    T cost;
    int rev;
    int id;

    operator int() const
    {
        return to;
    }
};

template <typename S = int, typename T = int>
struct mcf_graph
{
public:
    mcf_graph() {}

    mcf_graph(int n) : n(n)
    {
        g.resize(n);
        potential.resize(n);
    }

    void add_directed_edge(int from, int to, S cap, T cost)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        epos.push_back(std::pair<int, int>(from, (int)g[from].size()));
        g[from].push_back((edge<S, T>){from, to, cap, 0, cost, (int)g[to].size(), m});
        g[to].push_back((edge<S, T>){to, from, 0, cap, -cost, (int)g[from].size() - 1, m++});
    }

    std::pair<S, T> get_min_cost_flow(int source, int sink, S f = -1)
    {
        bool nonnegative = true;
        for (int u = 0; u < n; u++)
        {
            for (edge<S, T> &e : g[u])
            {
                if (e.cap && e.cost + potential[u] - potential[e.to] < 0)
                {
                    nonnegative = false;
                }
            }
        }
        assert(nonnegative);
        S sum_of_flow = 0;
        T sum_of_cost = 0;
        using P = std::pair<T, int>;
        std::vector<T> dist(n);
        std::vector<int> prevv(n);
        std::vector<int> preve(n);
        while (f)
        {
            std::priority_queue<P, std::vector<P>, std::greater<P>> que;
            fill(dist.begin(), dist.end(), -1);
            dist[source] = 0;
            que.push(P(dist[source], source));
            while (!que.empty())
            {
                auto [x, u] = que.top();
                que.pop();
                if (u == sink)
                {
                    break;
                }
                if (dist[u] < x)
                {
                    continue;
                }
                for (int i = 0; i < (int)g[u].size(); i++)
                {
                    edge<S, T> &e = g[u][i];
                    if (e.cap == 0)
                    {
                        continue;
                    }
                    int v = e.to;
                    T cost = e.cost + potential[u] - potential[v];
                    if (dist[v] == -1 || dist[v] > dist[u] + cost)
                    {
                        dist[v] = dist[u] + cost;
                        prevv[v] = u;
                        preve[v] = i;
                        que.push(P(dist[v], v));
                    }
                }
            }
            if (dist[sink] == -1)
            {
                break;
            }
            for (int u = 0; u < n; u++)
            {
                potential[u] += (dist[u] == -1 || dist[u] > dist[sink]) ? dist[sink] : dist[u];
            }
            S flow = f;
            for (int u = sink; u != source; u = prevv[u])
            {
                flow = (flow < 0) ? g[prevv[u]][preve[u]].cap : min(flow, g[prevv[u]][preve[u]].cap);
            }
            f -= flow;
            sum_of_flow += flow;
            for (int u = sink; u != source; u = prevv[u])
            {
                edge<S, T> &e = g[prevv[u]][preve[u]];
                e.cap -= flow;
                e.flow += flow;
                g[u][e.rev].cap += flow;
                g[u][e.rev].flow -= flow;
                sum_of_cost += e.cost * flow;
            }
        }
        return std::pair<S, T>(sum_of_flow, sum_of_cost);
    }

    edge<S, T> &get_edge(int id)
    {
        assert(id < m);
        return g[epos[id].first][epos[id].second];
    }

    int size()
    {
        return n;
    }

    inline const std::vector<edge<S, T>> &operator[](const int &u) const
    {
        return g[u];
    }

    inline std::vector<edge<S, T>> &operator[](const int &u)
    {
        return g[u];
    }

private:
    int n, m;
    std::vector<std::vector<edge<S, T>>> g;
    std::vector<T> potential;
    std::vector<std::pair<int, int>> epos;

    void init_potential(bool is_dag)
    {
        if (is_dag)
        {
            std::vector<int> d(n);
            for (int u = 0; u < n; u++)
            {
                for (edge<S, T> &e : g[u])
                {
                    if (e.cap)
                    {
                        d[e.to]++;
                    }
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
            while (que.size())
            {
                int u = que.front();
                que.pop();
                for (edge<S, T> &e : g[u])
                {
                    if (!e.cap)
                    {
                        continue;
                    }
                    int v = e.to;
                    potential[v] = min(potential[v], potential[u] + e.cost);
                    d[v]--;
                    if (!d[v])
                    {
                        que.push(v);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                bool flag = false;
                for (int u = 0; u < n; u++)
                {
                    for (edge<S, T> &e : g[u])
                    {
                        if (e.cap == 0)
                        {
                            continue;
                        }
                        int v = e.to;
                        if (potential[v] > potential[u] + e.cost)
                        {
                            potential[v] = potential[u] + e.cost;
                            flag = true;
                        }
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
        }
    }
};
