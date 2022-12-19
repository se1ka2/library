#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

#include "../../lib/graph/graph.hpp"
#include "../../lib/graph/other/scc.hpp"

int main()
{
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.add_directed_edge(a, b);
    }
    scc_structure scc(g);
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
