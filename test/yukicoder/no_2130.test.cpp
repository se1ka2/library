#define PROBLEM "https://yukicoder.me/problems/no/2130"

#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/math/static_modint.hpp"
#include "../../lib/math/combination_fix_n.hpp"
using namespace std;
using mint = static_modint<998244353>;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    combination_fix_n<mint> com_n(n, m);
    mint ans = mint(2).pow(n);
    for (int i = 0; i < m; i++)
    {
        ans -= com_n(i);
    }
    cout << ans << endl;
}
