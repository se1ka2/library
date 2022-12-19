#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
typedef pair<int, int> P;

#include "../../lib/graph/graph.hpp"
#include "../../lib/graph/other/low_link.hpp"

int main()
{
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        g.add_undirected_edge(s, t);
    }
    low_link lowlink(g);
    vector<int> ans;
    for (int u : lowlink.articulation)
    {
        ans.push_back(u);
    }
    sort(ans.begin(), ans.end());
    for (int u : ans)
    {
        cout << u << endl;
    }
}
