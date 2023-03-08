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
  bundledCode: "#line 1 \"lib/graph/other/eularian_trail.hpp\"\ntemplate <typename\
    \ GRAPH>\r\nstd::vector<int> eulerian_trail(GRAPH &g, int r = 0, bool return_edges\
    \ = true)\r\n{\r\n    int n = g.size();\r\n    int m = g.edge_size();\r\n    std::vector<int>\
    \ trail;\r\n    std::vector<bool> used(m);\r\n\r\n    auto dfs = [&](auto self,\
    \ int u, int last_edge_id) -> void\r\n    {\r\n        for (auto e : g[u])\r\n\
    \        {\r\n            if (!used[e.id])\r\n            {\r\n              \
    \  used[e.id] = true;\r\n                self(self, e.to, e.id);\r\n         \
    \   }\r\n        }\r\n        if (!return_edges)\r\n        {\r\n            trail.push_back(u);\r\
    \n        }\r\n        else if (last_edge_id != -1)\r\n        {\r\n         \
    \   trail.push_back(last_edge_id);\r\n        }\r\n    };\r\n\r\n    bool even_degree\
    \ = true;\r\n    for (int u = 0; u < n; u++)\r\n    {\r\n        even_degree &=\
    \ !((int)g[u].size() % 2);\r\n    }\r\n    assert(even_degree);\r\n    dfs(dfs,\
    \ r, -1);\r\n    bool connected = true;\r\n    for (int i = 0; i < m; i++)\r\n\
    \    {\r\n        connected &= used[i];\r\n    }\r\n    assert(connected);\r\n\
    \    return trail;\r\n}\r\n"
  code: "template <typename GRAPH>\r\nstd::vector<int> eulerian_trail(GRAPH &g, int\
    \ r = 0, bool return_edges = true)\r\n{\r\n    int n = g.size();\r\n    int m\
    \ = g.edge_size();\r\n    std::vector<int> trail;\r\n    std::vector<bool> used(m);\r\
    \n\r\n    auto dfs = [&](auto self, int u, int last_edge_id) -> void\r\n    {\r\
    \n        for (auto e : g[u])\r\n        {\r\n            if (!used[e.id])\r\n\
    \            {\r\n                used[e.id] = true;\r\n                self(self,\
    \ e.to, e.id);\r\n            }\r\n        }\r\n        if (!return_edges)\r\n\
    \        {\r\n            trail.push_back(u);\r\n        }\r\n        else if\
    \ (last_edge_id != -1)\r\n        {\r\n            trail.push_back(last_edge_id);\r\
    \n        }\r\n    };\r\n\r\n    bool even_degree = true;\r\n    for (int u =\
    \ 0; u < n; u++)\r\n    {\r\n        even_degree &= !((int)g[u].size() % 2);\r\
    \n    }\r\n    assert(even_degree);\r\n    dfs(dfs, r, -1);\r\n    bool connected\
    \ = true;\r\n    for (int i = 0; i < m; i++)\r\n    {\r\n        connected &=\
    \ used[i];\r\n    }\r\n    assert(connected);\r\n    return trail;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/eularian_trail.hpp
  requiredBy: []
  timestamp: '2023-03-08 13:24:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/other/eularian_trail.hpp
layout: document
redirect_from:
- /library/lib/graph/other/eularian_trail.hpp
- /library/lib/graph/other/eularian_trail.hpp.html
title: lib/graph/other/eularian_trail.hpp
---
