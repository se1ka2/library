---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2130.test.cpp
    title: test/yukicoder/no_2130.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/combination_fix_n.hpp\"\nmint modpow(mint x, long\
    \ long n)\n{\n    mint res = 1, r = x;\n    while (n)\n    {\n        if (n &\
    \ 1)\n        {\n            res *= r;\n        }\n        r *= r;\n        n\
    \ >>= 1;\n    }\n    return res;\n}\n\nstruct combination_fix_n\n{\npublic:\n\
    \    combination_fix_n(long long n, int maxk) : n(n), maxk(maxk)\n    {\n    \
    \    nP.resize(maxk + 1);\n        fact.resize(maxk + 1);\n        ifact.resize(maxk\
    \ + 1);\n        nP[0] = 1;\n        fact[0] = 1;\n        for (int i = 1; i <=\
    \ maxk; i++)\n        {\n            nP[i] = nP[i - 1] * (n + 1 - i);\n      \
    \      fact[i] = fact[i - 1] * i;\n        }\n        ifact[maxk] = modpow(fact[maxk],\
    \ MOD - 2);\n        for (int i = maxk - 1; i >= 0; i--)\n        {\n        \
    \    ifact[i] = ifact[i + 1] * (i + 1);\n        }\n    }\n\n    mint operator()(int\
    \ k)\n    {\n        assert(k <= maxk);\n        if (k > n || k < 0)\n       \
    \ {\n            return 0;\n        }\n        return nP[k] * ifact[k];\n    }\n\
    \nprivate:\n    long long n;\n    int maxk;\n    std::vector<mint> nP;\n    std::vector<mint>\
    \ fact;\n    std::vector<mint> ifact;\n};\n"
  code: "mint modpow(mint x, long long n)\n{\n    mint res = 1, r = x;\n    while\
    \ (n)\n    {\n        if (n & 1)\n        {\n            res *= r;\n        }\n\
    \        r *= r;\n        n >>= 1;\n    }\n    return res;\n}\n\nstruct combination_fix_n\n\
    {\npublic:\n    combination_fix_n(long long n, int maxk) : n(n), maxk(maxk)\n\
    \    {\n        nP.resize(maxk + 1);\n        fact.resize(maxk + 1);\n       \
    \ ifact.resize(maxk + 1);\n        nP[0] = 1;\n        fact[0] = 1;\n        for\
    \ (int i = 1; i <= maxk; i++)\n        {\n            nP[i] = nP[i - 1] * (n +\
    \ 1 - i);\n            fact[i] = fact[i - 1] * i;\n        }\n        ifact[maxk]\
    \ = modpow(fact[maxk], MOD - 2);\n        for (int i = maxk - 1; i >= 0; i--)\n\
    \        {\n            ifact[i] = ifact[i + 1] * (i + 1);\n        }\n    }\n\
    \n    mint operator()(int k)\n    {\n        assert(k <= maxk);\n        if (k\
    \ > n || k < 0)\n        {\n            return 0;\n        }\n        return nP[k]\
    \ * ifact[k];\n    }\n\nprivate:\n    long long n;\n    int maxk;\n    std::vector<mint>\
    \ nP;\n    std::vector<mint> fact;\n    std::vector<mint> ifact;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/combination_fix_n.hpp
  requiredBy: []
  timestamp: '2022-12-14 22:24:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2130.test.cpp
documentation_of: lib/math/combination_fix_n.hpp
layout: document
redirect_from:
- /library/lib/math/combination_fix_n.hpp
- /library/lib/math/combination_fix_n.hpp.html
title: lib/math/combination_fix_n.hpp
---
