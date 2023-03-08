#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/graph/Graph.hpp"
#include "../../lib/graph/other/SCC.hpp"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.add_directed_edge(a, b);
    }
    SCC<Graph<int>> scc(g);
    scc.number_of_component();
    int q;
    cin >> q;
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (bool)(scc[u] == scc[v]) << endl;
    }
}
