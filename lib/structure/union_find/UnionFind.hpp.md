---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_11_D.test.cpp
    title: test/aoj/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/unionfind.test.cpp
    title: test/library_checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/structure/union_find/UnionFind.hpp\"\nstruct UnionFind\r\
    \n{\r\npublic:\r\n    UnionFind(int n) : n(n), par(n), sz(n, 1), num_of_components(n)\r\
    \n    {\r\n        for (int i = 0; i < n; i++)\r\n        {\r\n            par[i]\
    \ = i;\r\n        }\r\n    }\r\n\r\n    int find(int i)\r\n    {\r\n        assert(0\
    \ <= i && i < n);\r\n        return (i == par[i]) ? i : par[i] = find(par[i]);\r\
    \n    }\r\n\r\n    bool same(int i, int j)\r\n    {\r\n        assert(0 <= i &&\
    \ i < n);\r\n        assert(0 <= j && j < n);\r\n        return find(i) == find(j);\r\
    \n    }\r\n\r\n    void unite(int i, int j)\r\n    {\r\n        assert(0 <= i\
    \ && i < n);\r\n        assert(0 <= j && j < n);\r\n        i = find(i), j = find(j);\r\
    \n        if (i == j)\r\n        {\r\n            return;\r\n        }\r\n   \
    \     if (sz[i] < sz[j])\r\n        {\r\n            std::swap(i, j);\r\n    \
    \    }\r\n        par[j] = i;\r\n        sz[i] += sz[j];\r\n        num_of_components--;\r\
    \n    }\r\n\r\n    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n \
    \   int size(int i)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        return\
    \ sz[find(i)];\r\n    }\r\n\r\n    int count()\r\n    {\r\n        return num_of_components;\r\
    \n    }\r\n\r\n    bool is_root(int i)\r\n    {\r\n        assert(0 <= i && i\
    \ < n);\r\n        return i == find(i);\r\n    }\r\n\r\n    int operator[](int\
    \ i)\r\n    {\r\n        return find(i);\r\n    }\r\n\r\nprivate:\r\n    int n;\r\
    \n    std::vector<int> par;\r\n    std::vector<int> sz;\r\n    int num_of_components;\r\
    \n};\r\n"
  code: "struct UnionFind\r\n{\r\npublic:\r\n    UnionFind(int n) : n(n), par(n),\
    \ sz(n, 1), num_of_components(n)\r\n    {\r\n        for (int i = 0; i < n; i++)\r\
    \n        {\r\n            par[i] = i;\r\n        }\r\n    }\r\n\r\n    int find(int\
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
    \n    {\r\n        return find(i);\r\n    }\r\n\r\nprivate:\r\n    int n;\r\n\
    \    std::vector<int> par;\r\n    std::vector<int> sz;\r\n    int num_of_components;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/union_find/UnionFind.hpp
  requiredBy: []
  timestamp: '2023-03-08 20:02:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/unionfind.test.cpp
  - test/aoj/ALDS1_11_D.test.cpp
documentation_of: lib/structure/union_find/UnionFind.hpp
layout: document
redirect_from:
- /library/lib/structure/union_find/UnionFind.hpp
- /library/lib/structure/union_find/UnionFind.hpp.html
title: lib/structure/union_find/UnionFind.hpp
---
