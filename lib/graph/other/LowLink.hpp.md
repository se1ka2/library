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
  bundledCode: "#line 1 \"lib/graph/other/LowLink.hpp\"\ntemplate <typename GRAPH>\r\
    \nstruct LowLink\r\n{\r\npublic:\r\n    using EDGE = typename GRAPH::Edge;\r\n\
    \    std::vector<int> articulation;\r\n    std::vector<EDGE> bridge;\r\n\r\n \
    \   LowLink() {}\r\n\r\n    LowLink(GRAPH &g) : n(g.size()), g(g)\r\n    {\r\n\
    \        std::vector<int> ord(n, -1);\r\n        std::vector<int> low(n, -1);\r\
    \n        int k = 0;\r\n\r\n        auto dfs = [&](auto self, int u, int last_edge_id)\
    \ -> void\r\n        {\r\n            low[u] = ord[u] = k++;\r\n            int\
    \ c = 0;\r\n            bool is_artification = false;\r\n            for (auto\
    \ e : g[u])\r\n            {\r\n                int v = e.to;\r\n            \
    \    if (e.id == last_edge_id)\r\n                {\r\n                    continue;\r\
    \n                }\r\n                if (ord[v] == -1)\r\n                {\r\
    \n                    c++;\r\n                    self(self, v, e.id);\r\n   \
    \                 if (last_edge_id != -1 && ord[u] <= low[v])\r\n            \
    \        {\r\n                        is_artification = true;\r\n            \
    \        }\r\n                    if (ord[u] < low[v])\r\n                   \
    \ {\r\n                        bridge.push_back(e);\r\n                    }\r\
    \n                    low[u] = std::min(low[u], low[v]);\r\n                }\r\
    \n                low[u] = std::min(low[u], ord[v]);\r\n            }\r\n    \
    \        is_artification |= (last_edge_id == -1 && c >= 2);\r\n            if\
    \ (is_artification)\r\n            {\r\n                articulation.push_back(u);\r\
    \n            }\r\n        };\r\n\r\n        for (int u = 0; u < n; u++)\r\n \
    \       {\r\n            if (ord[u] == -1)\r\n            {\r\n              \
    \  dfs(dfs, u, -1);\r\n            }\r\n        }\r\n    }\r\n\r\nprivate:\r\n\
    \    int n;\r\n    const GRAPH &g;\r\n};\r\n"
  code: "template <typename GRAPH>\r\nstruct LowLink\r\n{\r\npublic:\r\n    using\
    \ EDGE = typename GRAPH::Edge;\r\n    std::vector<int> articulation;\r\n    std::vector<EDGE>\
    \ bridge;\r\n\r\n    LowLink() {}\r\n\r\n    LowLink(GRAPH &g) : n(g.size()),\
    \ g(g)\r\n    {\r\n        std::vector<int> ord(n, -1);\r\n        std::vector<int>\
    \ low(n, -1);\r\n        int k = 0;\r\n\r\n        auto dfs = [&](auto self, int\
    \ u, int last_edge_id) -> void\r\n        {\r\n            low[u] = ord[u] = k++;\r\
    \n            int c = 0;\r\n            bool is_artification = false;\r\n    \
    \        for (auto e : g[u])\r\n            {\r\n                int v = e.to;\r\
    \n                if (e.id == last_edge_id)\r\n                {\r\n         \
    \           continue;\r\n                }\r\n                if (ord[v] == -1)\r\
    \n                {\r\n                    c++;\r\n                    self(self,\
    \ v, e.id);\r\n                    if (last_edge_id != -1 && ord[u] <= low[v])\r\
    \n                    {\r\n                        is_artification = true;\r\n\
    \                    }\r\n                    if (ord[u] < low[v])\r\n       \
    \             {\r\n                        bridge.push_back(e);\r\n          \
    \          }\r\n                    low[u] = std::min(low[u], low[v]);\r\n   \
    \             }\r\n                low[u] = std::min(low[u], ord[v]);\r\n    \
    \        }\r\n            is_artification |= (last_edge_id == -1 && c >= 2);\r\
    \n            if (is_artification)\r\n            {\r\n                articulation.push_back(u);\r\
    \n            }\r\n        };\r\n\r\n        for (int u = 0; u < n; u++)\r\n \
    \       {\r\n            if (ord[u] == -1)\r\n            {\r\n              \
    \  dfs(dfs, u, -1);\r\n            }\r\n        }\r\n    }\r\n\r\nprivate:\r\n\
    \    int n;\r\n    const GRAPH &g;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/LowLink.hpp
  requiredBy: []
  timestamp: '2023-03-08 14:01:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/GRL_3_B.test.cpp
documentation_of: lib/graph/other/LowLink.hpp
layout: document
redirect_from:
- /library/lib/graph/other/LowLink.hpp
- /library/lib/graph/other/LowLink.hpp.html
title: lib/graph/other/LowLink.hpp
---
