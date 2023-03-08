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
  bundledCode: "#line 1 \"lib/math/Combination.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename MODINT>\nstruct CombinationStructure\n{\npublic:\n\
    \    CombinationStructure()\n    {\n        fact = {1, 1};\n        fact_inverse\
    \ = {1, 1};\n    }\n\n    void size_up(int n)\n    {\n        int old_n = fact.size()\
    \ - 1;\n        if(n <= old_n)\n        {\n            return;\n        }\n  \
    \      n = std::max(n, old_n * 2);\n        fact.resize(n + 1);\n        fact_inverse.resize(n\
    \ + 1);\n        for (int i = old_n + 1; i <= n; i++)\n        {\n           \
    \ fact[i] = fact[i - 1] * i;\n        }\n        fact_inverse[n] = fact[n].inv();\n\
    \        for (int i = n - 1; i >= old_n + 1; i--)\n        {\n            fact_inverse[i]\
    \ = fact_inverse[i + 1] * (i + 1);\n        }\n    }\n\n    MODINT C(int n, int\
    \ k)\n    {\n        size_up(n);\n        if (k > n || k < 0)\n        {\n   \
    \         return 0;\n        }\n        return fact[n] * fact_inverse[k] * fact_inverse[n\
    \ - k];\n    }\n\n    MODINT P(int n, int k)\n    {\n        assert(k >= 0);\n\
    \        size_up(n);\n        if(k > n)\n        {\n            return 0;\n  \
    \      }\n        return fact[n] * fact_inverse[n - k];\n    }\n\n    MODINT factorial(int\
    \ n)\n    {\n        size_up(n);\n        return fact[n];\n    }\n\n    MODINT\
    \ operator()(int n, int k)\n    {\n        return C(n, k);\n    }\n\nprivate:\n\
    \    int maxn;\n    std::vector<MODINT> fact;\n    std::vector<MODINT> fact_inverse;\n\
    };\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate <typename MODINT>\nstruct\
    \ CombinationStructure\n{\npublic:\n    CombinationStructure()\n    {\n      \
    \  fact = {1, 1};\n        fact_inverse = {1, 1};\n    }\n\n    void size_up(int\
    \ n)\n    {\n        int old_n = fact.size() - 1;\n        if(n <= old_n)\n  \
    \      {\n            return;\n        }\n        n = std::max(n, old_n * 2);\n\
    \        fact.resize(n + 1);\n        fact_inverse.resize(n + 1);\n        for\
    \ (int i = old_n + 1; i <= n; i++)\n        {\n            fact[i] = fact[i -\
    \ 1] * i;\n        }\n        fact_inverse[n] = fact[n].inv();\n        for (int\
    \ i = n - 1; i >= old_n + 1; i--)\n        {\n            fact_inverse[i] = fact_inverse[i\
    \ + 1] * (i + 1);\n        }\n    }\n\n    MODINT C(int n, int k)\n    {\n   \
    \     size_up(n);\n        if (k > n || k < 0)\n        {\n            return\
    \ 0;\n        }\n        return fact[n] * fact_inverse[k] * fact_inverse[n - k];\n\
    \    }\n\n    MODINT P(int n, int k)\n    {\n        assert(k >= 0);\n       \
    \ size_up(n);\n        if(k > n)\n        {\n            return 0;\n        }\n\
    \        return fact[n] * fact_inverse[n - k];\n    }\n\n    MODINT factorial(int\
    \ n)\n    {\n        size_up(n);\n        return fact[n];\n    }\n\n    MODINT\
    \ operator()(int n, int k)\n    {\n        return C(n, k);\n    }\n\nprivate:\n\
    \    int maxn;\n    std::vector<MODINT> fact;\n    std::vector<MODINT> fact_inverse;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Combination.hpp
  requiredBy: []
  timestamp: '2023-03-09 00:20:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2141.test.cpp
documentation_of: lib/math/Combination.hpp
layout: document
redirect_from:
- /library/lib/math/Combination.hpp
- /library/lib/math/Combination.hpp.html
title: lib/math/Combination.hpp
---
