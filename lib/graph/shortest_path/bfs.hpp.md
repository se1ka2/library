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
  bundledCode: "#line 1 \"lib/graph/shortest_path/bfs.hpp\"\ntemplate <typename G>\r\
    \nstd::vector<int> bfs(G &g, int s)\r\n{\r\n    int n = g.size();\r\n    assert(s\
    \ >= 0 && s < n);\r\n    std::vector<int> d(n, -1);\r\n    std::queue<int> que;\r\
    \n    d[s] = 0;\r\n    que.push(s);\r\n    while (que.size())\r\n    {\r\n   \
    \     int u = que.front();\r\n        que.pop();\r\n        for (int v : g.g[u])\r\
    \n        {\r\n            if (d[v] == -1)\r\n            {\r\n              \
    \  d[v] = d[u] + 1;\r\n                que.push(v);\r\n            }\r\n     \
    \   }\r\n    }\r\n    return d;\r\n}\r\n"
  code: "template <typename G>\r\nstd::vector<int> bfs(G &g, int s)\r\n{\r\n    int\
    \ n = g.size();\r\n    assert(s >= 0 && s < n);\r\n    std::vector<int> d(n, -1);\r\
    \n    std::queue<int> que;\r\n    d[s] = 0;\r\n    que.push(s);\r\n    while (que.size())\r\
    \n    {\r\n        int u = que.front();\r\n        que.pop();\r\n        for (int\
    \ v : g.g[u])\r\n        {\r\n            if (d[v] == -1)\r\n            {\r\n\
    \                d[v] = d[u] + 1;\r\n                que.push(v);\r\n        \
    \    }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/shortest_path/bfs.hpp
  requiredBy: []
  timestamp: '2022-12-10 07:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/shortest_path/bfs.hpp
layout: document
redirect_from:
- /library/lib/graph/shortest_path/bfs.hpp
- /library/lib/graph/shortest_path/bfs.hpp.html
title: lib/graph/shortest_path/bfs.hpp
---
