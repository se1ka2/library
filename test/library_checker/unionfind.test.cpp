#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/structure/union_find/union_find.hpp"
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    union_find uf(n);
    while(q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if(t)
        {
            cout << (int)(uf.same(u, v)) << endl;
        }
        else
        {
            uf.unite(u, v);
        }
    }
}
