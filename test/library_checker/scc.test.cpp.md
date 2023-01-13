---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/graph.hpp
    title: lib/graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/other/scc.hpp
    title: lib/graph/other/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library_checker/scc.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/scc\"\n\n#include <algorithm>\n#include <iostream>\n\
    #include <cassert>\n#include <vector>\n#line 1 \"lib/graph/graph.hpp\"\ntemplate\
    \ <typename T = int>\r\nstruct edge\r\n{\r\n    int from, to;\r\n    T cost;\r\
    \n    int id;\r\n\r\n    operator int() const\r\n    {\r\n        return to;\r\
    \n    }\r\n};\r\n\r\ntemplate <typename T = int>\r\nstruct graph\r\n{\r\npublic:\r\
    \n    graph() {}\r\n\r\n    graph(int n) : n(n), m(0)\r\n    {\r\n        g.resize(n);\r\
    \n    }\r\n\r\n    void add_directed_edge(int from, int to, T cost = 1)\r\n  \
    \  {\r\n        assert(0 <= from && from < n);\r\n        assert(0 <= to && to\
    \ < n);\r\n        g[from].push_back((edge<T>){from, to, cost, m++});\r\n    }\r\
    \n\r\n    void add_undirected_edge(int from, int to, T cost = 1)\r\n    {\r\n\
    \        assert(0 <= from && from < n);\r\n        assert(0 <= to && to < n);\r\
    \n        g[from].push_back((edge<T>){from, to, cost, m});\r\n        g[to].push_back((edge<T>){to,\
    \ from, cost, m++});\r\n    }\r\n\r\n    int size()\r\n    {\r\n        return\
    \ n;\r\n    }\r\n\r\n    int edge_size()\r\n    {\r\n        return m;\r\n   \
    \ }\r\n\r\n    inline const std::vector<edge<T>> &operator[](const int &u) const\r\
    \n    {\r\n        return g[u];\r\n    }\r\n\r\n    inline std::vector<edge<T>>\
    \ &operator[](const int &u)\r\n    {\r\n        return g[u];\r\n    }\r\n\r\n\
    private:\r\n    int n, m;\r\n    std::vector<std::vector<edge<T>>> g;\r\n};\r\n\
    #line 1 \"lib/graph/other/scc.hpp\"\ntemplate <typename G, typename T = int>\r\
    \nstruct scc_structure\r\n{\r\npublic:\r\n    std::vector<std::vector<int>> group;\r\
    \n\r\n    scc_structure() {}\r\n\r\n    scc_structure(G &g) : n(g.size()), k(0),\
    \ g(g), rg(g.size()), cmp(n), used(n)\r\n    {\r\n        for (int u = 0; u <\
    \ n; u++)\r\n        {\r\n            for (int v : g[u])\r\n            {\r\n\
    \                rg[v].push_back(u);\r\n            }\r\n        }\r\n       \
    \ for (int u = 0; u < n; u++)\r\n        {\r\n            if (!used[u])\r\n  \
    \          {\r\n                dfs(u);\r\n            }\r\n        }\r\n    \
    \    fill(used.begin(), used.end(), false);\r\n        for (int i = n - 1; i >=\
    \ 0; i--)\r\n        {\r\n            if (!used[vs[i]])\r\n            {\r\n \
    \               rdfs(vs[i], k++);\r\n            }\r\n        }\r\n        group.resize(k);\r\
    \n        for (int u = 0; u < n; u++)\r\n        {\r\n            group[cmp[u]].push_back(u);\r\
    \n        }\r\n    }\r\n\r\n    graph<int> get_dag()\r\n    {\r\n        std::vector<bool>\
    \ b(k);\r\n        graph<int> dag(k);\r\n        for (int x = 0; x < k; x++)\r\
    \n        {\r\n            for (int u : group[x])\r\n            {\r\n       \
    \         for (int v : g[u])\r\n                {\r\n                    int y\
    \ = cmp[v];\r\n                    if (!b[y])\r\n                    {\r\n   \
    \                     dag.add_directed_edge(x, y);\r\n                       \
    \ b[y] = true;\r\n                    }\r\n                }\r\n            }\r\
    \n            for (int u : group[x])\r\n            {\r\n                for (int\
    \ v : g[u])\r\n                {\r\n                    b[cmp[v]] = false;\r\n\
    \                }\r\n            }\r\n        }\r\n        return dag;\r\n  \
    \  }\r\n\r\n    int number_of_component()\r\n    {\r\n        return k;\r\n  \
    \  }\r\n\r\n    const int operator[](const int &u) const\r\n    {\r\n        return\
    \ cmp[u];\r\n    }\r\n\r\nprivate:\r\n    int n;\r\n    int k;\r\n    const G\
    \ &g;\r\n    std::vector<std::vector<int>> rg;\r\n    std::vector<int> cmp;\r\n\
    \    std::vector<bool> used;\r\n    std::vector<int> vs;\r\n\r\n    void dfs(int\
    \ u)\r\n    {\r\n        used[u] = true;\r\n        for (int v : g[u])\r\n   \
    \     {\r\n            if (!used[v])\r\n            {\r\n                dfs(v);\r\
    \n            }\r\n        }\r\n        vs.push_back(u);\r\n    }\r\n\r\n    void\
    \ rdfs(int u, int k)\r\n    {\r\n        used[u] = true;\r\n        cmp[u] = k;\r\
    \n        for (int v : rg[u])\r\n        {\r\n            if (!used[v])\r\n  \
    \          {\r\n                rdfs(v, k);\r\n            }\r\n        }\r\n\
    \    }\r\n};\r\n#line 9 \"test/library_checker/scc.test.cpp\"\nusing namespace\
    \ std;\n\nint main()\n{\n    int n, m;\n    cin >> n >> m;\n    graph g(n);\n\
    \    for (int i = 0; i < m; i++)\n    {\n        int a, b;\n        cin >> a >>\
    \ b;\n        g.add_directed_edge(a, b);\n    }\n    scc_structure scc(g);\n \
    \   int k = scc.number_of_component();\n    cout << k << endl;\n    for (int x\
    \ = 0; x < k; x++)\n    {\n        cout << scc.group[x].size() << \" \";\n   \
    \     for (int u : scc.group[x])\n        {\n            cout << u << \" \";\n\
    \        }\n        cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <cassert>\n#include <vector>\n#include \"../../lib/graph/graph.hpp\"\
    \n#include \"../../lib/graph/other/scc.hpp\"\nusing namespace std;\n\nint main()\n\
    {\n    int n, m;\n    cin >> n >> m;\n    graph g(n);\n    for (int i = 0; i <\
    \ m; i++)\n    {\n        int a, b;\n        cin >> a >> b;\n        g.add_directed_edge(a,\
    \ b);\n    }\n    scc_structure scc(g);\n    int k = scc.number_of_component();\n\
    \    cout << k << endl;\n    for (int x = 0; x < k; x++)\n    {\n        cout\
    \ << scc.group[x].size() << \" \";\n        for (int u : scc.group[x])\n     \
    \   {\n            cout << u << \" \";\n        }\n        cout << endl;\n   \
    \ }\n}\n"
  dependsOn:
  - lib/graph/graph.hpp
  - lib/graph/other/scc.hpp
  isVerificationFile: true
  path: test/library_checker/scc.test.cpp
  requiredBy: []
  timestamp: '2023-01-14 04:14:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/scc.test.cpp
- /verify/test/library_checker/scc.test.cpp.html
title: test/library_checker/scc.test.cpp
---
