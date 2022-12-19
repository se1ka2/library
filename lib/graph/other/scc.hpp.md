---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/scc.test.cpp
    title: test/library_checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/other/scc.hpp\"\ntemplate <typename G, typename\
    \ T = int>\r\nstruct scc_structure\r\n{\r\npublic:\r\n    std::vector<std::vector<int>>\
    \ group;\r\n\r\n    scc_structure() {}\r\n\r\n    scc_structure(G &g) : n(g.size()),\
    \ k(0), g(g), rg(g.size()), cmp(n), used(n)\r\n    {\r\n        for (int u = 0;\
    \ u < n; u++)\r\n        {\r\n            for (int v : g[u])\r\n            {\r\
    \n                rg[v].push_back(u);\r\n            }\r\n        }\r\n      \
    \  for (int u = 0; u < n; u++)\r\n        {\r\n            if (!used[u])\r\n \
    \           {\r\n                dfs(u);\r\n            }\r\n        }\r\n   \
    \     fill(used.begin(), used.end(), false);\r\n        for (int i = n - 1; i\
    \ >= 0; i--)\r\n        {\r\n            if (!used[vs[i]])\r\n            {\r\n\
    \                rdfs(vs[i], k++);\r\n            }\r\n        }\r\n        group.resize(k);\r\
    \n        for (int u = 0; u < n; u++)\r\n        {\r\n            group[cmp[u]].push_back(u);\r\
    \n        }\r\n    }\r\n\r\n    graph<int> get_dag()\r\n    {\r\n        std::vector<bool>\
    \ b(k);\r\n        graph<int> dag(k);\r\n        for (int x = 0; x < k; x++)\r\
    \n        {\r\n            for (int u : group[x])\r\n            {\r\n       \
    \         for (int v : g[u])\r\n                {\r\n                    int y\
    \ = cmp[v];\r\n                    if (!b[y])\r\n                    {\r\n   \
    \                     dag.add_directed_edge(x, y);\r\n                       \
    \ b[y] = true;\r\n                    }\r\n                }\r\n            }\r\
    \n            for (int u : group[x])\r\n            {\r\n                for (int\
    \ v : g[u])\r\n                {\r\n                    b[cmp[v]] = false;\r\n\
    \                }\r\n            }\r\n        }\r\n        return dag;\r\n  \
    \  }\r\n\r\n    int number_of_component()\r\n    {\r\n        return k;\r\n  \
    \  }\r\n\r\n    const int operator[](const int &u) const\r\n    {\r\n        return\
    \ cmp[u];\r\n    }\r\n\r\nprivate:\r\n    int n;\r\n    int k;\r\n    const G\
    \ &g;\r\n    std::vector<std::vector<int>> rg;\r\n    std::vector<int> cmp;\r\n\
    \    std::vector<bool> used;\r\n    std::vector<int> vs;\r\n\r\n    void dfs(int\
    \ u)\r\n    {\r\n        used[u] = true;\r\n        for (int v : g[u])\r\n   \
    \     {\r\n            if (!used[v])\r\n            {\r\n                dfs(v);\r\
    \n            }\r\n        }\r\n        vs.push_back(u);\r\n    }\r\n\r\n    void\
    \ rdfs(int u, int k)\r\n    {\r\n        used[u] = true;\r\n        cmp[u] = k;\r\
    \n        for (int v : rg[u])\r\n        {\r\n            if (!used[v])\r\n  \
    \          {\r\n                rdfs(v, k);\r\n            }\r\n        }\r\n\
    \    }\r\n};\r\n"
  code: "template <typename G, typename T = int>\r\nstruct scc_structure\r\n{\r\n\
    public:\r\n    std::vector<std::vector<int>> group;\r\n\r\n    scc_structure()\
    \ {}\r\n\r\n    scc_structure(G &g) : n(g.size()), k(0), g(g), rg(g.size()), cmp(n),\
    \ used(n)\r\n    {\r\n        for (int u = 0; u < n; u++)\r\n        {\r\n   \
    \         for (int v : g[u])\r\n            {\r\n                rg[v].push_back(u);\r\
    \n            }\r\n        }\r\n        for (int u = 0; u < n; u++)\r\n      \
    \  {\r\n            if (!used[u])\r\n            {\r\n                dfs(u);\r\
    \n            }\r\n        }\r\n        fill(used.begin(), used.end(), false);\r\
    \n        for (int i = n - 1; i >= 0; i--)\r\n        {\r\n            if (!used[vs[i]])\r\
    \n            {\r\n                rdfs(vs[i], k++);\r\n            }\r\n    \
    \    }\r\n        group.resize(k);\r\n        for (int u = 0; u < n; u++)\r\n\
    \        {\r\n            group[cmp[u]].push_back(u);\r\n        }\r\n    }\r\n\
    \r\n    graph<int> get_dag()\r\n    {\r\n        std::vector<bool> b(k);\r\n \
    \       graph<int> dag(k);\r\n        for (int x = 0; x < k; x++)\r\n        {\r\
    \n            for (int u : group[x])\r\n            {\r\n                for (int\
    \ v : g[u])\r\n                {\r\n                    int y = cmp[v];\r\n  \
    \                  if (!b[y])\r\n                    {\r\n                   \
    \     dag.add_directed_edge(x, y);\r\n                        b[y] = true;\r\n\
    \                    }\r\n                }\r\n            }\r\n            for\
    \ (int u : group[x])\r\n            {\r\n                for (int v : g[u])\r\n\
    \                {\r\n                    b[cmp[v]] = false;\r\n             \
    \   }\r\n            }\r\n        }\r\n        return dag;\r\n    }\r\n\r\n  \
    \  int number_of_component()\r\n    {\r\n        return k;\r\n    }\r\n\r\n  \
    \  const int operator[](const int &u) const\r\n    {\r\n        return cmp[u];\r\
    \n    }\r\n\r\nprivate:\r\n    int n;\r\n    int k;\r\n    const G &g;\r\n   \
    \ std::vector<std::vector<int>> rg;\r\n    std::vector<int> cmp;\r\n    std::vector<bool>\
    \ used;\r\n    std::vector<int> vs;\r\n\r\n    void dfs(int u)\r\n    {\r\n  \
    \      used[u] = true;\r\n        for (int v : g[u])\r\n        {\r\n        \
    \    if (!used[v])\r\n            {\r\n                dfs(v);\r\n           \
    \ }\r\n        }\r\n        vs.push_back(u);\r\n    }\r\n\r\n    void rdfs(int\
    \ u, int k)\r\n    {\r\n        used[u] = true;\r\n        cmp[u] = k;\r\n   \
    \     for (int v : rg[u])\r\n        {\r\n            if (!used[v])\r\n      \
    \      {\r\n                rdfs(v, k);\r\n            }\r\n        }\r\n    }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/scc.hpp
  requiredBy: []
  timestamp: '2022-12-20 02:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/scc.test.cpp
documentation_of: lib/graph/other/scc.hpp
layout: document
redirect_from:
- /library/lib/graph/other/scc.hpp
- /library/lib/graph/other/scc.hpp.html
title: lib/graph/other/scc.hpp
---
