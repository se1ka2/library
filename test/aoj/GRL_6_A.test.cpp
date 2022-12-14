#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

#include "../../lib/graph/flow/max_flow.hpp"

int main()
{
    int n, m;
    cin >> n >> m;
    mf_graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g.add_directed_edge(u, v, c);
    }
    cout << g.get_maximum_flow(0, n - 1) << endl;
}
