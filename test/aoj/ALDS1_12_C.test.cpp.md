---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/Graph.hpp
    title: lib/graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/shortest_path/dijkstra.hpp
    title: lib/graph/shortest_path/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_12_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <queue>\n#line 1 \"lib/graph/Graph.hpp\"\
    \ntemplate <typename T = int>\r\nstruct Graph\r\n{\r\npublic:\r\n    using value_type\
    \ = T;\r\n\r\n    struct Edge\r\n    {\r\n        int from, to;\r\n        T cost;\r\
    \n        int id;\r\n\r\n        operator int() const\r\n        {\r\n       \
    \     return to;\r\n        }\r\n    };\r\n\r\n    Graph() {}\r\n\r\n    Graph(int\
    \ n) : n(n), m(0), g(n) {}\r\n\r\n    void add_directed_edge(int from, int to,\
    \ T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\n        assert(0\
    \ <= to && to < n);\r\n        g[from].push_back((Edge){from, to, cost, m++});\r\
    \n    }\r\n\r\n    void add_undirected_edge(int from, int to, T cost = 1)\r\n\
    \    {\r\n        assert(0 <= from && from < n);\r\n        assert(0 <= to &&\
    \ to < n);\r\n        g[from].push_back((Edge){from, to, cost, m});\r\n      \
    \  g[to].push_back((Edge){to, from, cost, m++});\r\n    }\r\n\r\n    int size()\r\
    \n    {\r\n        return n;\r\n    }\r\n\r\n    int edge_size()\r\n    {\r\n\
    \        return m;\r\n    }\r\n\r\n    inline const std::vector<Edge> &operator[](const\
    \ int &u) const\r\n    {\r\n        return g[u];\r\n    }\r\n\r\n    inline std::vector<Edge>\
    \ &operator[](const int &u)\r\n    {\r\n        return g[u];\r\n    }\r\n\r\n\
    private:\r\n    int n, m;\r\n    std::vector<std::vector<Edge>> g;\r\n};\r\n#line\
    \ 1 \"lib/graph/shortest_path/dijkstra.hpp\"\ntemplate <typename GRAPH>\r\nstd::vector<typename\
    \ GRAPH::value_type> dijkstra(GRAPH &g, int s)\r\n{\r\n    using T = typename\
    \ GRAPH::value_type;\r\n    using P = std::pair<T, int>;\r\n    int n = g.size();\r\
    \n    assert(s >= 0 && s < n);\r\n    std::vector<T> d(n, -1);\r\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> que;\r\n    d[s] = 0;\r\n    que.push(P(0,\
    \ s));\r\n    while (que.size())\r\n    {\r\n        auto [dist, u] = que.top();\r\
    \n        que.pop();\r\n        if (d[u] < dist)\r\n        {\r\n            continue;\r\
    \n        }\r\n        for (auto e : g[u])\r\n        {\r\n            int v =\
    \ e.to;\r\n            if (d[v] == -1 || d[v] > d[u] + e.cost)\r\n           \
    \ {\r\n                d[v] = d[u] + e.cost;\r\n                que.push(P(d[v],\
    \ v));\r\n            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n#line 8\
    \ \"test/aoj/ALDS1_12_C.test.cpp\"\nusing namespace std;\n\nint main()\n{\n  \
    \  int n;\n    cin >> n;\n    Graph<int> g(n);\n    for(int i = 0; i < n; i++)\n\
    \    {\n        int u, k;\n        cin >> u >> k;\n        for(int j = 0; j <\
    \ k; j++)\n        {\n            int v, c;\n            cin >> v >> c;\n    \
    \        g.add_directed_edge(u, v, c);\n        }\n    }\n    vector<int> d =\
    \ dijkstra(g, 0);\n    for(int u = 0; u < n; u++)\n    {\n        cout << u <<\
    \ \" \" << d[u] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <queue>\n#include \"../../lib/graph/Graph.hpp\"\
    \n#include \"../../lib/graph/shortest_path/dijkstra.hpp\"\nusing namespace std;\n\
    \nint main()\n{\n    int n;\n    cin >> n;\n    Graph<int> g(n);\n    for(int\
    \ i = 0; i < n; i++)\n    {\n        int u, k;\n        cin >> u >> k;\n     \
    \   for(int j = 0; j < k; j++)\n        {\n            int v, c;\n           \
    \ cin >> v >> c;\n            g.add_directed_edge(u, v, c);\n        }\n    }\n\
    \    vector<int> d = dijkstra(g, 0);\n    for(int u = 0; u < n; u++)\n    {\n\
    \        cout << u << \" \" << d[u] << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/Graph.hpp
  - lib/graph/shortest_path/dijkstra.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_12_C.test.cpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_12_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_12_C.test.cpp
- /verify/test/aoj/ALDS1_12_C.test.cpp.html
title: test/aoj/ALDS1_12_C.test.cpp
---
