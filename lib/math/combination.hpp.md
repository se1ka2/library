---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2141.test.cpp
    title: test/yukicoder/no_2141.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/combination.hpp\"\ntemplate <typename M>\nstruct\
    \ combination\n{\npublic:\n    combination(int maxn) : maxn(maxn)\n    {\n   \
    \     fact.resize(maxn + 1);\n        ifact.resize(maxn + 1);\n        fact[0]\
    \ = 1;\n        for (int i = 1; i <= maxn; i++)\n        {\n            fact[i]\
    \ = fact[i - 1] * i;\n        }\n        ifact[maxn] = fact[maxn].inv();\n   \
    \     for (int i = maxn - 1; i >= 0; i--)\n        {\n            ifact[i] = ifact[i\
    \ + 1] * (i + 1);\n        }\n    }\n\n    M operator()(int n, int k)\n    {\n\
    \        assert(n <= maxn);\n        if (k > n || k < 0)\n        {\n        \
    \    return 0;\n        }\n        return fact[n] * ifact[k] * ifact[n - k];\n\
    \    }\n\nprivate:\n    int maxn;\n    std::vector<M> fact;\n    std::vector<M>\
    \ ifact;\n};\n"
  code: "template <typename M>\nstruct combination\n{\npublic:\n    combination(int\
    \ maxn) : maxn(maxn)\n    {\n        fact.resize(maxn + 1);\n        ifact.resize(maxn\
    \ + 1);\n        fact[0] = 1;\n        for (int i = 1; i <= maxn; i++)\n     \
    \   {\n            fact[i] = fact[i - 1] * i;\n        }\n        ifact[maxn]\
    \ = fact[maxn].inv();\n        for (int i = maxn - 1; i >= 0; i--)\n        {\n\
    \            ifact[i] = ifact[i + 1] * (i + 1);\n        }\n    }\n\n    M operator()(int\
    \ n, int k)\n    {\n        assert(n <= maxn);\n        if (k > n || k < 0)\n\
    \        {\n            return 0;\n        }\n        return fact[n] * ifact[k]\
    \ * ifact[n - k];\n    }\n\nprivate:\n    int maxn;\n    std::vector<M> fact;\n\
    \    std::vector<M> ifact;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/combination.hpp
  requiredBy: []
  timestamp: '2023-01-14 04:04:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2141.test.cpp
documentation_of: lib/math/combination.hpp
layout: document
redirect_from:
- /library/lib/math/combination.hpp
- /library/lib/math/combination.hpp.html
title: lib/math/combination.hpp
---
