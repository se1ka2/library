#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/graph/Graph.hpp"
#include "../../lib/graph/other/LowLink.hpp"
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    for (int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        g.add_undirected_edge(s, t);
    }
    LowLink<Graph<int>> lowlink(g);
    vector<P> ans;
    for (auto e : lowlink.bridge)
    {
        ans.push_back(P(min(e.from, e.to), max(e.from, e.to)));
    }
    sort(ans.begin(), ans.end());
    for (P p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}
