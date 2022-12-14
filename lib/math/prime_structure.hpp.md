---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/no_2081.test.cpp
    title: test/yukicoder/no_2081.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/prime_structure.hpp\"\nstruct prime_sturcture\n\
    {\npublic:\n    prime_sturcture(int max_n) : max_n(max_n), p(max_n + 1, true)\n\
    \    {\n        p[0] = p[1] = false;\n        for (int i = 2; i <= max_n; i++)\n\
    \        {\n            if (p[i])\n            {\n                prime_list.push_back(i);\n\
    \                for (int j = i * 2; j <= max_n; j += i)\n                {\n\
    \                    p[j] = false;\n                }\n            }\n       \
    \ }\n    }\n\n    bool is_prime(int n)\n    {\n        assert(n <= max_n);\n \
    \       return p[n];\n    }\n\n    int size()\n    {\n        return prime_list.size();\n\
    \    }\n\n    const int operator[](int i) const\n    {\n        assert(i < (int)prime_list.size());\n\
    \        return prime_list[i];\n    }\n\n    std::vector<int>::const_iterator\
    \ begin()\n    {\n        return prime_list.begin();\n    }\n\n    std::vector<int>::const_iterator\
    \ end()\n    {\n        return prime_list.end();\n    }\n\nprivate:\n    int max_n;\n\
    \    std::vector<bool> p;\n    std::vector<int> prime_list;\n};\n"
  code: "struct prime_sturcture\n{\npublic:\n    prime_sturcture(int max_n) : max_n(max_n),\
    \ p(max_n + 1, true)\n    {\n        p[0] = p[1] = false;\n        for (int i\
    \ = 2; i <= max_n; i++)\n        {\n            if (p[i])\n            {\n   \
    \             prime_list.push_back(i);\n                for (int j = i * 2; j\
    \ <= max_n; j += i)\n                {\n                    p[j] = false;\n  \
    \              }\n            }\n        }\n    }\n\n    bool is_prime(int n)\n\
    \    {\n        assert(n <= max_n);\n        return p[n];\n    }\n\n    int size()\n\
    \    {\n        return prime_list.size();\n    }\n\n    const int operator[](int\
    \ i) const\n    {\n        assert(i < (int)prime_list.size());\n        return\
    \ prime_list[i];\n    }\n\n    std::vector<int>::const_iterator begin()\n    {\n\
    \        return prime_list.begin();\n    }\n\n    std::vector<int>::const_iterator\
    \ end()\n    {\n        return prime_list.end();\n    }\n\nprivate:\n    int max_n;\n\
    \    std::vector<bool> p;\n    std::vector<int> prime_list;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/prime_structure.hpp
  requiredBy: []
  timestamp: '2022-12-14 22:24:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/no_2081.test.cpp
documentation_of: lib/math/prime_structure.hpp
layout: document
redirect_from:
- /library/lib/math/prime_structure.hpp
- /library/lib/math/prime_structure.hpp.html
title: lib/math/prime_structure.hpp
---
