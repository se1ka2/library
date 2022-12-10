#define PROBLEM "https://yukicoder.me/problems/no/2156"

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

#include "../../lib/math/modint.hpp"
#include "../../lib/math/matrix.hpp"

int main()
{
    ll n;
    cin >> n;
    Matrix<mint> a(2);
    a[0][0] = a[0][1] = a[1][0] = 1;
    a ^= n;
    cout << a[0][0] - 1 << endl;
}
