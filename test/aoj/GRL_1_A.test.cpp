#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include <cassert>
#include <queue>
#include "../../lib/graph/Graph.hpp"
#include "../../lib/graph/shortest_path/dijkstra.hpp"
using namespace std;

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    Graph<int> g(n);
    for (int i = 0; i < m; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        g.add_directed_edge(s, t, d);
    }
    vector<int> d = dijkstra(g, r);
    for (int u = 0; u < n; u++)
    {
        if (d[u] == -1)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << d[u] << endl;
        }
    }
}
