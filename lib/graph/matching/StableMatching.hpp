template <typename T = int>
struct stable_matching
{
public:
    struct Edge
    {
        int a, b;
        int preference_a, preference_b; // The smaller the value, the higher the priority.
        bool is_matched;
        T cost;
        int id;

        bool operator<(const Edge &e) const
        {
            return preference_a < e.preference_a;
        }
    };

    stable_matching() {}

    stable_matching(int p, int q) : p(p), q(q), m(0)
    {
        g.resize(p);
    }

    void add_directed_edge(int a, int b, int preference_a, int preference_b, T cost = 1)
    {
        assert(0 <= a && a < p);
        assert(0 <= b && b < q);
        epos.push_back(std::pair<int, int>(a, (int)g[a].size()));
        g[a].push_back((Edge){a, b, preference_a, preference_b, false, cost, m++});
    }

    void get_stable_matching()
    {
        for (int a = 0; a < p; a++)
        {
            if (!std::is_sorted(g[a].begin(), g[a].end()))
            {
                std::sort(g[a].begin(), g[a].end());
            }
        }
        std::vector<std::pair<int, int>> match(q, std::pair<int, int>(-1, -1));
        std::vector<int> nx(p, 0);
        std::queue<int> que;
        for (int a = 0; a < p; a++)
        {
            que.push(a);
        }
        while (que.size())
        {
            int a = que.front();
            que.pop();
            for (int &i = nx[a]; i < (int)g[a].size(); i++)
            {
                int b = g[a][i].b;
                int x = match[b].first;
                int j = match[b].second;
                if (x >= 0 && g[a][i].preference_b < g[x][j].preference_b)
                {
                    g[x][j].is_matched = false;
                    nx[x]++;
                    que.push(x);
                    x = -1;
                }
                if (x == -1)
                {
                    g[a][i].is_matched = true;
                    match[b] = std::pair<int, int>(a, i);
                    break;
                }
            }
        }
    }

    std::vector<Edge> get_matching_edges()
    {
        std::vector<Edge> res;
        for (int i = 0; i < m; i++)
        {
            Edge e = g[epos[i].first][epos[i].second];
            if (e.is_matched)
            {
                res.push_back(e);
            }
        }
        return res;
    }

    Edge &get_edge(int id)
    {
        assert(id < m);
        return g[epos[id].first][epos[id].second];
    }

    int get_size()
    {
        return p + q;
    }

    int get_left_size()
    {
        return p;
    }

    int get_right_size()
    {
        return q;
    }

    int get_edge_size()
    {
        return m;
    }

private:
    int p, q, m;
    std::vector<std::vector<Edge>> g;
    std::vector<std::pair<int, int>> epos;
};
