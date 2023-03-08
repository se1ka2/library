#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D"

#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/structure/union_find/UnionFind.hpp"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (uf.same(u, v) ? "yes" : "no") << endl;
    }
}
