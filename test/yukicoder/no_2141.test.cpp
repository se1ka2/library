#define PROBLEM "https://yukicoder.me/problems/no/2156"

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const int MOD = 998244353;

#include "../../lib/math/modint.hpp"
#include "../../lib/math/combination.hpp"

int main()
{
    int n, m;
    cin >> n >> m;
    combination com(m);
    int s = m;
    mint ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (i < m % n)
        {
            ans *= com(s, m / n + 1);
            s -= m / n + 1;
        }
        else
        {
            ans *= com(s, m / n);
            s -= m / n;
        }
    }
    cout << ans << endl;
}
