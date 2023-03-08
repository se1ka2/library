---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/Graph.hpp
    title: lib/graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/other/SCC.hpp
    title: lib/graph/other/SCC.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"test/aoj/GRL_3_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
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
    \ g;\r\n};\r\n#line 1 \"lib/graph/other/SCC.hpp\"\ntemplate <typename GRAPH>\r\
    \nstruct SCC\r\n{\r\npublic:\r\n    std::vector<std::vector<int>> group;\r\n\r\
    \n    SCC() {}\r\n\r\n    SCC(GRAPH &g) : n(g.size()), k(0), g(g), cmp(n)\r\n\
    \    {\r\n        std::vector<std::vector<int>> rg(n);\r\n        std::vector<bool>\
    \ used(n);\r\n        std::vector<int> vs;\r\n\r\n        auto dfs = [&](auto\
    \ self, int u) -> void\r\n        {\r\n            used[u] = true;\r\n       \
    \     for (int v : g[u])\r\n            {\r\n                if (!used[v])\r\n\
    \                {\r\n                    self(self, v);\r\n                }\r\
    \n            }\r\n            vs.push_back(u);\r\n        };\r\n\r\n        auto\
    \ rdfs = [&](auto self, int u) -> void\r\n        {\r\n            used[u] = true;\r\
    \n            cmp[u] = k;\r\n            for (int v : rg[u])\r\n            {\r\
    \n                if (!used[v])\r\n                {\r\n                    self(self,\
    \ v);\r\n                }\r\n            }\r\n        };\r\n\r\n        for (int\
    \ u = 0; u < n; u++)\r\n        {\r\n            for (int v : g[u])\r\n      \
    \      {\r\n                rg[v].push_back(u);\r\n            }\r\n        }\r\
    \n        for (int u = 0; u < n; u++)\r\n        {\r\n            if (!used[u])\r\
    \n            {\r\n                dfs(dfs, u);\r\n            }\r\n        }\r\
    \n        fill(used.begin(), used.end(), false);\r\n        for (int i = n - 1;\
    \ i >= 0; i--)\r\n        {\r\n            if (!used[vs[i]])\r\n            {\r\
    \n                rdfs(rdfs, vs[i]);\r\n                k++;\r\n            }\r\
    \n        }\r\n        group.resize(k);\r\n        for (int u = 0; u < n; u++)\r\
    \n        {\r\n            group[cmp[u]].push_back(u);\r\n        }\r\n    }\r\
    \n\r\n    GRAPH get_dag()\r\n    {\r\n        std::vector<bool> b(k);\r\n    \
    \    GRAPH dag(k);\r\n        for (int x = 0; x < k; x++)\r\n        {\r\n   \
    \         for (int u : group[x])\r\n            {\r\n                for (int\
    \ v : g[u])\r\n                {\r\n                    int y = cmp[v];\r\n  \
    \                  if (!b[y])\r\n                    {\r\n                   \
    \     dag.add_directed_edge(x, y);\r\n                        b[y] = true;\r\n\
    \                    }\r\n                }\r\n            }\r\n            for\
    \ (int u : group[x])\r\n            {\r\n                for (int v : g[u])\r\n\
    \                {\r\n                    b[cmp[v]] = false;\r\n             \
    \   }\r\n            }\r\n        }\r\n        return dag;\r\n    }\r\n\r\n  \
    \  int number_of_component()\r\n    {\r\n        return k;\r\n    }\r\n\r\n  \
    \  const int operator[](const int &u) const\r\n    {\r\n        return cmp[u];\r\
    \n    }\r\n\r\nprivate:\r\n    int n;\r\n    int k;\r\n    const GRAPH &g;\r\n\
    \    std::vector<int> cmp;\r\n};\r\n#line 9 \"test/aoj/GRL_3_C.test.cpp\"\nusing\
    \ namespace std;\n\nint main()\n{\n    int n, m;\n    cin >> n >> m;\n    Graph<int>\
    \ g(n);\n    for (int i = 0; i < m; i++)\n    {\n        int a, b;\n        cin\
    \ >> a >> b;\n        g.add_directed_edge(a, b);\n    }\n    SCC<Graph<int>> scc(g);\n\
    \    scc.number_of_component();\n    int q;\n    cin >> q;\n    while(q--)\n \
    \   {\n        int u, v;\n        cin >> u >> v;\n        cout << (bool)(scc[u]\
    \ == scc[v]) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <cassert>\n#include <vector>\n\
    #include \"../../lib/graph/Graph.hpp\"\n#include \"../../lib/graph/other/SCC.hpp\"\
    \nusing namespace std;\n\nint main()\n{\n    int n, m;\n    cin >> n >> m;\n \
    \   Graph<int> g(n);\n    for (int i = 0; i < m; i++)\n    {\n        int a, b;\n\
    \        cin >> a >> b;\n        g.add_directed_edge(a, b);\n    }\n    SCC<Graph<int>>\
    \ scc(g);\n    scc.number_of_component();\n    int q;\n    cin >> q;\n    while(q--)\n\
    \    {\n        int u, v;\n        cin >> u >> v;\n        cout << (bool)(scc[u]\
    \ == scc[v]) << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/Graph.hpp
  - lib/graph/other/SCC.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 22:53:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_C.test.cpp
- /verify/test/aoj/GRL_3_C.test.cpp.html
title: test/aoj/GRL_3_C.test.cpp
---
