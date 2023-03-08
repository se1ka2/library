---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/scc.test.cpp
    title: test/library_checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/other/SCC.hpp\"\ntemplate <typename GRAPH>\r\n\
    struct SCC\r\n{\r\npublic:\r\n    std::vector<std::vector<int>> group;\r\n\r\n\
    \    SCC() {}\r\n\r\n    SCC(GRAPH &g) : n(g.size()), k(0), g(g), cmp(n)\r\n \
    \   {\r\n        std::vector<std::vector<int>> rg(n);\r\n        std::vector<bool>\
    \ used(n);\r\n        std::vector<int> vs;\r\n\r\n        auto dfs = [&](auto\
    \ self, int u) -> void\r\n        {\r\n            used[u] = true;\r\n       \
    \     for (int v : g[u])\r\n            {\r\n                if (!used[v])\r\n\
    \                {\r\n                    self(self, v);\r\n                }\r\
    \n            }\r\n            vs.push_back(u);\r\n        };\r\n\r\n        auto\
    \ rdfs = [&](auto self, int u) -> void\r\n        {\r\n            used[u] = true;\r\
    \n            cmp[u] = k;\r\n            for (int v : rg[u])\r\n            {\r\
    \n                if (!used[v])\r\n                {\r\n                    self(self,\
    \ v);\r\n                }\r\n            }\r\n        };\r\n\r\n        for (int\
    \ u = 0; u < n; u++)\r\n        {\r\n            for (int v : g[u])\r\n      \
    \      {\r\n                rg[v].push_back(u);\r\n            }\r\n        }\r\
    \n        for (int u = 0; u < n; u++)\r\n        {\r\n            if (!used[u])\r\
    \n            {\r\n                dfs(dfs, u);\r\n            }\r\n        }\r\
    \n        fill(used.begin(), used.end(), false);\r\n        for (int i = n - 1;\
    \ i >= 0; i--)\r\n        {\r\n            if (!used[vs[i]])\r\n            {\r\
    \n                rdfs(rdfs, vs[i]);\r\n                k++;\r\n            }\r\
    \n        }\r\n        group.resize(k);\r\n        for (int u = 0; u < n; u++)\r\
    \n        {\r\n            group[cmp[u]].push_back(u);\r\n        }\r\n    }\r\
    \n\r\n    GRAPH get_dag()\r\n    {\r\n        std::vector<bool> b(k);\r\n    \
    \    GRAPH dag(k);\r\n        for (int x = 0; x < k; x++)\r\n        {\r\n   \
    \         for (int u : group[x])\r\n            {\r\n                for (int\
    \ v : g[u])\r\n                {\r\n                    int y = cmp[v];\r\n  \
    \                  if (!b[y])\r\n                    {\r\n                   \
    \     dag.add_directed_edge(x, y);\r\n                        b[y] = true;\r\n\
    \                    }\r\n                }\r\n            }\r\n            for\
    \ (int u : group[x])\r\n            {\r\n                for (int v : g[u])\r\n\
    \                {\r\n                    b[cmp[v]] = false;\r\n             \
    \   }\r\n            }\r\n        }\r\n        return dag;\r\n    }\r\n\r\n  \
    \  int number_of_component()\r\n    {\r\n        return k;\r\n    }\r\n\r\n  \
    \  const int operator[](const int &u) const\r\n    {\r\n        return cmp[u];\r\
    \n    }\r\n\r\nprivate:\r\n    int n;\r\n    int k;\r\n    const GRAPH &g;\r\n\
    \    std::vector<int> cmp;\r\n};\r\n"
  code: "template <typename GRAPH>\r\nstruct SCC\r\n{\r\npublic:\r\n    std::vector<std::vector<int>>\
    \ group;\r\n\r\n    SCC() {}\r\n\r\n    SCC(GRAPH &g) : n(g.size()), k(0), g(g),\
    \ cmp(n)\r\n    {\r\n        std::vector<std::vector<int>> rg(n);\r\n        std::vector<bool>\
    \ used(n);\r\n        std::vector<int> vs;\r\n\r\n        auto dfs = [&](auto\
    \ self, int u) -> void\r\n        {\r\n            used[u] = true;\r\n       \
    \     for (int v : g[u])\r\n            {\r\n                if (!used[v])\r\n\
    \                {\r\n                    self(self, v);\r\n                }\r\
    \n            }\r\n            vs.push_back(u);\r\n        };\r\n\r\n        auto\
    \ rdfs = [&](auto self, int u) -> void\r\n        {\r\n            used[u] = true;\r\
    \n            cmp[u] = k;\r\n            for (int v : rg[u])\r\n            {\r\
    \n                if (!used[v])\r\n                {\r\n                    self(self,\
    \ v);\r\n                }\r\n            }\r\n        };\r\n\r\n        for (int\
    \ u = 0; u < n; u++)\r\n        {\r\n            for (int v : g[u])\r\n      \
    \      {\r\n                rg[v].push_back(u);\r\n            }\r\n        }\r\
    \n        for (int u = 0; u < n; u++)\r\n        {\r\n            if (!used[u])\r\
    \n            {\r\n                dfs(dfs, u);\r\n            }\r\n        }\r\
    \n        fill(used.begin(), used.end(), false);\r\n        for (int i = n - 1;\
    \ i >= 0; i--)\r\n        {\r\n            if (!used[vs[i]])\r\n            {\r\
    \n                rdfs(rdfs, vs[i]);\r\n                k++;\r\n            }\r\
    \n        }\r\n        group.resize(k);\r\n        for (int u = 0; u < n; u++)\r\
    \n        {\r\n            group[cmp[u]].push_back(u);\r\n        }\r\n    }\r\
    \n\r\n    GRAPH get_dag()\r\n    {\r\n        std::vector<bool> b(k);\r\n    \
    \    GRAPH dag(k);\r\n        for (int x = 0; x < k; x++)\r\n        {\r\n   \
    \         for (int u : group[x])\r\n            {\r\n                for (int\
    \ v : g[u])\r\n                {\r\n                    int y = cmp[v];\r\n  \
    \                  if (!b[y])\r\n                    {\r\n                   \
    \     dag.add_directed_edge(x, y);\r\n                        b[y] = true;\r\n\
    \                    }\r\n                }\r\n            }\r\n            for\
    \ (int u : group[x])\r\n            {\r\n                for (int v : g[u])\r\n\
    \                {\r\n                    b[cmp[v]] = false;\r\n             \
    \   }\r\n            }\r\n        }\r\n        return dag;\r\n    }\r\n\r\n  \
    \  int number_of_component()\r\n    {\r\n        return k;\r\n    }\r\n\r\n  \
    \  const int operator[](const int &u) const\r\n    {\r\n        return cmp[u];\r\
    \n    }\r\n\r\nprivate:\r\n    int n;\r\n    int k;\r\n    const GRAPH &g;\r\n\
    \    std::vector<int> cmp;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/SCC.hpp
  requiredBy: []
  timestamp: '2023-03-08 14:28:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/scc.test.cpp
  - test/aoj/GRL_3_C.test.cpp
documentation_of: lib/graph/other/SCC.hpp
layout: document
redirect_from:
- /library/lib/graph/other/SCC.hpp
- /library/lib/graph/other/SCC.hpp.html
title: lib/graph/other/SCC.hpp
---
