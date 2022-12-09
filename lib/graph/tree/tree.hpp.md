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
  bundledCode: "#line 1 \"lib/graph/tree/tree.hpp\"\ntemplate <typename T = int>\r\
    \nstruct tree\r\n{\r\n    int n;\r\n    int root;\r\n    std::vector<std::vector<edge<T>>>\
    \ t;\r\n    std::vector<edge<T>> par;\r\n    std::vector<int> dpt;\r\n    std::vector<int>\
    \ s;\r\n    std::vector<int> topological_order;\r\n    std::vector<std::vector<int>>\
    \ anc;\r\n\r\n    tree() {}\r\n\r\n    tree(graph<T> &g, int root, bool by_bfs\
    \ = true, bool g_is_tree = true) : n(g.size()), root(root)\r\n    {\r\n      \
    \  if (g_is_tree)\r\n        {\r\n            assert(g.edge_size() == n - 1);\r\
    \n        }\r\n        t.resize(n);\r\n        par.resize(n);\r\n        dpt.assign(n,\
    \ -1);\r\n        s.resize(n);\r\n        par[root] = edge<T>{root, -1};\r\n \
    \       dpt[root] = 0;\r\n        topological_order.push_back(root);\r\n     \
    \   if (by_bfs)\r\n        {\r\n            std::queue<int> que;\r\n         \
    \   que.push(root);\r\n            while (que.size())\r\n            {\r\n   \
    \             int u = que.front();\r\n                que.pop();\r\n         \
    \       for (edge<T> e : g[u])\r\n                {\r\n                    int\
    \ v = e.to;\r\n                    if (dpt[v] >= 0)\r\n                    {\r\
    \n                        continue;\r\n                    }\r\n             \
    \       add_child(u, e);\r\n                    que.push(v);\r\n             \
    \   }\r\n            }\r\n        }\r\n        else\r\n        {\r\n         \
    \   build_tree_by_dfs(root, g);\r\n        }\r\n        bool connected = true;\r\
    \n        for (int u = 0; u < n; u++)\r\n        {\r\n            if (dpt[u] ==\
    \ -1)\r\n            {\r\n                connected = false;\r\n            }\r\
    \n        }\r\n        assert(connected);\r\n        std::reverse(topological_order.begin(),\
    \ topological_order.end());\r\n    }\r\n\r\n    void build_tree_by_dfs(int u,\
    \ graph<T> &g)\r\n    {\r\n        for (edge<T> e : g[u])\r\n        {\r\n   \
    \         int v = e.to;\r\n            if (dpt[v] >= 0)\r\n            {\r\n \
    \               continue;\r\n            }\r\n            add_child(u, e);\r\n\
    \            build_tree_by_dfs(v, g);\r\n        }\r\n    }\r\n\r\n    void add_child(int\
    \ u, edge<T> &e)\r\n    {\r\n        int v = e.to;\r\n        t[u].push_back(e);\r\
    \n        par[v] = edge<T>{v, u, e.cost, e.id};\r\n        dpt[v] = dpt[u] + 1;\r\
    \n        topological_order.push_back(v);\r\n    }\r\n\r\n    int size(int u)\r\
    \n    {\r\n        if (s[u])\r\n        {\r\n            return s[u];\r\n    \
    \    }\r\n        s[u] = 1;\r\n        for (int v : t[u])\r\n        {\r\n   \
    \         s[u] += size(v);\r\n        }\r\n        return s[u];\r\n    }\r\n\r\
    \n    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    inline const\
    \ std::vector<edge<T>> &operator[](const int &u) const\r\n    {\r\n        return\
    \ t[u];\r\n    }\r\n};\r\n"
  code: "template <typename T = int>\r\nstruct tree\r\n{\r\n    int n;\r\n    int\
    \ root;\r\n    std::vector<std::vector<edge<T>>> t;\r\n    std::vector<edge<T>>\
    \ par;\r\n    std::vector<int> dpt;\r\n    std::vector<int> s;\r\n    std::vector<int>\
    \ topological_order;\r\n    std::vector<std::vector<int>> anc;\r\n\r\n    tree()\
    \ {}\r\n\r\n    tree(graph<T> &g, int root, bool by_bfs = true, bool g_is_tree\
    \ = true) : n(g.size()), root(root)\r\n    {\r\n        if (g_is_tree)\r\n   \
    \     {\r\n            assert(g.edge_size() == n - 1);\r\n        }\r\n      \
    \  t.resize(n);\r\n        par.resize(n);\r\n        dpt.assign(n, -1);\r\n  \
    \      s.resize(n);\r\n        par[root] = edge<T>{root, -1};\r\n        dpt[root]\
    \ = 0;\r\n        topological_order.push_back(root);\r\n        if (by_bfs)\r\n\
    \        {\r\n            std::queue<int> que;\r\n            que.push(root);\r\
    \n            while (que.size())\r\n            {\r\n                int u = que.front();\r\
    \n                que.pop();\r\n                for (edge<T> e : g[u])\r\n   \
    \             {\r\n                    int v = e.to;\r\n                    if\
    \ (dpt[v] >= 0)\r\n                    {\r\n                        continue;\r\
    \n                    }\r\n                    add_child(u, e);\r\n          \
    \          que.push(v);\r\n                }\r\n            }\r\n        }\r\n\
    \        else\r\n        {\r\n            build_tree_by_dfs(root, g);\r\n    \
    \    }\r\n        bool connected = true;\r\n        for (int u = 0; u < n; u++)\r\
    \n        {\r\n            if (dpt[u] == -1)\r\n            {\r\n            \
    \    connected = false;\r\n            }\r\n        }\r\n        assert(connected);\r\
    \n        std::reverse(topological_order.begin(), topological_order.end());\r\n\
    \    }\r\n\r\n    void build_tree_by_dfs(int u, graph<T> &g)\r\n    {\r\n    \
    \    for (edge<T> e : g[u])\r\n        {\r\n            int v = e.to;\r\n    \
    \        if (dpt[v] >= 0)\r\n            {\r\n                continue;\r\n  \
    \          }\r\n            add_child(u, e);\r\n            build_tree_by_dfs(v,\
    \ g);\r\n        }\r\n    }\r\n\r\n    void add_child(int u, edge<T> &e)\r\n \
    \   {\r\n        int v = e.to;\r\n        t[u].push_back(e);\r\n        par[v]\
    \ = edge<T>{v, u, e.cost, e.id};\r\n        dpt[v] = dpt[u] + 1;\r\n        topological_order.push_back(v);\r\
    \n    }\r\n\r\n    int size(int u)\r\n    {\r\n        if (s[u])\r\n        {\r\
    \n            return s[u];\r\n        }\r\n        s[u] = 1;\r\n        for (int\
    \ v : t[u])\r\n        {\r\n            s[u] += size(v);\r\n        }\r\n    \
    \    return s[u];\r\n    }\r\n\r\n    int size()\r\n    {\r\n        return n;\r\
    \n    }\r\n\r\n    inline const std::vector<edge<T>> &operator[](const int &u)\
    \ const\r\n    {\r\n        return t[u];\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/tree/tree.hpp
  requiredBy: []
  timestamp: '2022-12-10 07:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/tree/tree.hpp
layout: document
redirect_from:
- /library/lib/graph/tree/tree.hpp
- /library/lib/graph/tree/tree.hpp.html
title: lib/graph/tree/tree.hpp
---
