#define PROBLEM "https://yukicoder.me/problems/no/2130"

#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/math/StaticModint.hpp"
#include "../../lib/math/CombinationFixN.hpp"
using namespace std;
using mint = StaticModint<998244353>;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    CombinationFixN<mint> com_n(n, m);
    mint ans = mint(2).pow(n);
    for (int i = 0; i < m; i++)
    {
        ans -= com_n(i);
    }
    cout << ans << endl;
}
