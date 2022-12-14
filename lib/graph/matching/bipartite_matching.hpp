struct bipartite_matching
{
public:
    bipartite_matching() {}

    bipartite_matching(int p, int q) : p(p), q(q), g(p + q + 2), ml(p, -1), mr(q, -1)
    {
        for (int a = 0; a < p; a++)
        {
            g.add_directed_edge(p + q, a, 1);
        }
        for (int b = 0; b < q; b++)
        {
            g.add_directed_edge(b + p, p + q + 1, 1);
        }
    }

    void add_edge(int a, int b)
    {
        assert(0 <= a && a < p);
        assert(0 <= b && b < q);
        g.add_directed_edge(a, b + p, 1);
    }

    int get_maximum_matching()
    {
        int k = g.get_maximum_flow(p + q, p + q + 1);
        for (int i = p + q; i < g.edge_size(); i++)
        {
            edge<int> &e = g.get_edge(i);
            if (e.flow)
            {
                ml[e.from] = mr[e.to - p] = e.id;
            }
        }
        return k;
    }

    bool is_matched(int edge_id)
    {
        return (bool)(g.get_edge(edge_id + (p + q)).flow);
    }

    bool is_covered(int u, bool left)
    {
        return left ? (ml[u] >= 0) : (mr[u] >= 0);
    }

    edge<int> &get_incident_edge(int u, bool left)
    {
        assert(is_covered(u, left));
        return left ? g.get_edge(ml[u]) : g.get_edge(mr[u]);
    }

    int match_to(int u, bool left)
    {
        if(!is_covered(u, left))
        {
            return -1;
        }
        return left ? g.get_edge(ml[u]).to - p : g.get_edge(mr[u]).from;
    }

private:
    int p, q;
    mf_graph<int> g;
    std::vector<int> ml, mr;
};
