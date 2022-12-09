template <typename T = int>
struct edge
{
    int a, b;
    int preference_a, preference_b;
    bool is_matched;
    T cost;
    int id;

    bool operator<(const edge<T> &e) const
    {
        return preference_a < e.preference_a;
    }
};

template <typename T = int>
struct stable_matching
{
    int p, q, m;
    std::vector<std::vector<edge<T>>> g;
    std::vector<std::pair<int, int>> epos;

    stable_matching() {}

    stable_matching(int p, int q) : p(p), q(q), m(0)
    {
        g.resize(p);
    }

    void add_directed_edge(int a, int b, int preference_a, int preference_b, int cost = 1)
    {
        assert(0 <= a && a < p);
        assert(0 <= b && b < q);
        epos.push_back(std::pair<int, int>(a, (int)g[a].size()));
        g[a].push_back((edge<T>){a, b, preference_a, preference_b, false, cost, m++});
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
        std::vector<std::pair<int, int>> mbpos(q, std::pair<int, int>(-1, -1));
        std::vector<T> nx(p, 0);
        std::queue<T> que;
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
                int x = mbpos[b].first;
                if (x >= 0 && g[x][mbpos[b].second].preference_b > g[a][i].preference_b)
                {
                    g[x][mbpos[b].second].is_matched = false;
                    nx[x]++;
                    que.push(x);
                    x = -1;
                }
                if (x == -1)
                {
                    g[a][i].is_matched = true;
                    mbpos[b] = std::pair<int, int>(a, i);
                    break;
                }
            }
        }
    }

    edge<T> &get_edge(int id)
    {
        assert(id < m);
        return g[epos[id].first][epos[id].second];
    }
};
