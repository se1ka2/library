#define PROBLEM "https://yukicoder.me/problems/no/2130"

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

#include "../../lib/math/modint.hpp"
#include "../../lib/math/combination_big.hpp"

int main()
{
    ll n, m;
    cin >> n >> m;
    combination_big com(n + 120, m + 300);
    mint ans = modpow(2, n);
    for (int i = 0; i < m; i++)
    {
        ans -= com(n, i);
    }
    cout << ans << endl;
}
