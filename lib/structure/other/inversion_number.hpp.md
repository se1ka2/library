---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_5_D.test.cpp
    title: test/aoj/ALDS1_5_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/structure/other/inversion_number.hpp\"\nlong long inversion_number(std::vector<int>\
    \ &a)\n{\n    int n = a.size();\n    std::vector<int> q = compression(a, true);\n\
    \    int k = q.back() + 1;\n    BinaryIndexedTree<int> bit(k);\n    long long\
    \ res = 0;\n    for (int i = n - 1; i >= 0; i--)\n    {\n        res += bit.sum(q[i]);\n\
    \        bit.add(q[i], 1);\n    }\n    return res;\n}\n"
  code: "long long inversion_number(std::vector<int> &a)\n{\n    int n = a.size();\n\
    \    std::vector<int> q = compression(a, true);\n    int k = q.back() + 1;\n \
    \   BinaryIndexedTree<int> bit(k);\n    long long res = 0;\n    for (int i = n\
    \ - 1; i >= 0; i--)\n    {\n        res += bit.sum(q[i]);\n        bit.add(q[i],\
    \ 1);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/other/inversion_number.hpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_5_D.test.cpp
documentation_of: lib/structure/other/inversion_number.hpp
layout: document
redirect_from:
- /library/lib/structure/other/inversion_number.hpp
- /library/lib/structure/other/inversion_number.hpp.html
title: lib/structure/other/inversion_number.hpp
---
