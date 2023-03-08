---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_11_C.test.cpp
    title: test/aoj/ALDS1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_12_B.test.cpp
    title: test/aoj/ALDS1_12_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_12_C.test.cpp
    title: test/aoj/ALDS1_12_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_4_B.test.cpp
    title: test/aoj/GRL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/scc.test.cpp
    title: test/library_checker/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2095.test.cpp
    title: test/yukicoder/no_2095.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/Graph.hpp\"\ntemplate <typename T = int>\r\nstruct\
    \ Graph\r\n{\r\npublic:\r\n    using value_type = T;\r\n\r\n    struct Edge\r\n\
    \    {\r\n        int from, to;\r\n        T cost;\r\n        int id;\r\n\r\n\
    \        operator int() const\r\n        {\r\n            return to;\r\n     \
    \   }\r\n    };\r\n\r\n    Graph() {}\r\n\r\n    Graph(int n) : n(n), m(0), g(n)\
    \ {}\r\n\r\n    void add_directed_edge(int from, int to, T cost = 1)\r\n    {\r\
    \n        assert(0 <= from && from < n);\r\n        assert(0 <= to && to < n);\r\
    \n        g[from].push_back((Edge){from, to, cost, m++});\r\n    }\r\n\r\n   \
    \ void add_undirected_edge(int from, int to, T cost = 1)\r\n    {\r\n        assert(0\
    \ <= from && from < n);\r\n        assert(0 <= to && to < n);\r\n        g[from].push_back((Edge){from,\
    \ to, cost, m});\r\n        g[to].push_back((Edge){to, from, cost, m++});\r\n\
    \    }\r\n\r\n    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n  \
    \  int edge_size()\r\n    {\r\n        return m;\r\n    }\r\n\r\n    inline const\
    \ std::vector<Edge> &operator[](const int &u) const\r\n    {\r\n        return\
    \ g[u];\r\n    }\r\n\r\n    inline std::vector<Edge> &operator[](const int &u)\r\
    \n    {\r\n        return g[u];\r\n    }\r\n\r\nprivate:\r\n    int n, m;\r\n\
    \    std::vector<std::vector<Edge>> g;\r\n};\r\n"
  code: "template <typename T = int>\r\nstruct Graph\r\n{\r\npublic:\r\n    using\
    \ value_type = T;\r\n\r\n    struct Edge\r\n    {\r\n        int from, to;\r\n\
    \        T cost;\r\n        int id;\r\n\r\n        operator int() const\r\n  \
    \      {\r\n            return to;\r\n        }\r\n    };\r\n\r\n    Graph() {}\r\
    \n\r\n    Graph(int n) : n(n), m(0), g(n) {}\r\n\r\n    void add_directed_edge(int\
    \ from, int to, T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\
    \n        assert(0 <= to && to < n);\r\n        g[from].push_back((Edge){from,\
    \ to, cost, m++});\r\n    }\r\n\r\n    void add_undirected_edge(int from, int\
    \ to, T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\n     \
    \   assert(0 <= to && to < n);\r\n        g[from].push_back((Edge){from, to, cost,\
    \ m});\r\n        g[to].push_back((Edge){to, from, cost, m++});\r\n    }\r\n\r\
    \n    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    int edge_size()\r\
    \n    {\r\n        return m;\r\n    }\r\n\r\n    inline const std::vector<Edge>\
    \ &operator[](const int &u) const\r\n    {\r\n        return g[u];\r\n    }\r\n\
    \r\n    inline std::vector<Edge> &operator[](const int &u)\r\n    {\r\n      \
    \  return g[u];\r\n    }\r\n\r\nprivate:\r\n    int n, m;\r\n    std::vector<std::vector<Edge>>\
    \ g;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/Graph.hpp
  requiredBy: []
  timestamp: '2023-03-08 14:49:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/scc.test.cpp
  - test/yukicoder/no_2095.test.cpp
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/GRL_4_B.test.cpp
  - test/aoj/ALDS1_11_C.test.cpp
  - test/aoj/GRL_3_C.test.cpp
  - test/aoj/GRL_1_A.test.cpp
  - test/aoj/ALDS1_12_C.test.cpp
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/ALDS1_12_B.test.cpp
documentation_of: lib/graph/Graph.hpp
layout: document
redirect_from:
- /library/lib/graph/Graph.hpp
- /library/lib/graph/Graph.hpp.html
title: lib/graph/Graph.hpp
---
