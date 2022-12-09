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
  bundledCode: "#line 1 \"lib/graph/other/low_link.hpp\"\ntemplate <typename G, typename\
    \ T = int>\r\nvoid low_link_sub(int u, int last_edge_id, int &k, G &g, std::vector<int>\
    \ &ord, std::vector<int> &low, std::vector<edge<T>> &bridge)\r\n{\r\n    ord[u]\
    \ = k++;\r\n    low[u] = ord[u];\r\n    for (edge<T> e : g[u])\r\n    {\r\n  \
    \      int v = e.to;\r\n        if (e.id == last_edge_id)\r\n        {\r\n   \
    \         continue;\r\n        }\r\n        if (ord[v] == -1)\r\n        {\r\n\
    \            low_link_sub(v, e.id, k, g, ord, low, bridge);\r\n        }\r\n \
    \       low[u] = std::min(low[u], low[v]);\r\n        if (ord[u] < low[v])\r\n\
    \        {\r\n            bridge.push_back(e);\r\n        }\r\n    }\r\n}\r\n\r\
    \ntemplate <typename G, typename T = int>\r\nstd::vector<edge<T>> low_link(G &g)\r\
    \n{\r\n    int n = g.size();\r\n    std::vector<int> ord(n, -1);\r\n    std::vector<int>\
    \ low(n, -1);\r\n    std::vector<edge<T>> bridge;\r\n    int k = 0;\r\n    for\
    \ (int u = 0; u < n; u++)\r\n    {\r\n        if (ord[u] == -1)\r\n        {\r\
    \n            low_link_sub(u, -1, k, g, ord, low, bridge);\r\n        }\r\n  \
    \  }\r\n    return bridge;\r\n}\r\n"
  code: "template <typename G, typename T = int>\r\nvoid low_link_sub(int u, int last_edge_id,\
    \ int &k, G &g, std::vector<int> &ord, std::vector<int> &low, std::vector<edge<T>>\
    \ &bridge)\r\n{\r\n    ord[u] = k++;\r\n    low[u] = ord[u];\r\n    for (edge<T>\
    \ e : g[u])\r\n    {\r\n        int v = e.to;\r\n        if (e.id == last_edge_id)\r\
    \n        {\r\n            continue;\r\n        }\r\n        if (ord[v] == -1)\r\
    \n        {\r\n            low_link_sub(v, e.id, k, g, ord, low, bridge);\r\n\
    \        }\r\n        low[u] = std::min(low[u], low[v]);\r\n        if (ord[u]\
    \ < low[v])\r\n        {\r\n            bridge.push_back(e);\r\n        }\r\n\
    \    }\r\n}\r\n\r\ntemplate <typename G, typename T = int>\r\nstd::vector<edge<T>>\
    \ low_link(G &g)\r\n{\r\n    int n = g.size();\r\n    std::vector<int> ord(n,\
    \ -1);\r\n    std::vector<int> low(n, -1);\r\n    std::vector<edge<T>> bridge;\r\
    \n    int k = 0;\r\n    for (int u = 0; u < n; u++)\r\n    {\r\n        if (ord[u]\
    \ == -1)\r\n        {\r\n            low_link_sub(u, -1, k, g, ord, low, bridge);\r\
    \n        }\r\n    }\r\n    return bridge;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/low_link.hpp
  requiredBy: []
  timestamp: '2022-12-10 07:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/other/low_link.hpp
layout: document
redirect_from:
- /library/lib/graph/other/low_link.hpp
- /library/lib/graph/other/low_link.hpp.html
title: lib/graph/other/low_link.hpp
---
