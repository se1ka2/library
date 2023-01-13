#define PROBLEM "https://yukicoder.me/problems/no/2105"

#include <iostream>
#include "../../lib/math/static_modint.hpp"
using namespace std;
using mint = static_modint<998244353>;

int main()
{
    int c, x;
    cin >> c >> x;
    if (x == 0)
    {
        cout << mint(c + 1).inv() << endl;
        return 0;
    }
    mint dp[2005];
    dp[0] = 1;
    for (int i = 1;; i++)
    {
        if (c + i > x)
        {
            mint ans = 1;
            for (int j = 0; j <= x; j++)
            {
                ans -= dp[j] / (x - j + 1);
            }
            cout << ans << endl;
            break;
        }
        mint d[2005]{0};
        for (int j = 0; j < i; j++)
        {
            d[j] += dp[j] * j / (c + i);
            d[j + 1] += dp[j] * (c + i - j) / (c + i);
        }
        swap(dp, d);
    }
}
