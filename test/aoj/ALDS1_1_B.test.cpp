#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B"

#include <iostream>
#include "../../lib/math/gcd.hpp"
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}
