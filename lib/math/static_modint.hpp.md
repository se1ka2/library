---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2105.test.cpp
    title: test/yukicoder/no_2105.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2130.test.cpp
    title: test/yukicoder/no_2130.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2141.test.cpp
    title: test/yukicoder/no_2141.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2156.test.cpp
    title: test/yukicoder/no_2156.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/static_modint.hpp\"\ntemplate <int MOD>\nstruct\
    \ static_modint\n{\n    using mint = static_modint;\n\npublic:\n    int val;\n\
    \n    static_modint() : val(0) {}\n\n    static_modint(long long v)\n    {\n \
    \       if (std::abs(v) >= mod())\n        {\n            v %= mod();\n      \
    \  }\n        if (v < 0)\n        {\n            v += mod();\n        }\n    \
    \    val = v;\n    }\n\n    mint &operator++()\n    {\n        val++;\n      \
    \  if (val == mod())\n        {\n            val = 0;\n        }\n        return\
    \ *this;\n    }\n\n    mint &operator--()\n    {\n        if (val == 0)\n    \
    \    {\n            val = mod();\n        }\n        val--;\n        return *this;\n\
    \    }\n\n    mint &operator+=(const mint &x)\n    {\n        val += x.val;\n\
    \        if (val >= mod())\n        {\n            val -= mod();\n        }\n\
    \        return *this;\n    }\n\n    mint &operator-=(const mint &x)\n    {\n\
    \        val -= x.val;\n        if (val < 0)\n        {\n            val += mod();\n\
    \        }\n        return *this;\n    }\n\n    mint &operator*=(const mint &x)\n\
    \    {\n        val = (int)((long long)val * x.val % mod());\n        return *this;\n\
    \    }\n\n    mint &operator/=(const mint &x)\n    {\n        *this *= x.inv();\n\
    \        return *this;\n    }\n\n    mint operator-()\n    {\n        return mint()\
    \ - *this;\n    }\n\n    mint pow(long long n) const\n    {\n        mint x =\
    \ 1, r = *this;\n        while (n)\n        {\n            if (n & 1)\n      \
    \      {\n                x *= r;\n            }\n            r *= r;\n      \
    \      n >>= 1;\n        }\n        return x;\n    }\n\n    mint inv() const\n\
    \    {\n        return pow(mod() - 2);\n    }\n\n    friend mint operator+(const\
    \ mint &x, const mint &y)\n    {\n        return mint(x) += y;\n    }\n\n    friend\
    \ mint operator-(const mint &x, const mint &y)\n    {\n        return mint(x)\
    \ -= y;\n    }\n\n    friend mint operator*(const mint &x, const mint &y)\n  \
    \  {\n        return mint(x) *= y;\n    }\n\n    friend mint operator/(const mint\
    \ &x, const mint &y)\n    {\n        return mint(x) /= y;\n    }\n\n    friend\
    \ bool operator==(const mint &x, const mint &y)\n    {\n        return x.val ==\
    \ y.val;\n    }\n\n    friend bool operator!=(const mint &x, const mint &y)\n\
    \    {\n        return x.val != y.val;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &x)\n    {\n        return os << x.val;\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, mint &x)\n    {\n        long long\
    \ v;\n        is >> v;\n        x = mint(v);\n        return is;\n    }\n\nprivate:\n\
    \    static constexpr int mod()\n    {\n        return MOD;\n    }\n};\n"
  code: "template <int MOD>\nstruct static_modint\n{\n    using mint = static_modint;\n\
    \npublic:\n    int val;\n\n    static_modint() : val(0) {}\n\n    static_modint(long\
    \ long v)\n    {\n        if (std::abs(v) >= mod())\n        {\n            v\
    \ %= mod();\n        }\n        if (v < 0)\n        {\n            v += mod();\n\
    \        }\n        val = v;\n    }\n\n    mint &operator++()\n    {\n       \
    \ val++;\n        if (val == mod())\n        {\n            val = 0;\n       \
    \ }\n        return *this;\n    }\n\n    mint &operator--()\n    {\n        if\
    \ (val == 0)\n        {\n            val = mod();\n        }\n        val--;\n\
    \        return *this;\n    }\n\n    mint &operator+=(const mint &x)\n    {\n\
    \        val += x.val;\n        if (val >= mod())\n        {\n            val\
    \ -= mod();\n        }\n        return *this;\n    }\n\n    mint &operator-=(const\
    \ mint &x)\n    {\n        val -= x.val;\n        if (val < 0)\n        {\n  \
    \          val += mod();\n        }\n        return *this;\n    }\n\n    mint\
    \ &operator*=(const mint &x)\n    {\n        val = (int)((long long)val * x.val\
    \ % mod());\n        return *this;\n    }\n\n    mint &operator/=(const mint &x)\n\
    \    {\n        *this *= x.inv();\n        return *this;\n    }\n\n    mint operator-()\n\
    \    {\n        return mint() - *this;\n    }\n\n    mint pow(long long n) const\n\
    \    {\n        mint x = 1, r = *this;\n        while (n)\n        {\n       \
    \     if (n & 1)\n            {\n                x *= r;\n            }\n    \
    \        r *= r;\n            n >>= 1;\n        }\n        return x;\n    }\n\n\
    \    mint inv() const\n    {\n        return pow(mod() - 2);\n    }\n\n    friend\
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
    \ &is, mint &x)\n    {\n        long long v;\n        is >> v;\n        x = mint(v);\n\
    \        return is;\n    }\n\nprivate:\n    static constexpr int mod()\n    {\n\
    \        return MOD;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/static_modint.hpp
  requiredBy: []
  timestamp: '2023-01-14 04:39:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2156.test.cpp
  - test/yukicoder/no_2141.test.cpp
  - test/yukicoder/no_2105.test.cpp
  - test/yukicoder/no_2130.test.cpp
documentation_of: lib/math/static_modint.hpp
layout: document
redirect_from:
- /library/lib/math/static_modint.hpp
- /library/lib/math/static_modint.hpp.html
title: lib/math/static_modint.hpp
---
