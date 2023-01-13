#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/graph/graph.hpp"
#include "../../lib/graph/other/low_link.hpp"
using namespace std;
typedef pair<int, int> P;

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
    vector<P> ans;
    for (edge<int> e : lowlink.bridge)
    {
        ans.push_back(P(min(e.from, e.to), max(e.from, e.to)));
    }
    sort(ans.begin(), ans.end());
    for (P p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}
