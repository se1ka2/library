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
  bundledCode: "#line 1 \"lib/graph/other/scc.hpp\"\ntemplate <typename T = int>\r\
    \nstruct scc_graph\r\n{\r\n    int n, m;\r\n    std::vector<std::vector<edge<T>>>\
    \ g, rg;\r\n    std::vector<int> cmp;\r\n\r\n    scc_graph() {}\r\n\r\n    scc_graph(int\
    \ n) : n(n)\r\n    {\r\n        g.resize(n);\r\n        rg.resize(n);\r\n    \
    \    cmp.resize(n);\r\n    }\r\n\r\n    void add_directed_edge(int from, int to,\
    \ T cost = 1)\r\n    {\r\n        assert(0 <= from && from < n);\r\n        assert(0\
    \ <= to && to < n);\r\n        g[from].push_back((edge<T>){from, to, cost, m});\r\
    \n        rg[to].push_back((edge<T>){to, from, cost, m++});\r\n    }\r\n\r\n \
    \   void dfs(int u, vector<bool> &used, vector<int> &vs)\r\n    {\r\n        used[u]\
    \ = true;\r\n        for (int v : g[u])\r\n        {\r\n            if (!used[v])\r\
    \n            {\r\n                dfs(v, used, vs);\r\n            }\r\n    \
    \    }\r\n        vs.push_back(u);\r\n    }\r\n\r\n    void rdfs(int u, int k,\
    \ vector<bool> &used)\r\n    {\r\n        used[u] = true;\r\n        cmp[u] =\
    \ k;\r\n        for (int v : rg[u])\r\n        {\r\n            if (!used[v])\r\
    \n            {\r\n                rdfs(v, k, used);\r\n            }\r\n    \
    \    }\r\n    }\r\n\r\n    int build()\r\n    {\r\n        std::vector<bool> used(n,\
    \ false);\r\n        std::vector<int> vs;\r\n        for (int i = 0; i < n; i++)\r\
    \n        {\r\n            if (!used[i])\r\n            {\r\n                dfs(i,\
    \ used, vs);\r\n            }\r\n        }\r\n        fill(used.begin(), used.end(),\
    \ false);\r\n        int k = 0;\r\n        for (int i = n - 1; i >= 0; i--)\r\n\
    \        {\r\n            if (!used[vs[i]])\r\n            {\r\n             \
    \   rdfs(vs[i], k, used);\r\n                k++;\r\n            }\r\n       \
    \ }\r\n        return k;\r\n    }\r\n\r\n    graph<int> get_dag()\r\n    {\r\n\
    \        int k = build();\r\n        std::vector<std::vector<int>> p(k);\r\n \
    \       for (int u = 0; u < n; u++)\r\n        {\r\n            for (int v : g[u])\r\
    \n            {\r\n                p[cmp[u]].push_back(cmp[v]);\r\n          \
    \  }\r\n        }\r\n        std::vector<int> b(k);\r\n        graph<int> dag(k);\r\
    \n        for (int x = 0; x < k; x++)\r\n        {\r\n            for (int y :\
    \ p[x])\r\n            {\r\n                if (!b[y])\r\n                {\r\n\
    \                    dag.add_directed_edge(x, y);\r\n                    b[y]\
    \ = 1;\r\n                }\r\n            }\r\n            for (int y : p[x])\r\
    \n            {\r\n                b[y] = 0;\r\n            }\r\n        }\r\n\
    \        return dag;\r\n    }\r\n\r\n    int size()\r\n    {\r\n        return\
    \ n;\r\n    }\r\n\r\n    int edge_size()\r\n    {\r\n        return m;\r\n   \
    \ }\r\n\r\n    inline const std::vector<edge<T>> &operator[](const int &u) const\r\
    \n    {\r\n        return g[u];\r\n    }\r\n};\r\n"
  code: "template <typename T = int>\r\nstruct scc_graph\r\n{\r\n    int n, m;\r\n\
    \    std::vector<std::vector<edge<T>>> g, rg;\r\n    std::vector<int> cmp;\r\n\
    \r\n    scc_graph() {}\r\n\r\n    scc_graph(int n) : n(n)\r\n    {\r\n       \
    \ g.resize(n);\r\n        rg.resize(n);\r\n        cmp.resize(n);\r\n    }\r\n\
    \r\n    void add_directed_edge(int from, int to, T cost = 1)\r\n    {\r\n    \
    \    assert(0 <= from && from < n);\r\n        assert(0 <= to && to < n);\r\n\
    \        g[from].push_back((edge<T>){from, to, cost, m});\r\n        rg[to].push_back((edge<T>){to,\
    \ from, cost, m++});\r\n    }\r\n\r\n    void dfs(int u, vector<bool> &used, vector<int>\
    \ &vs)\r\n    {\r\n        used[u] = true;\r\n        for (int v : g[u])\r\n \
    \       {\r\n            if (!used[v])\r\n            {\r\n                dfs(v,\
    \ used, vs);\r\n            }\r\n        }\r\n        vs.push_back(u);\r\n   \
    \ }\r\n\r\n    void rdfs(int u, int k, vector<bool> &used)\r\n    {\r\n      \
    \  used[u] = true;\r\n        cmp[u] = k;\r\n        for (int v : rg[u])\r\n \
    \       {\r\n            if (!used[v])\r\n            {\r\n                rdfs(v,\
    \ k, used);\r\n            }\r\n        }\r\n    }\r\n\r\n    int build()\r\n\
    \    {\r\n        std::vector<bool> used(n, false);\r\n        std::vector<int>\
    \ vs;\r\n        for (int i = 0; i < n; i++)\r\n        {\r\n            if (!used[i])\r\
    \n            {\r\n                dfs(i, used, vs);\r\n            }\r\n    \
    \    }\r\n        fill(used.begin(), used.end(), false);\r\n        int k = 0;\r\
    \n        for (int i = n - 1; i >= 0; i--)\r\n        {\r\n            if (!used[vs[i]])\r\
    \n            {\r\n                rdfs(vs[i], k, used);\r\n                k++;\r\
    \n            }\r\n        }\r\n        return k;\r\n    }\r\n\r\n    graph<int>\
    \ get_dag()\r\n    {\r\n        int k = build();\r\n        std::vector<std::vector<int>>\
    \ p(k);\r\n        for (int u = 0; u < n; u++)\r\n        {\r\n            for\
    \ (int v : g[u])\r\n            {\r\n                p[cmp[u]].push_back(cmp[v]);\r\
    \n            }\r\n        }\r\n        std::vector<int> b(k);\r\n        graph<int>\
    \ dag(k);\r\n        for (int x = 0; x < k; x++)\r\n        {\r\n            for\
    \ (int y : p[x])\r\n            {\r\n                if (!b[y])\r\n          \
    \      {\r\n                    dag.add_directed_edge(x, y);\r\n             \
    \       b[y] = 1;\r\n                }\r\n            }\r\n            for (int\
    \ y : p[x])\r\n            {\r\n                b[y] = 0;\r\n            }\r\n\
    \        }\r\n        return dag;\r\n    }\r\n\r\n    int size()\r\n    {\r\n\
    \        return n;\r\n    }\r\n\r\n    int edge_size()\r\n    {\r\n        return\
    \ m;\r\n    }\r\n\r\n    inline const std::vector<edge<T>> &operator[](const int\
    \ &u) const\r\n    {\r\n        return g[u];\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/scc.hpp
  requiredBy: []
  timestamp: '2022-12-10 07:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/other/scc.hpp
layout: document
redirect_from:
- /library/lib/graph/other/scc.hpp
- /library/lib/graph/other/scc.hpp.html
title: lib/graph/other/scc.hpp
---
