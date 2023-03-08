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
  bundledCode: "#line 1 \"lib/math/CombinationFixN.hpp\"\ntemplate <typename M>\n\
    struct CombinationFixN\n{\npublic:\n    CombinationFixN(long long n, int maxk)\
    \ : n(n), maxk(maxk)\n    {\n        nP.resize(maxk + 1);\n        fact.resize(maxk\
    \ + 1);\n        ifact.resize(maxk + 1);\n        nP[0] = 1;\n        fact[0]\
    \ = 1;\n        for (int i = 1; i <= maxk; i++)\n        {\n            nP[i]\
    \ = nP[i - 1] * (n + 1 - i);\n            fact[i] = fact[i - 1] * i;\n       \
    \ }\n        ifact[maxk] = fact[maxk].inv();\n        for (int i = maxk - 1; i\
    \ >= 0; i--)\n        {\n            ifact[i] = ifact[i + 1] * (i + 1);\n    \
    \    }\n    }\n\n    M operator()(int k)\n    {\n        assert(k <= maxk);\n\
    \        if (k > n || k < 0)\n        {\n            return 0;\n        }\n  \
    \      return nP[k] * ifact[k];\n    }\n\nprivate:\n    long long n;\n    int\
    \ maxk;\n    std::vector<M> nP;\n    std::vector<M> fact;\n    std::vector<M>\
    \ ifact;\n};\n"
  code: "template <typename M>\nstruct CombinationFixN\n{\npublic:\n    CombinationFixN(long\
    \ long n, int maxk) : n(n), maxk(maxk)\n    {\n        nP.resize(maxk + 1);\n\
    \        fact.resize(maxk + 1);\n        ifact.resize(maxk + 1);\n        nP[0]\
    \ = 1;\n        fact[0] = 1;\n        for (int i = 1; i <= maxk; i++)\n      \
    \  {\n            nP[i] = nP[i - 1] * (n + 1 - i);\n            fact[i] = fact[i\
    \ - 1] * i;\n        }\n        ifact[maxk] = fact[maxk].inv();\n        for (int\
    \ i = maxk - 1; i >= 0; i--)\n        {\n            ifact[i] = ifact[i + 1] *\
    \ (i + 1);\n        }\n    }\n\n    M operator()(int k)\n    {\n        assert(k\
    \ <= maxk);\n        if (k > n || k < 0)\n        {\n            return 0;\n \
    \       }\n        return nP[k] * ifact[k];\n    }\n\nprivate:\n    long long\
    \ n;\n    int maxk;\n    std::vector<M> nP;\n    std::vector<M> fact;\n    std::vector<M>\
    \ ifact;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/CombinationFixN.hpp
  requiredBy: []
  timestamp: '2023-03-08 19:41:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2130.test.cpp
documentation_of: lib/math/CombinationFixN.hpp
layout: document
redirect_from:
- /library/lib/math/CombinationFixN.hpp
- /library/lib/math/CombinationFixN.hpp.html
title: lib/math/CombinationFixN.hpp
---
