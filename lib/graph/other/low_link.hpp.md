---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/other/low_link.hpp\"\ntemplate <typename G, typename\
    \ T = int>\r\nstruct low_link\r\n{\r\npublic:\r\n    std::vector<int> articulation;\r\
    \n    std::vector<edge<T>> bridge;\r\n\r\n    low_link() {}\r\n\r\n    low_link(G\
    \ &g) : n(g.size()), g(g), ord(g.size(), -1), low(g.size(), -1)\r\n    {\r\n \
    \       int k = 0;\r\n        for (int u = 0; u < n; u++)\r\n        {\r\n   \
    \         if (ord[u] == -1)\r\n            {\r\n                dfs(u, -1, k);\r\
    \n            }\r\n        }\r\n    }\r\n\r\nprivate:\r\n    int n;\r\n    const\
    \ G &g;\r\n    std::vector<int> ord;\r\n    std::vector<int> low;\r\n\r\n    void\
    \ dfs(int u, int last_edge_id, int &k)\r\n    {\r\n        low[u] = ord[u] = k++;\r\
    \n        int c = 0;\r\n        bool is_artification = false;\r\n        for (edge<T>\
    \ e : g[u])\r\n        {\r\n            int v = e.to;\r\n            if (e.id\
    \ == last_edge_id)\r\n            {\r\n                continue;\r\n         \
    \   }\r\n            if (ord[v] == -1)\r\n            {\r\n                c++;\r\
    \n                dfs(v, e.id, k);\r\n                if (last_edge_id != -1 &&\
    \ ord[u] <= low[v])\r\n                {\r\n                    is_artification\
    \ = true;\r\n                }\r\n                if (ord[u] < low[v])\r\n   \
    \             {\r\n                    bridge.push_back(e);\r\n              \
    \  }\r\n                low[u] = std::min(low[u], low[v]);\r\n            }\r\n\
    \            low[u] = std::min(low[u], ord[v]);\r\n        }\r\n        is_artification\
    \ |= (last_edge_id == -1 && c >= 2);\r\n        if (is_artification)\r\n     \
    \   {\r\n            articulation.push_back(u);\r\n        }\r\n    }\r\n};\r\n"
  code: "template <typename G, typename T = int>\r\nstruct low_link\r\n{\r\npublic:\r\
    \n    std::vector<int> articulation;\r\n    std::vector<edge<T>> bridge;\r\n\r\
    \n    low_link() {}\r\n\r\n    low_link(G &g) : n(g.size()), g(g), ord(g.size(),\
    \ -1), low(g.size(), -1)\r\n    {\r\n        int k = 0;\r\n        for (int u\
    \ = 0; u < n; u++)\r\n        {\r\n            if (ord[u] == -1)\r\n         \
    \   {\r\n                dfs(u, -1, k);\r\n            }\r\n        }\r\n    }\r\
    \n\r\nprivate:\r\n    int n;\r\n    const G &g;\r\n    std::vector<int> ord;\r\
    \n    std::vector<int> low;\r\n\r\n    void dfs(int u, int last_edge_id, int &k)\r\
    \n    {\r\n        low[u] = ord[u] = k++;\r\n        int c = 0;\r\n        bool\
    \ is_artification = false;\r\n        for (edge<T> e : g[u])\r\n        {\r\n\
    \            int v = e.to;\r\n            if (e.id == last_edge_id)\r\n      \
    \      {\r\n                continue;\r\n            }\r\n            if (ord[v]\
    \ == -1)\r\n            {\r\n                c++;\r\n                dfs(v, e.id,\
    \ k);\r\n                if (last_edge_id != -1 && ord[u] <= low[v])\r\n     \
    \           {\r\n                    is_artification = true;\r\n             \
    \   }\r\n                if (ord[u] < low[v])\r\n                {\r\n       \
    \             bridge.push_back(e);\r\n                }\r\n                low[u]\
    \ = std::min(low[u], low[v]);\r\n            }\r\n            low[u] = std::min(low[u],\
    \ ord[v]);\r\n        }\r\n        is_artification |= (last_edge_id == -1 && c\
    \ >= 2);\r\n        if (is_artification)\r\n        {\r\n            articulation.push_back(u);\r\
    \n        }\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/low_link.hpp
  requiredBy: []
  timestamp: '2022-12-20 02:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/GRL_3_A.test.cpp
documentation_of: lib/graph/other/low_link.hpp
layout: document
redirect_from:
- /library/lib/graph/other/low_link.hpp
- /library/lib/graph/other/low_link.hpp.html
title: lib/graph/other/low_link.hpp
---
