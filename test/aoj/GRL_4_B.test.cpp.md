---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/Graph.hpp
    title: lib/graph/Graph.hpp
  - icon: ':x:'
    path: lib/graph/other/topological_sort.hpp
    title: lib/graph/other/topological_sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"test/aoj/GRL_4_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
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
    \ 1 \"lib/graph/other/topological_sort.hpp\"\ntemplate <typename GRAPH>\nstd::vector<int>\
    \ topological_sort(GRAPH &g)\n{\n    int n = g.size();\n    std::vector<int> d(n);\n\
    \    for (int u = 0; u < n; u++)\n    {\n        for (int v : g[u])\n        {\n\
    \            d[v]++;\n        }\n    }\n    std::queue<int> que;\n    for (int\
    \ u = 0; u < n; u++)\n    {\n        if (!d[u])\n        {\n            que.push(u);\n\
    \        }\n    }\n    std::vector<int> res;\n    while (que.size())\n    {\n\
    \        int u = que.front();\n        res.push_back(u);\n        que.pop();\n\
    \        for (int v : g[u])\n        {\n            d[v]--;\n            if (!d[v])\n\
    \            {\n                que.push(v);\n            }\n        }\n    }\n\
    \    assert((int)res.size() == n);\n    return res;\n}\n#line 8 \"test/aoj/GRL_4_B.test.cpp\"\
    \nusing namespace std;\n\nint main()\n{\n    int n, m;\n    cin >> n >> m;\n \
    \   Graph<int> g(n);\n    for(int i = 0; i < m; i++)\n    {\n        int s, t;\n\
    \        cin >> s >> t;\n        g.add_directed_edge(s, t);\n    }\n    vector<int>\
    \ p = topological_sort(g);\n    for(int u : p)\n    {\n        cout << u << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <queue>\n#include \"../../lib/graph/Graph.hpp\"\
    \n#include \"../../lib/graph/other/topological_sort.hpp\"\nusing namespace std;\n\
    \nint main()\n{\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n   \
    \ for(int i = 0; i < m; i++)\n    {\n        int s, t;\n        cin >> s >> t;\n\
    \        g.add_directed_edge(s, t);\n    }\n    vector<int> p = topological_sort(g);\n\
    \    for(int u : p)\n    {\n        cout << u << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/Graph.hpp
  - lib/graph/other/topological_sort.hpp
  isVerificationFile: true
  path: test/aoj/GRL_4_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 22:53:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_4_B.test.cpp
- /verify/test/aoj/GRL_4_B.test.cpp.html
title: test/aoj/GRL_4_B.test.cpp
---
