#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"

#include <iostream>
#include <cassert>
#include <queue>
#include "../../lib/graph/Graph.hpp"
#include "../../lib/graph/shortest_path/dijkstra.hpp"
using namespace std;

int main()
{
    int n;
    cin >> n;
    Graph<int> g(n);
    for(int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;
        for(int j = 0; j < k; j++)
        {
            int v, c;
            cin >> v >> c;
            g.add_directed_edge(u, v, c);
        }
    }
    vector<int> d = dijkstra(g, 0);
    for(int u = 0; u < n; u++)
    {
        cout << u << " " << d[u] << endl;
    }
}
