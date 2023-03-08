---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/matching/BipartiteMaximumMatching.hpp
    title: lib/graph/matching/BipartiteMaximumMatching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/aoj/GRL_7_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <queue>\n#line 1 \"lib/graph/matching/BipartiteMaximumMatching.hpp\"\
    \nstruct BipartiteMaximumMatching\r\n{\r\npublic:\r\n    BipartiteMaximumMatching()\
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
    \ match;\r\n};\r\n#line 7 \"test/aoj/GRL_7_A.test.cpp\"\nusing namespace std;\n\
    \nint main()\n{\n    int x, y, m;\n    cin >> x >> y >> m;\n    BipartiteMaximumMatching\
    \ g(x, y);\n    for(int i = 0; i < m; i++)\n    {\n        int u, v;\n       \
    \ cin >> u >> v;\n        g.add_directed_edge(u, v);\n    }\n    cout << g.get_maximum_matching()\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <queue>\n#include \"../../lib/graph/matching/BipartiteMaximumMatching.hpp\"\
    \nusing namespace std;\n\nint main()\n{\n    int x, y, m;\n    cin >> x >> y >>\
    \ m;\n    BipartiteMaximumMatching g(x, y);\n    for(int i = 0; i < m; i++)\n\
    \    {\n        int u, v;\n        cin >> u >> v;\n        g.add_directed_edge(u,\
    \ v);\n    }\n    cout << g.get_maximum_matching() << endl;\n}\n"
  dependsOn:
  - lib/graph/matching/BipartiteMaximumMatching.hpp
  isVerificationFile: true
  path: test/aoj/GRL_7_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_7_A.test.cpp
- /verify/test/aoj/GRL_7_A.test.cpp.html
title: test/aoj/GRL_7_A.test.cpp
---
