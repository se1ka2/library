---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2130_2.test.cpp
    title: test/yukicoder/no_2130_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/combination_big.hpp\"\nmint modpow(mint x, long\
    \ long n)\n{\n    mint res = 1, r = x;\n    while (n)\n    {\n        if (n &\
    \ 1)\n        {\n            res *= r;\n        }\n        r *= r;\n        n\
    \ >>= 1;\n    }\n    return res;\n}\n\nstruct combination_big\n{\n    long long\
    \ maxn;\n    int maxk;\n    std::vector<mint> nP;\n    std::vector<mint> inP;\n\
    \    std::vector<mint> fact;\n    std::vector<mint> ifact;\n\n    combination_big(long\
    \ long maxn, int maxk) : maxn(maxn), maxk(maxk), nP(maxk + 1), inP(maxk + 1),\
    \ fact(maxk + 1), ifact(maxk + 1)\n    {\n        nP[0] = 1;\n        inP[0] =\
    \ 1;\n        fact[0] = 1;\n        ifact[0] = 1;\n        for (int i = 1; i <=\
    \ maxk; i++)\n        {\n            nP[i] = nP[i - 1] * (maxn + 1 - i);\n   \
    \         inP[i] = inP[i - 1] * modpow(maxn + 1 - i, MOD - 2);\n            fact[i]\
    \ = fact[i - 1] * i;\n            ifact[i] = ifact[i - 1] * modpow(i, MOD - 2);\n\
    \        }\n    }\n\n    mint operator()(long long n, int k)\n    {\n        assert(n\
    \ <= maxn);\n        assert(maxn - n + k <= maxk);\n        if (k > n || k < 0)\n\
    \        {\n            return 0;\n        }\n        return nP[maxn - n + k]\
    \ * inP[maxn - n] * ifact[k];\n    }\n};\n"
  code: "mint modpow(mint x, long long n)\n{\n    mint res = 1, r = x;\n    while\
    \ (n)\n    {\n        if (n & 1)\n        {\n            res *= r;\n        }\n\
    \        r *= r;\n        n >>= 1;\n    }\n    return res;\n}\n\nstruct combination_big\n\
    {\n    long long maxn;\n    int maxk;\n    std::vector<mint> nP;\n    std::vector<mint>\
    \ inP;\n    std::vector<mint> fact;\n    std::vector<mint> ifact;\n\n    combination_big(long\
    \ long maxn, int maxk) : maxn(maxn), maxk(maxk), nP(maxk + 1), inP(maxk + 1),\
    \ fact(maxk + 1), ifact(maxk + 1)\n    {\n        nP[0] = 1;\n        inP[0] =\
    \ 1;\n        fact[0] = 1;\n        ifact[0] = 1;\n        for (int i = 1; i <=\
    \ maxk; i++)\n        {\n            nP[i] = nP[i - 1] * (maxn + 1 - i);\n   \
    \         inP[i] = inP[i - 1] * modpow(maxn + 1 - i, MOD - 2);\n            fact[i]\
    \ = fact[i - 1] * i;\n            ifact[i] = ifact[i - 1] * modpow(i, MOD - 2);\n\
    \        }\n    }\n\n    mint operator()(long long n, int k)\n    {\n        assert(n\
    \ <= maxn);\n        assert(maxn - n + k <= maxk);\n        if (k > n || k < 0)\n\
    \        {\n            return 0;\n        }\n        return nP[maxn - n + k]\
    \ * inP[maxn - n] * ifact[k];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/combination_big.hpp
  requiredBy: []
  timestamp: '2022-12-11 03:25:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2130_2.test.cpp
documentation_of: lib/math/combination_big.hpp
layout: document
redirect_from:
- /library/lib/math/combination_big.hpp
- /library/lib/math/combination_big.hpp.html
title: lib/math/combination_big.hpp
---
