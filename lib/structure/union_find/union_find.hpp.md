---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/structure/union_find/union_find.hpp\"\nstruct union_find\r\
    \n{\r\n    int n;\r\n    std::vector<int> par;\r\n    std::vector<int> sz;\r\n\
    \    int num_of_components;\r\n\r\n    union_find(int n) : n(n)\r\n    {\r\n \
    \       par.resize(n);\r\n        sz.resize(n);\r\n        for (int i = 0; i <\
    \ n; i++)\r\n        {\r\n            par[i] = i;\r\n            sz[i] = 1;\r\n\
    \        }\r\n        num_of_components = n;\r\n    }\r\n\r\n    int find(int\
    \ i)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        return (i == par[i])\
    \ ? i : par[i] = find(par[i]);\r\n    }\r\n\r\n    bool same(int i, int j)\r\n\
    \    {\r\n        assert(0 <= i && i < n);\r\n        assert(0 <= j && j < n);\r\
    \n        return find(i) == find(j);\r\n    }\r\n\r\n    void unite(int i, int\
    \ j)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        assert(0 <= j &&\
    \ j < n);\r\n        i = find(i), j = find(j);\r\n        if (i == j)\r\n    \
    \    {\r\n            return;\r\n        }\r\n        if (sz[i] < sz[j])\r\n \
    \       {\r\n            std::swap(i, j);\r\n        }\r\n        par[j] = i;\r\
    \n        sz[i] += sz[j];\r\n        num_of_components--;\r\n    }\r\n\r\n   \
    \ int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    int size(int i)\r\
    \n    {\r\n        assert(0 <= i && i < n);\r\n        return sz[find(i)];\r\n\
    \    }\r\n\r\n    int count()\r\n    {\r\n        return num_of_components;\r\n\
    \    }\r\n\r\n    bool is_root(int i)\r\n    {\r\n        assert(0 <= i && i <\
    \ n);\r\n        return i == find(i);\r\n    }\r\n\r\n    int operator[](int i)\r\
    \n    {\r\n        return find(i);\r\n    }\r\n};\r\n"
  code: "struct union_find\r\n{\r\n    int n;\r\n    std::vector<int> par;\r\n   \
    \ std::vector<int> sz;\r\n    int num_of_components;\r\n\r\n    union_find(int\
    \ n) : n(n)\r\n    {\r\n        par.resize(n);\r\n        sz.resize(n);\r\n  \
    \      for (int i = 0; i < n; i++)\r\n        {\r\n            par[i] = i;\r\n\
    \            sz[i] = 1;\r\n        }\r\n        num_of_components = n;\r\n   \
    \ }\r\n\r\n    int find(int i)\r\n    {\r\n        assert(0 <= i && i < n);\r\n\
    \        return (i == par[i]) ? i : par[i] = find(par[i]);\r\n    }\r\n\r\n  \
    \  bool same(int i, int j)\r\n    {\r\n        assert(0 <= i && i < n);\r\n  \
    \      assert(0 <= j && j < n);\r\n        return find(i) == find(j);\r\n    }\r\
    \n\r\n    void unite(int i, int j)\r\n    {\r\n        assert(0 <= i && i < n);\r\
    \n        assert(0 <= j && j < n);\r\n        i = find(i), j = find(j);\r\n  \
    \      if (i == j)\r\n        {\r\n            return;\r\n        }\r\n      \
    \  if (sz[i] < sz[j])\r\n        {\r\n            std::swap(i, j);\r\n       \
    \ }\r\n        par[j] = i;\r\n        sz[i] += sz[j];\r\n        num_of_components--;\r\
    \n    }\r\n\r\n    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n \
    \   int size(int i)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        return\
    \ sz[find(i)];\r\n    }\r\n\r\n    int count()\r\n    {\r\n        return num_of_components;\r\
    \n    }\r\n\r\n    bool is_root(int i)\r\n    {\r\n        assert(0 <= i && i\
    \ < n);\r\n        return i == find(i);\r\n    }\r\n\r\n    int operator[](int\
    \ i)\r\n    {\r\n        return find(i);\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/union_find/union_find.hpp
  requiredBy: []
  timestamp: '2022-12-10 07:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/structure/union_find/union_find.hpp
layout: document
redirect_from:
- /library/lib/structure/union_find/union_find.hpp
- /library/lib/structure/union_find/union_find.hpp.html
title: lib/structure/union_find/union_find.hpp
---
