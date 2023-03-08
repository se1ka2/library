---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_4_B.test.cpp
    title: test/aoj/GRL_4_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/other/topological_sort.hpp\"\ntemplate <typename\
    \ GRAPH>\nstd::vector<int> topological_sort(GRAPH &g)\n{\n    int n = g.size();\n\
    \    std::vector<int> d(n);\n    for (int u = 0; u < n; u++)\n    {\n        for\
    \ (int v : g[u])\n        {\n            d[v]++;\n        }\n    }\n    std::queue<int>\
    \ que;\n    for (int u = 0; u < n; u++)\n    {\n        if (!d[u])\n        {\n\
    \            que.push(u);\n        }\n    }\n    std::vector<int> res;\n    while\
    \ (que.size())\n    {\n        int u = que.front();\n        res.push_back(u);\n\
    \        que.pop();\n        for (int v : g[u])\n        {\n            d[v]--;\n\
    \            if (!d[v])\n            {\n                que.push(v);\n       \
    \     }\n        }\n    }\n    assert((int)res.size() == n);\n    return res;\n\
    }\n"
  code: "template <typename GRAPH>\nstd::vector<int> topological_sort(GRAPH &g)\n\
    {\n    int n = g.size();\n    std::vector<int> d(n);\n    for (int u = 0; u <\
    \ n; u++)\n    {\n        for (int v : g[u])\n        {\n            d[v]++;\n\
    \        }\n    }\n    std::queue<int> que;\n    for (int u = 0; u < n; u++)\n\
    \    {\n        if (!d[u])\n        {\n            que.push(u);\n        }\n \
    \   }\n    std::vector<int> res;\n    while (que.size())\n    {\n        int u\
    \ = que.front();\n        res.push_back(u);\n        que.pop();\n        for (int\
    \ v : g[u])\n        {\n            d[v]--;\n            if (!d[v])\n        \
    \    {\n                que.push(v);\n            }\n        }\n    }\n    assert((int)res.size()\
    \ == n);\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/topological_sort.hpp
  requiredBy: []
  timestamp: '2023-03-08 22:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_4_B.test.cpp
documentation_of: lib/graph/other/topological_sort.hpp
layout: document
redirect_from:
- /library/lib/graph/other/topological_sort.hpp
- /library/lib/graph/other/topological_sort.hpp.html
title: lib/graph/other/topological_sort.hpp
---
