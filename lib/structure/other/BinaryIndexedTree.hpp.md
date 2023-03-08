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
  bundledCode: "#line 1 \"lib/structure/other/BinaryIndexedTree.hpp\"\ntemplate <typename\
    \ T>\nstruct BinaryIndexedTree\n{\n    int n;\n    std::vector<T> bit;\n\n   \
    \ BinaryIndexedTree() {}\n\n    BinaryIndexedTree(int n) : n(n)\n    {\n     \
    \   bit.resize(n + 1);\n    }\n\n    T sum(int i) // sum of [0, i)\n    {\n  \
    \      T res = 0;\n        while (i)\n        {\n            res += bit[i];\n\
    \            i -= (i & -i);\n        }\n        return res;\n    }\n\n    T sum(int\
    \ l, int r)\n    {\n        return sum(r) - sum(l);\n    }\n\n    void add(int\
    \ i, T x)\n    {\n        i++;\n        while (i <= n)\n        {\n          \
    \  bit[i] += x;\n            i += (i & -i);\n        }\n    }\n};\n"
  code: "template <typename T>\nstruct BinaryIndexedTree\n{\n    int n;\n    std::vector<T>\
    \ bit;\n\n    BinaryIndexedTree() {}\n\n    BinaryIndexedTree(int n) : n(n)\n\
    \    {\n        bit.resize(n + 1);\n    }\n\n    T sum(int i) // sum of [0, i)\n\
    \    {\n        T res = 0;\n        while (i)\n        {\n            res += bit[i];\n\
    \            i -= (i & -i);\n        }\n        return res;\n    }\n\n    T sum(int\
    \ l, int r)\n    {\n        return sum(r) - sum(l);\n    }\n\n    void add(int\
    \ i, T x)\n    {\n        i++;\n        while (i <= n)\n        {\n          \
    \  bit[i] += x;\n            i += (i & -i);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/other/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_5_D.test.cpp
documentation_of: lib/structure/other/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/lib/structure/other/BinaryIndexedTree.hpp
- /library/lib/structure/other/BinaryIndexedTree.hpp.html
title: lib/structure/other/BinaryIndexedTree.hpp
---
