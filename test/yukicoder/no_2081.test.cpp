#define PROBLEM "https://yukicoder.me/problems/no/2081"

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

#include "../../lib/math/prime_structure.hpp"

int main()
{
    int m;
    cin >> m;
    if(!m)
    {
        m += 998244353;
    }
    prime_sturcture prime(50000);
    int l = 0, r = prime.size() - 1;
    vector<int> ans;
    while (m)
    {
        for (int i = 30; i >= 0; i--)
        {
            if (m >= (1 << i) - 1)
            {
                while (prime[l] * prime[r] > 100000)
                {
                    r--;
                }
                for (int j = 0; j < i; j++)
                {
                    ans.push_back(prime[l] * prime[r--]);
                }
                m -= (1 << i) - 1;
                l++;
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}
