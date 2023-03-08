#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include <iostream>
#include <cassert>
#include <queue>
#include "../../lib/graph/Graph.hpp"
#include "../../lib/graph/shortest_path/bfs.hpp"
using namespace std;

int main()
{
    int n;
    cin >> n;
    Graph<int> g(n);
    for (int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            v--;
            g.add_directed_edge(u, v);
        }
    }
    vector<int> d = bfs(g, 0);
    for (int u = 0; u < n; u++)
    {
        cout << u + 1 << " " << d[u] << endl;
    }
}
