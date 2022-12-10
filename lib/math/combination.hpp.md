---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/no_2141.test.cpp
    title: test/yukicoder/no_2141.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/combination.hpp\"\nmint modpow(mint x, long long\
    \ n)\n{\n    mint res = 1, r = x;\n    while (n)\n    {\n        if (n & 1)\n\
    \        {\n            res *= r;\n        }\n        r *= r;\n        n >>= 1;\n\
    \    }\n    return res;\n}\n\nstruct combination\n{\n    int maxn;\n    std::vector<mint>\
    \ fact;\n    std::vector<mint> ifact;\n\n    combination(int maxn) : maxn(maxn)\n\
    \    {\n        fact.resize(maxn + 1);\n        ifact.resize(maxn + 1);\n    \
    \    fact[0] = 1;\n        for (int i = 1; i <= maxn; i++)\n        {\n      \
    \      fact[i] = fact[i - 1] * i;\n        }\n        ifact[maxn] = modpow(fact[maxn],\
    \ MOD - 2);\n        for (int i = maxn - 1; i >= 0; i--)\n        {\n        \
    \    ifact[i] = ifact[i + 1] * (i + 1);\n        }\n    }\n\n    mint operator()(int\
    \ n, int k)\n    {\n        assert(n <= maxn);\n        if (k > n || k < 0)\n\
    \        {\n            return 0;\n        }\n        return fact[n] * ifact[k]\
    \ * ifact[n - k];\n    }\n};\n"
  code: "mint modpow(mint x, long long n)\n{\n    mint res = 1, r = x;\n    while\
    \ (n)\n    {\n        if (n & 1)\n        {\n            res *= r;\n        }\n\
    \        r *= r;\n        n >>= 1;\n    }\n    return res;\n}\n\nstruct combination\n\
    {\n    int maxn;\n    std::vector<mint> fact;\n    std::vector<mint> ifact;\n\n\
    \    combination(int maxn) : maxn(maxn)\n    {\n        fact.resize(maxn + 1);\n\
    \        ifact.resize(maxn + 1);\n        fact[0] = 1;\n        for (int i = 1;\
    \ i <= maxn; i++)\n        {\n            fact[i] = fact[i - 1] * i;\n       \
    \ }\n        ifact[maxn] = modpow(fact[maxn], MOD - 2);\n        for (int i =\
    \ maxn - 1; i >= 0; i--)\n        {\n            ifact[i] = ifact[i + 1] * (i\
    \ + 1);\n        }\n    }\n\n    mint operator()(int n, int k)\n    {\n      \
    \  assert(n <= maxn);\n        if (k > n || k < 0)\n        {\n            return\
    \ 0;\n        }\n        return fact[n] * ifact[k] * ifact[n - k];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/combination.hpp
  requiredBy: []
  timestamp: '2022-12-11 02:52:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/no_2141.test.cpp
documentation_of: lib/math/combination.hpp
layout: document
redirect_from:
- /library/lib/math/combination.hpp
- /library/lib/math/combination.hpp.html
title: lib/math/combination.hpp
---
