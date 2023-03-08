#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>
#include <cassert>
#include <queue>
#include "../../lib/graph/matching/BipartiteMaximumMatching.hpp"
using namespace std;

int main()
{
    int x, y, m;
    cin >> x >> y >> m;
    BipartiteMaximumMatching g(x, y);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.add_directed_edge(u, v);
    }
    cout << g.get_maximum_matching() << endl;
}
