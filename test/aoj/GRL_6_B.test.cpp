#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <iostream>
#include <cassert>
#include <queue>
#include "../../lib/graph/flow/MinimumCostFlow.hpp"
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, m, f;
    cin >> n >> m >> f;
    MinimumCostFlow<int, int> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        g.add_directed_edge(u, v, c, d);
    }
    P p = g.get_min_cost_flow(0, n - 1, f);
    cout << (p.first == f ? p.second : -1) << endl;
}
