#define PROBLEM "https://judge.yosupo.jp/problem/scc"

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
    int k = scc.number_of_component();
    cout << k << endl;
    for (int x = 0; x < k; x++)
    {
        cout << scc.group[x].size() << " ";
        for (int u : scc.group[x])
        {
            cout << u << " ";
        }
        cout << endl;
    }
}
