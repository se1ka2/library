---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/matching/BipartiteMaximumMatching.hpp\"\nstruct\
    \ BipartiteMaximumMatching\r\n{\r\npublic:\r\n    BipartiteMaximumMatching() {}\r\
    \n\r\n    BipartiteMaximumMatching(int p, int q) : p(p), q(q), g(p), match(q,\
    \ -1) {}\r\n\r\n    void add_directed_edge(int a, int b)\r\n    {\r\n        assert(0\
    \ <= a && a < p);\r\n        assert(0 <= b && b < q);\r\n        g[a].push_back(b);\r\
    \n    }\r\n\r\n    int get_maximum_matching()\r\n    {\r\n        std::vector<bool>\
    \ covered(p);\r\n        std::vector<int> dist(p);\r\n        std::vector<bool>\
    \ used(p);\r\n        int max_length;\r\n        int res = 0;\r\n\r\n        auto\
    \ bfs = [&]()\r\n        {\r\n            std::queue<int> que;\r\n           \
    \ for (int u = 0; u < p; u++)\r\n            {\r\n                if (!covered[u])\r\
    \n                {\r\n                    que.push(u);\r\n                  \
    \  dist[u] = 0;\r\n                }\r\n                else\r\n             \
    \   {\r\n                    dist[u] = -1;\r\n                }\r\n          \
    \  }\r\n            while (que.size())\r\n            {\r\n                int\
    \ u = que.front();\r\n                que.pop();\r\n                for (int v\
    \ : g[u])\r\n                {\r\n                    if (match[v] == -1)\r\n\
    \                    {\r\n                        max_length = dist[u];\r\n  \
    \                      return;\r\n                    }\r\n                  \
    \  if (dist[match[v]] == -1)\r\n                    {\r\n                    \
    \    dist[match[v]] = dist[u] + 1;\r\n                        que.push(match[v]);\r\
    \n                    }\r\n                }\r\n            }\r\n        };\r\n\
    \r\n        auto dfs = [&](auto self, int u) -> bool\r\n        {\r\n        \
    \    used[u] = true;\r\n            for (int v : g[u])\r\n            {\r\n  \
    \              int w = match[v];\r\n                if (w == -1 || (!used[w] &&\
    \ dist[w] == dist[u] + 1 && dist[w] <= max_length && self(self, w)))\r\n     \
    \           {\r\n                    match[v] = u;\r\n                    covered[u]\
    \ = true;\r\n                    return true;\r\n                }\r\n       \
    \     }\r\n            return false;\r\n        };\r\n\r\n        while (true)\r\
    \n        {\r\n            max_length = -1;\r\n            bfs();\r\n        \
    \    if (max_length == -1)\r\n            {\r\n                return res;\r\n\
    \            }\r\n            used.assign(p, false);\r\n            for (int u\
    \ = 0; u < p; u++)\r\n            {\r\n                res += (!covered[u] &&\
    \ dfs(dfs, u));\r\n            }\r\n        }\r\n    }\r\n\r\n    std::vector<std::pair<int,\
    \ int>> get_matching_edges()\r\n    {\r\n        std::vector<std::pair<int, int>>\
    \ res;\r\n        for (int v = 0; v < q; v++)\r\n        {\r\n            if (match[v]\
    \ >= 0)\r\n            {\r\n                res.push_back(std::pair<int, int>(match[v],\
    \ v));\r\n            }\r\n        }\r\n        return res;\r\n    }\r\n\r\nprivate:\r\
    \n    int p, q;\r\n    std::vector<std::vector<int>> g;\r\n    std::vector<int>\
    \ match;\r\n};\r\n"
  code: "struct BipartiteMaximumMatching\r\n{\r\npublic:\r\n    BipartiteMaximumMatching()\
    \ {}\r\n\r\n    BipartiteMaximumMatching(int p, int q) : p(p), q(q), g(p), match(q,\
    \ -1) {}\r\n\r\n    void add_directed_edge(int a, int b)\r\n    {\r\n        assert(0\
    \ <= a && a < p);\r\n        assert(0 <= b && b < q);\r\n        g[a].push_back(b);\r\
    \n    }\r\n\r\n    int get_maximum_matching()\r\n    {\r\n        std::vector<bool>\
    \ covered(p);\r\n        std::vector<int> dist(p);\r\n        std::vector<bool>\
    \ used(p);\r\n        int max_length;\r\n        int res = 0;\r\n\r\n        auto\
    \ bfs = [&]()\r\n        {\r\n            std::queue<int> que;\r\n           \
    \ for (int u = 0; u < p; u++)\r\n            {\r\n                if (!covered[u])\r\
    \n                {\r\n                    que.push(u);\r\n                  \
    \  dist[u] = 0;\r\n                }\r\n                else\r\n             \
    \   {\r\n                    dist[u] = -1;\r\n                }\r\n          \
    \  }\r\n            while (que.size())\r\n            {\r\n                int\
    \ u = que.front();\r\n                que.pop();\r\n                for (int v\
    \ : g[u])\r\n                {\r\n                    if (match[v] == -1)\r\n\
    \                    {\r\n                        max_length = dist[u];\r\n  \
    \                      return;\r\n                    }\r\n                  \
    \  if (dist[match[v]] == -1)\r\n                    {\r\n                    \
    \    dist[match[v]] = dist[u] + 1;\r\n                        que.push(match[v]);\r\
    \n                    }\r\n                }\r\n            }\r\n        };\r\n\
    \r\n        auto dfs = [&](auto self, int u) -> bool\r\n        {\r\n        \
    \    used[u] = true;\r\n            for (int v : g[u])\r\n            {\r\n  \
    \              int w = match[v];\r\n                if (w == -1 || (!used[w] &&\
    \ dist[w] == dist[u] + 1 && dist[w] <= max_length && self(self, w)))\r\n     \
    \           {\r\n                    match[v] = u;\r\n                    covered[u]\
    \ = true;\r\n                    return true;\r\n                }\r\n       \
    \     }\r\n            return false;\r\n        };\r\n\r\n        while (true)\r\
    \n        {\r\n            max_length = -1;\r\n            bfs();\r\n        \
    \    if (max_length == -1)\r\n            {\r\n                return res;\r\n\
    \            }\r\n            used.assign(p, false);\r\n            for (int u\
    \ = 0; u < p; u++)\r\n            {\r\n                res += (!covered[u] &&\
    \ dfs(dfs, u));\r\n            }\r\n        }\r\n    }\r\n\r\n    std::vector<std::pair<int,\
    \ int>> get_matching_edges()\r\n    {\r\n        std::vector<std::pair<int, int>>\
    \ res;\r\n        for (int v = 0; v < q; v++)\r\n        {\r\n            if (match[v]\
    \ >= 0)\r\n            {\r\n                res.push_back(std::pair<int, int>(match[v],\
    \ v));\r\n            }\r\n        }\r\n        return res;\r\n    }\r\n\r\nprivate:\r\
    \n    int p, q;\r\n    std::vector<std::vector<int>> g;\r\n    std::vector<int>\
    \ match;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/matching/BipartiteMaximumMatching.hpp
  requiredBy: []
  timestamp: '2023-03-07 23:26:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_7_A.test.cpp
documentation_of: lib/graph/matching/BipartiteMaximumMatching.hpp
layout: document
redirect_from:
- /library/lib/graph/matching/BipartiteMaximumMatching.hpp
- /library/lib/graph/matching/BipartiteMaximumMatching.hpp.html
title: lib/graph/matching/BipartiteMaximumMatching.hpp
---
