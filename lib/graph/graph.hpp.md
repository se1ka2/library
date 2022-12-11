---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2095.test.cpp
    title: test/yukicoder/no_2095.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/graph.hpp\"\ntemplate <typename T = int>\r\nstruct\
    \ edge\r\n{\r\n    int from, to;\r\n    T cost;\r\n    int id;\r\n\r\n    operator\
    \ int() const\r\n    {\r\n        return to;\r\n    }\r\n};\r\n\r\ntemplate <typename\
    \ T = int>\r\nstruct graph\r\n{\r\n    int n, m;\r\n    std::vector<std::vector<edge<T>>>\
    \ g;\r\n\r\n    graph() {}\r\n\r\n    graph(int n) : n(n), m(0)\r\n    {\r\n \
    \       g.resize(n);\r\n    }\r\n\r\n    void add_directed_edge(int from, int\
    \ to, T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\n     \
    \   assert(0 <= to && to < n);\r\n        g[from].push_back((edge<T>){from, to,\
    \ cost, m++});\r\n    }\r\n\r\n    void add_undirected_edge(int from, int to,\
    \ T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\n        assert(0\
    \ <= to && to < n);\r\n        g[from].push_back((edge<T>){from, to, cost, m});\r\
    \n        g[to].push_back((edge<T>){to, from, cost, m++});\r\n    }\r\n\r\n  \
    \  int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    int edge_size()\r\
    \n    {\r\n        return m;\r\n    }\r\n\r\n    inline const std::vector<edge<T>>\
    \ &operator[](const int &u) const\r\n    {\r\n        return g[u];\r\n    }\r\n\
    \r\n    inline std::vector<edge<T>> &operator[](const int &u)\r\n    {\r\n   \
    \     return g[u];\r\n    }\r\n};\r\n"
  code: "template <typename T = int>\r\nstruct edge\r\n{\r\n    int from, to;\r\n\
    \    T cost;\r\n    int id;\r\n\r\n    operator int() const\r\n    {\r\n     \
    \   return to;\r\n    }\r\n};\r\n\r\ntemplate <typename T = int>\r\nstruct graph\r\
    \n{\r\n    int n, m;\r\n    std::vector<std::vector<edge<T>>> g;\r\n\r\n    graph()\
    \ {}\r\n\r\n    graph(int n) : n(n), m(0)\r\n    {\r\n        g.resize(n);\r\n\
    \    }\r\n\r\n    void add_directed_edge(int from, int to, T cost = 1)\r\n   \
    \ {\r\n        assert(0 <= from && from < n);\r\n        assert(0 <= to && to\
    \ < n);\r\n        g[from].push_back((edge<T>){from, to, cost, m++});\r\n    }\r\
    \n\r\n    void add_undirected_edge(int from, int to, T cost = 1)\r\n    {\r\n\
    \        assert(0 <= from && from < n);\r\n        assert(0 <= to && to < n);\r\
    \n        g[from].push_back((edge<T>){from, to, cost, m});\r\n        g[to].push_back((edge<T>){to,\
    \ from, cost, m++});\r\n    }\r\n\r\n    int size()\r\n    {\r\n        return\
    \ n;\r\n    }\r\n\r\n    int edge_size()\r\n    {\r\n        return m;\r\n   \
    \ }\r\n\r\n    inline const std::vector<edge<T>> &operator[](const int &u) const\r\
    \n    {\r\n        return g[u];\r\n    }\r\n\r\n    inline std::vector<edge<T>>\
    \ &operator[](const int &u)\r\n    {\r\n        return g[u];\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph.hpp
  requiredBy: []
  timestamp: '2022-12-12 03:52:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2095.test.cpp
documentation_of: lib/graph/graph.hpp
layout: document
redirect_from:
- /library/lib/graph/graph.hpp
- /library/lib/graph/graph.hpp.html
title: lib/graph/graph.hpp
---
