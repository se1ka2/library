---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2156.test.cpp
    title: test/yukicoder/2156.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/modint.hpp\"\nstruct mint\n{\n    int val;\n\n\
    \    mint() : val(0) {}\n\n    mint(long long v) : val(v)\n    {\n        if (abs(val)\
    \ >= MOD)\n        {\n            val %= MOD;\n        }\n        if (val < 0)\n\
    \        {\n            val += MOD;\n        }\n    }\n\n    mint &operator++()\n\
    \    {\n        val++;\n        if (val == MOD)\n        {\n            val =\
    \ 0;\n        }\n        return *this;\n    }\n\n    mint &operator--()\n    {\n\
    \        if (val == 0)\n        {\n            val = MOD;\n        }\n       \
    \ val--;\n        return *this;\n    }\n\n    mint &operator+=(const mint &x)\n\
    \    {\n        val += x.val;\n        if (val >= MOD)\n        {\n          \
    \  val -= MOD;\n        }\n        return *this;\n    }\n\n    mint &operator-=(const\
    \ mint &x)\n    {\n        val -= x.val;\n        if (val < 0)\n        {\n  \
    \          val += MOD;\n        }\n        return *this;\n    }\n\n    mint &operator*=(const\
    \ mint &x)\n    {\n        val = (int)((long long)val * x.val % MOD);\n      \
    \  return *this;\n    }\n\n    mint &operator/=(const mint &x)\n    {\n      \
    \  *this *= x.inv();\n        return *this;\n    }\n\n    mint operator-()\n \
    \   {\n        return mint() - *this;\n    }\n\n    mint pow(long long n) const\n\
    \    {\n        mint x = 1, r = *this;\n        while (n)\n        {\n       \
    \     if (n & 1)\n            {\n                x *= r;\n            }\n    \
    \        r *= r;\n            n >>= 1;\n        }\n        return x;\n    }\n\n\
    \    mint inv() const\n    {\n        return pow(MOD - 2);\n    }\n\n    friend\
    \ mint operator+(const mint &x, const mint &y)\n    {\n        return mint(x)\
    \ += y;\n    }\n\n    friend mint operator-(const mint &x, const mint &y)\n  \
    \  {\n        return mint(x) -= y;\n    }\n\n    friend mint operator*(const mint\
    \ &x, const mint &y)\n    {\n        return mint(x) *= y;\n    }\n\n    friend\
    \ mint operator/(const mint &x, const mint &y)\n    {\n        return mint(x)\
    \ /= y;\n    }\n\n    friend bool operator==(const mint &x, const mint &y)\n \
    \   {\n        return x.val == y.val;\n    }\n\n    friend bool operator!=(const\
    \ mint &x, const mint &y)\n    {\n        return x.val != y.val;\n    }\n\n  \
    \  friend std::ostream &operator<<(std::ostream &os, const mint &x)\n    {\n \
    \       return os << x.val;\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &x)\n    {\n        int v;\n        is >> v;\n        x = mint(v);\n\
    \        return is;\n    }\n};\n"
  code: "struct mint\n{\n    int val;\n\n    mint() : val(0) {}\n\n    mint(long long\
    \ v) : val(v)\n    {\n        if (abs(val) >= MOD)\n        {\n            val\
    \ %= MOD;\n        }\n        if (val < 0)\n        {\n            val += MOD;\n\
    \        }\n    }\n\n    mint &operator++()\n    {\n        val++;\n        if\
    \ (val == MOD)\n        {\n            val = 0;\n        }\n        return *this;\n\
    \    }\n\n    mint &operator--()\n    {\n        if (val == 0)\n        {\n  \
    \          val = MOD;\n        }\n        val--;\n        return *this;\n    }\n\
    \n    mint &operator+=(const mint &x)\n    {\n        val += x.val;\n        if\
    \ (val >= MOD)\n        {\n            val -= MOD;\n        }\n        return\
    \ *this;\n    }\n\n    mint &operator-=(const mint &x)\n    {\n        val -=\
    \ x.val;\n        if (val < 0)\n        {\n            val += MOD;\n        }\n\
    \        return *this;\n    }\n\n    mint &operator*=(const mint &x)\n    {\n\
    \        val = (int)((long long)val * x.val % MOD);\n        return *this;\n \
    \   }\n\n    mint &operator/=(const mint &x)\n    {\n        *this *= x.inv();\n\
    \        return *this;\n    }\n\n    mint operator-()\n    {\n        return mint()\
    \ - *this;\n    }\n\n    mint pow(long long n) const\n    {\n        mint x =\
    \ 1, r = *this;\n        while (n)\n        {\n            if (n & 1)\n      \
    \      {\n                x *= r;\n            }\n            r *= r;\n      \
    \      n >>= 1;\n        }\n        return x;\n    }\n\n    mint inv() const\n\
    \    {\n        return pow(MOD - 2);\n    }\n\n    friend mint operator+(const\
    \ mint &x, const mint &y)\n    {\n        return mint(x) += y;\n    }\n\n    friend\
    \ mint operator-(const mint &x, const mint &y)\n    {\n        return mint(x)\
    \ -= y;\n    }\n\n    friend mint operator*(const mint &x, const mint &y)\n  \
    \  {\n        return mint(x) *= y;\n    }\n\n    friend mint operator/(const mint\
    \ &x, const mint &y)\n    {\n        return mint(x) /= y;\n    }\n\n    friend\
    \ bool operator==(const mint &x, const mint &y)\n    {\n        return x.val ==\
    \ y.val;\n    }\n\n    friend bool operator!=(const mint &x, const mint &y)\n\
    \    {\n        return x.val != y.val;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &x)\n    {\n        return os << x.val;\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, mint &x)\n    {\n        int v;\n\
    \        is >> v;\n        x = mint(v);\n        return is;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/modint.hpp
  requiredBy: []
  timestamp: '2022-12-10 18:36:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2156.test.cpp
documentation_of: lib/math/modint.hpp
layout: document
redirect_from:
- /library/lib/math/modint.hpp
- /library/lib/math/modint.hpp.html
title: lib/math/modint.hpp
---
