#define PROBLEM "https://yukicoder.me/problems/no/2141"

#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/math/static_modint.hpp"
#include "../../lib/math/combination.hpp"
using namespace std;
using mint = static_modint<998244353>;

int main()
{
    int n, m;
    cin >> n >> m;
    combination<mint> com(m);
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
