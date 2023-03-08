#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/structure/other/BinaryIndexedTree.hpp"
#include "../../lib/utility/compression.hpp"
#include "../../lib/structure/other/inversion_number.hpp"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << inversion_number(a) << endl;
}
