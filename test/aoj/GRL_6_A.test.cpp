#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include <cassert>
#include <queue>
#include "../../lib/graph/flow/MaximumFlow.hpp"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    MaximumFlow<int> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g.add_directed_edge(u, v, c);
    }
    cout << g.get_maximum_flow(0, n - 1) << endl;
}
