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
    \ G, typename T = int>\r\nvoid eulerian_trail_sub(int u, int last_edge_id, bool\
    \ return_edge_id, G &g, std::vector<int> &trail, std::vector<bool> &used)\r\n\
    {\r\n    for (edge<T> e : g[u])\r\n    {\r\n        if (used[e.id])\r\n      \
    \  {\r\n            continue;\r\n        }\r\n        used[e.id] = true;\r\n \
    \       eulerian_trail_sub(e.to, e.id, return_edge_id, g, trail, used);\r\n  \
    \  }\r\n    if (!return_edge_id)\r\n    {\r\n        trail.push_back(u);\r\n \
    \   }\r\n    else if (last_edge_id != -1)\r\n    {\r\n        trail.push_back(last_edge_id);\r\
    \n    }\r\n}\r\n\r\ntemplate <typename G>\r\nstd::vector<int> eulerian_trail(G\
    \ &g, int r = 0, bool return_edge_id = true)\r\n{\r\n    int n = g.size(), m =\
    \ g.edge_size();\r\n    bool even_degree = true;\r\n    for (int u = 0; u < n;\
    \ u++)\r\n    {\r\n        even_degree &= !((int)g[u].size() % 2);\r\n    }\r\n\
    \    assert(even_degree);\r\n    std::vector<int> trail;\r\n    std::vector<bool>\
    \ used(m);\r\n    eulerian_trail_sub(r, -1, return_edge_id, g, trail, used);\r\
    \n    bool cover_all_edge = true;\r\n    for (int i = 0; i < m; i++)\r\n    {\r\
    \n        cover_all_edge &= used[i];\r\n    }\r\n    assert(cover_all_edge);\r\
    \n    return trail;\r\n}\r\n"
  code: "template <typename G, typename T = int>\r\nvoid eulerian_trail_sub(int u,\
    \ int last_edge_id, bool return_edge_id, G &g, std::vector<int> &trail, std::vector<bool>\
    \ &used)\r\n{\r\n    for (edge<T> e : g[u])\r\n    {\r\n        if (used[e.id])\r\
    \n        {\r\n            continue;\r\n        }\r\n        used[e.id] = true;\r\
    \n        eulerian_trail_sub(e.to, e.id, return_edge_id, g, trail, used);\r\n\
    \    }\r\n    if (!return_edge_id)\r\n    {\r\n        trail.push_back(u);\r\n\
    \    }\r\n    else if (last_edge_id != -1)\r\n    {\r\n        trail.push_back(last_edge_id);\r\
    \n    }\r\n}\r\n\r\ntemplate <typename G>\r\nstd::vector<int> eulerian_trail(G\
    \ &g, int r = 0, bool return_edge_id = true)\r\n{\r\n    int n = g.size(), m =\
    \ g.edge_size();\r\n    bool even_degree = true;\r\n    for (int u = 0; u < n;\
    \ u++)\r\n    {\r\n        even_degree &= !((int)g[u].size() % 2);\r\n    }\r\n\
    \    assert(even_degree);\r\n    std::vector<int> trail;\r\n    std::vector<bool>\
    \ used(m);\r\n    eulerian_trail_sub(r, -1, return_edge_id, g, trail, used);\r\
    \n    bool cover_all_edge = true;\r\n    for (int i = 0; i < m; i++)\r\n    {\r\
    \n        cover_all_edge &= used[i];\r\n    }\r\n    assert(cover_all_edge);\r\
    \n    return trail;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/eularian_trail.hpp
  requiredBy: []
  timestamp: '2022-12-10 07:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/other/eularian_trail.hpp
layout: document
redirect_from:
- /library/lib/graph/other/eularian_trail.hpp
- /library/lib/graph/other/eularian_trail.hpp.html
title: lib/graph/other/eularian_trail.hpp
---
