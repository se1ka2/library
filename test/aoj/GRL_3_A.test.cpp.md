---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/Graph.hpp
    title: lib/graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/other/LowLink.hpp
    title: lib/graph/other/LowLink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/aoj/GRL_3_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <cassert>\n#include <vector>\n\
    #line 1 \"lib/graph/Graph.hpp\"\ntemplate <typename T = int>\r\nstruct Graph\r\
    \n{\r\npublic:\r\n    using value_type = T;\r\n\r\n    struct Edge\r\n    {\r\n\
    \        int from, to;\r\n        T cost;\r\n        int id;\r\n\r\n        operator\
    \ int() const\r\n        {\r\n            return to;\r\n        }\r\n    };\r\n\
    \r\n    Graph() {}\r\n\r\n    Graph(int n) : n(n), m(0), g(n) {}\r\n\r\n    void\
    \ add_directed_edge(int from, int to, T cost = 1)\r\n    {\r\n        assert(0\
    \ <= from && from < n);\r\n        assert(0 <= to && to < n);\r\n        g[from].push_back((Edge){from,\
    \ to, cost, m++});\r\n    }\r\n\r\n    void add_undirected_edge(int from, int\
    \ to, T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\n     \
    \   assert(0 <= to && to < n);\r\n        g[from].push_back((Edge){from, to, cost,\
    \ m});\r\n        g[to].push_back((Edge){to, from, cost, m++});\r\n    }\r\n\r\
    \n    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    int edge_size()\r\
    \n    {\r\n        return m;\r\n    }\r\n\r\n    inline const std::vector<Edge>\
    \ &operator[](const int &u) const\r\n    {\r\n        return g[u];\r\n    }\r\n\
    \r\n    inline std::vector<Edge> &operator[](const int &u)\r\n    {\r\n      \
    \  return g[u];\r\n    }\r\n\r\nprivate:\r\n    int n, m;\r\n    std::vector<std::vector<Edge>>\
    \ g;\r\n};\r\n#line 1 \"lib/graph/other/LowLink.hpp\"\ntemplate <typename GRAPH>\r\
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
    \    int n;\r\n    const GRAPH &g;\r\n};\r\n#line 9 \"test/aoj/GRL_3_A.test.cpp\"\
    \nusing namespace std;\ntypedef pair<int, int> P;\n\nint main()\n{\n    int n,\
    \ m;\n    cin >> n >> m;\n    Graph<int> g(n);\n    for (int i = 0; i < m; i++)\n\
    \    {\n        int s, t;\n        cin >> s >> t;\n        g.add_undirected_edge(s,\
    \ t);\n    }\n    LowLink<Graph<int>> lowlink(g);\n    vector<int> ans;\n    for\
    \ (int u : lowlink.articulation)\n    {\n        ans.push_back(u);\n    }\n  \
    \  sort(ans.begin(), ans.end());\n    for (int u : ans)\n    {\n        cout <<\
    \ u << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <cassert>\n#include <vector>\n\
    #include \"../../lib/graph/Graph.hpp\"\n#include \"../../lib/graph/other/LowLink.hpp\"\
    \nusing namespace std;\ntypedef pair<int, int> P;\n\nint main()\n{\n    int n,\
    \ m;\n    cin >> n >> m;\n    Graph<int> g(n);\n    for (int i = 0; i < m; i++)\n\
    \    {\n        int s, t;\n        cin >> s >> t;\n        g.add_undirected_edge(s,\
    \ t);\n    }\n    LowLink<Graph<int>> lowlink(g);\n    vector<int> ans;\n    for\
    \ (int u : lowlink.articulation)\n    {\n        ans.push_back(u);\n    }\n  \
    \  sort(ans.begin(), ans.end());\n    for (int u : ans)\n    {\n        cout <<\
    \ u << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/Graph.hpp
  - lib/graph/other/LowLink.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 22:53:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_A.test.cpp
- /verify/test/aoj/GRL_3_A.test.cpp.html
title: test/aoj/GRL_3_A.test.cpp
---
