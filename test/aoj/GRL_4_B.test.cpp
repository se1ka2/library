#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include <iostream>
#include <cassert>
#include <queue>
#include "../../lib/graph/Graph.hpp"
#include "../../lib/graph/other/topological_sort.hpp"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    for(int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        g.add_directed_edge(s, t);
    }
    vector<int> p = topological_sort(g);
    for(int u : p)
    {
        cout << u << endl;
    }
}
