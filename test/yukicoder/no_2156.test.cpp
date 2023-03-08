#define PROBLEM "https://yukicoder.me/problems/no/2156"

#include <iostream>
#include <cassert>
#include <vector>
#include "../../lib/math/StaticModint.hpp"
#include "../../lib/math/Matrix.hpp"
using namespace std;
using mint = StaticModint<998244353>;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    Matrix<mint> a(2);
    a[0][0] = a[0][1] = a[1][0] = 1;
    a ^= n;
    cout << a[0][0] - 1 << endl;
}
