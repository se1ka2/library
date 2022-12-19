---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/graph.hpp
    title: lib/graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/other/low_link.hpp
    title: lib/graph/other/low_link.hpp
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
    using namespace std;\ntypedef pair<int, int> P;\n\n#line 1 \"lib/graph/graph.hpp\"\
    \ntemplate <typename T = int>\r\nstruct edge\r\n{\r\n    int from, to;\r\n   \
    \ T cost;\r\n    int id;\r\n\r\n    operator int() const\r\n    {\r\n        return\
    \ to;\r\n    }\r\n};\r\n\r\ntemplate <typename T = int>\r\nstruct graph\r\n{\r\
    \npublic:\r\n    graph() {}\r\n\r\n    graph(int n) : n(n), m(0)\r\n    {\r\n\
    \        g.resize(n);\r\n    }\r\n\r\n    void add_directed_edge(int from, int\
    \ to, T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\n     \
    \   assert(0 <= to && to < n);\r\n        g[from].push_back((edge<T>){from, to,\
    \ cost, m++});\r\n    }\r\n\r\n    void add_undirected_edge(int from, int to,\
    \ T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\n        assert(0\
    \ <= to && to < n);\r\n        g[from].push_back((edge<T>){from, to, cost, m});\r\
    \n        g[to].push_back((edge<T>){to, from, cost, m++});\r\n    }\r\n\r\n  \
    \  int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    int edge_size()\r\
    \n    {\r\n        return m;\r\n    }\r\n\r\n    inline const std::vector<edge<T>>\
    \ &operator[](const int &u) const\r\n    {\r\n        return g[u];\r\n    }\r\n\
    \r\n    inline std::vector<edge<T>> &operator[](const int &u)\r\n    {\r\n   \
    \     return g[u];\r\n    }\r\n\r\nprivate:\r\n    int n, m;\r\n    std::vector<std::vector<edge<T>>>\
    \ g;\r\n};\r\n#line 1 \"lib/graph/other/low_link.hpp\"\ntemplate <typename G,\
    \ typename T = int>\r\nstruct low_link\r\n{\r\npublic:\r\n    std::vector<int>\
    \ articulation;\r\n    std::vector<edge<T>> bridge;\r\n\r\n    low_link() {}\r\
    \n\r\n    low_link(G &g) : n(g.size()), g(g), ord(g.size(), -1), low(g.size(),\
    \ -1)\r\n    {\r\n        int k = 0;\r\n        for (int u = 0; u < n; u++)\r\n\
    \        {\r\n            if (ord[u] == -1)\r\n            {\r\n             \
    \   dfs(u, -1, k);\r\n            }\r\n        }\r\n    }\r\n\r\nprivate:\r\n\
    \    int n;\r\n    const G &g;\r\n    std::vector<int> ord;\r\n    std::vector<int>\
    \ low;\r\n\r\n    void dfs(int u, int last_edge_id, int &k)\r\n    {\r\n     \
    \   low[u] = ord[u] = k++;\r\n        int c = 0;\r\n        bool is_artification\
    \ = false;\r\n        for (edge<T> e : g[u])\r\n        {\r\n            int v\
    \ = e.to;\r\n            if (e.id == last_edge_id)\r\n            {\r\n      \
    \          continue;\r\n            }\r\n            if (ord[v] == -1)\r\n   \
    \         {\r\n                c++;\r\n                dfs(v, e.id, k);\r\n  \
    \              if (last_edge_id != -1 && ord[u] <= low[v])\r\n               \
    \ {\r\n                    is_artification = true;\r\n                }\r\n  \
    \              if (ord[u] < low[v])\r\n                {\r\n                 \
    \   bridge.push_back(e);\r\n                }\r\n                low[u] = std::min(low[u],\
    \ low[v]);\r\n            }\r\n            low[u] = std::min(low[u], ord[v]);\r\
    \n        }\r\n        is_artification |= (last_edge_id == -1 && c >= 2);\r\n\
    \        if (is_artification)\r\n        {\r\n            articulation.push_back(u);\r\
    \n        }\r\n    }\r\n};\r\n#line 12 \"test/aoj/GRL_3_A.test.cpp\"\n\nint main()\n\
    {\n    int n, m;\n    cin >> n >> m;\n    graph g(n);\n    for (int i = 0; i <\
    \ m; i++)\n    {\n        int s, t;\n        cin >> s >> t;\n        g.add_undirected_edge(s,\
    \ t);\n    }\n    low_link lowlink(g);\n    vector<int> ans;\n    for (int u :\
    \ lowlink.articulation)\n    {\n        ans.push_back(u);\n    }\n    sort(ans.begin(),\
    \ ans.end());\n    for (int u : ans)\n    {\n        cout << u << endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <cassert>\n#include <vector>\n\
    using namespace std;\ntypedef pair<int, int> P;\n\n#include \"../../lib/graph/graph.hpp\"\
    \n#include \"../../lib/graph/other/low_link.hpp\"\n\nint main()\n{\n    int n,\
    \ m;\n    cin >> n >> m;\n    graph g(n);\n    for (int i = 0; i < m; i++)\n \
    \   {\n        int s, t;\n        cin >> s >> t;\n        g.add_undirected_edge(s,\
    \ t);\n    }\n    low_link lowlink(g);\n    vector<int> ans;\n    for (int u :\
    \ lowlink.articulation)\n    {\n        ans.push_back(u);\n    }\n    sort(ans.begin(),\
    \ ans.end());\n    for (int u : ans)\n    {\n        cout << u << endl;\n    }\n\
    }\n"
  dependsOn:
  - lib/graph/graph.hpp
  - lib/graph/other/low_link.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-20 02:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_A.test.cpp
- /verify/test/aoj/GRL_3_A.test.cpp.html
title: test/aoj/GRL_3_A.test.cpp
---
