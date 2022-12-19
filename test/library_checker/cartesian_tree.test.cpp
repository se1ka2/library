#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
using namespace std;

#include "../../lib/structure/other/cartesian_tree.hpp"

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cartesian_tree ct(a);
    for (int i = 0; i < n; i++)
    {
        cout << ct.par[i] << " ";
    }
    cout << endl;
}
