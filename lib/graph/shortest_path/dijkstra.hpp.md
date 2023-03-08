---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    path: test/yukicoder/no_2095.test.cpp
    title: test/yukicoder/no_2095.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/shortest_path/dijkstra.hpp\"\ntemplate <typename\
    \ GRAPH>\r\nstd::vector<typename GRAPH::value_type> dijkstra(GRAPH &g, int s)\r\
    \n{\r\n    using T = typename GRAPH::value_type;\r\n    using P = std::pair<T,\
    \ int>;\r\n    int n = g.size();\r\n    assert(s >= 0 && s < n);\r\n    std::vector<T>\
    \ d(n, -1);\r\n    std::priority_queue<P, std::vector<P>, std::greater<P>> que;\r\
    \n    d[s] = 0;\r\n    que.push(P(0, s));\r\n    while (que.size())\r\n    {\r\
    \n        auto [dist, u] = que.top();\r\n        que.pop();\r\n        if (d[u]\
    \ < dist)\r\n        {\r\n            continue;\r\n        }\r\n        for (auto\
    \ e : g[u])\r\n        {\r\n            int v = e.to;\r\n            if (d[v]\
    \ == -1 || d[v] > d[u] + e.cost)\r\n            {\r\n                d[v] = d[u]\
    \ + e.cost;\r\n                que.push(P(d[v], v));\r\n            }\r\n    \
    \    }\r\n    }\r\n    return d;\r\n}\r\n"
  code: "template <typename GRAPH>\r\nstd::vector<typename GRAPH::value_type> dijkstra(GRAPH\
    \ &g, int s)\r\n{\r\n    using T = typename GRAPH::value_type;\r\n    using P\
    \ = std::pair<T, int>;\r\n    int n = g.size();\r\n    assert(s >= 0 && s < n);\r\
    \n    std::vector<T> d(n, -1);\r\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ que;\r\n    d[s] = 0;\r\n    que.push(P(0, s));\r\n    while (que.size())\r\n\
    \    {\r\n        auto [dist, u] = que.top();\r\n        que.pop();\r\n      \
    \  if (d[u] < dist)\r\n        {\r\n            continue;\r\n        }\r\n   \
    \     for (auto e : g[u])\r\n        {\r\n            int v = e.to;\r\n      \
    \      if (d[v] == -1 || d[v] > d[u] + e.cost)\r\n            {\r\n          \
    \      d[v] = d[u] + e.cost;\r\n                que.push(P(d[v], v));\r\n    \
    \        }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/shortest_path/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-03-08 14:49:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2095.test.cpp
  - test/aoj/GRL_1_A.test.cpp
  - test/aoj/ALDS1_12_C.test.cpp
  - test/aoj/ALDS1_12_B.test.cpp
documentation_of: lib/graph/shortest_path/dijkstra.hpp
layout: document
redirect_from:
- /library/lib/graph/shortest_path/dijkstra.hpp
- /library/lib/graph/shortest_path/dijkstra.hpp.html
title: lib/graph/shortest_path/dijkstra.hpp
---
