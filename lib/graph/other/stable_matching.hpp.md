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
  bundledCode: "#line 1 \"lib/graph/other/stable_matching.hpp\"\ntemplate <typename\
    \ T = int>\r\nstruct edge\r\n{\r\n    int a, b;\r\n    int preference_a, preference_b;\r\
    \n    bool is_matched;\r\n    T cost;\r\n    int id;\r\n\r\n    bool operator<(const\
    \ edge<T> &e) const\r\n    {\r\n        return preference_a < e.preference_a;\r\
    \n    }\r\n};\r\n\r\ntemplate <typename T = int>\r\nstruct stable_matching\r\n\
    {\r\n    int p, q, m;\r\n    std::vector<std::vector<edge<T>>> g;\r\n    std::vector<std::pair<int,\
    \ int>> epos;\r\n\r\n    stable_matching() {}\r\n\r\n    stable_matching(int p,\
    \ int q) : p(p), q(q), m(0)\r\n    {\r\n        g.resize(p);\r\n    }\r\n\r\n\
    \    void add_directed_edge(int a, int b, int preference_a, int preference_b,\
    \ int cost = 1)\r\n    {\r\n        assert(0 <= a && a < p);\r\n        assert(0\
    \ <= b && b < q);\r\n        epos.push_back(std::pair<int, int>(a, (int)g[a].size()));\r\
    \n        g[a].push_back((edge<T>){a, b, preference_a, preference_b, false, cost,\
    \ m++});\r\n    }\r\n\r\n    void get_stable_matching()\r\n    {\r\n        for\
    \ (int a = 0; a < p; a++)\r\n        {\r\n            if (!std::is_sorted(g[a].begin(),\
    \ g[a].end()))\r\n            {\r\n                std::sort(g[a].begin(), g[a].end());\r\
    \n            }\r\n        }\r\n        std::vector<std::pair<int, int>> mbpos(q,\
    \ std::pair<int, int>(-1, -1));\r\n        std::vector<T> nx(p, 0);\r\n      \
    \  std::queue<T> que;\r\n        for (int a = 0; a < p; a++)\r\n        {\r\n\
    \            que.push(a);\r\n        }\r\n        while (que.size())\r\n     \
    \   {\r\n            int a = que.front();\r\n            que.pop();\r\n      \
    \      for (int &i = nx[a]; i < (int)g[a].size(); i++)\r\n            {\r\n  \
    \              int b = g[a][i].b;\r\n                int x = mbpos[b].first;\r\
    \n                if (x >= 0 && g[x][mbpos[b].second].preference_b > g[a][i].preference_b)\r\
    \n                {\r\n                    g[x][mbpos[b].second].is_matched =\
    \ false;\r\n                    nx[x]++;\r\n                    que.push(x);\r\
    \n                    x = -1;\r\n                }\r\n                if (x ==\
    \ -1)\r\n                {\r\n                    g[a][i].is_matched = true;\r\
    \n                    mbpos[b] = std::pair<int, int>(a, i);\r\n              \
    \      break;\r\n                }\r\n            }\r\n        }\r\n    }\r\n\r\
    \n    edge<T> &get_edge(int id)\r\n    {\r\n        assert(id < m);\r\n      \
    \  return g[epos[id].first][epos[id].second];\r\n    }\r\n};\r\n"
  code: "template <typename T = int>\r\nstruct edge\r\n{\r\n    int a, b;\r\n    int\
    \ preference_a, preference_b;\r\n    bool is_matched;\r\n    T cost;\r\n    int\
    \ id;\r\n\r\n    bool operator<(const edge<T> &e) const\r\n    {\r\n        return\
    \ preference_a < e.preference_a;\r\n    }\r\n};\r\n\r\ntemplate <typename T =\
    \ int>\r\nstruct stable_matching\r\n{\r\n    int p, q, m;\r\n    std::vector<std::vector<edge<T>>>\
    \ g;\r\n    std::vector<std::pair<int, int>> epos;\r\n\r\n    stable_matching()\
    \ {}\r\n\r\n    stable_matching(int p, int q) : p(p), q(q), m(0)\r\n    {\r\n\
    \        g.resize(p);\r\n    }\r\n\r\n    void add_directed_edge(int a, int b,\
    \ int preference_a, int preference_b, int cost = 1)\r\n    {\r\n        assert(0\
    \ <= a && a < p);\r\n        assert(0 <= b && b < q);\r\n        epos.push_back(std::pair<int,\
    \ int>(a, (int)g[a].size()));\r\n        g[a].push_back((edge<T>){a, b, preference_a,\
    \ preference_b, false, cost, m++});\r\n    }\r\n\r\n    void get_stable_matching()\r\
    \n    {\r\n        for (int a = 0; a < p; a++)\r\n        {\r\n            if\
    \ (!std::is_sorted(g[a].begin(), g[a].end()))\r\n            {\r\n           \
    \     std::sort(g[a].begin(), g[a].end());\r\n            }\r\n        }\r\n \
    \       std::vector<std::pair<int, int>> mbpos(q, std::pair<int, int>(-1, -1));\r\
    \n        std::vector<T> nx(p, 0);\r\n        std::queue<T> que;\r\n        for\
    \ (int a = 0; a < p; a++)\r\n        {\r\n            que.push(a);\r\n       \
    \ }\r\n        while (que.size())\r\n        {\r\n            int a = que.front();\r\
    \n            que.pop();\r\n            for (int &i = nx[a]; i < (int)g[a].size();\
    \ i++)\r\n            {\r\n                int b = g[a][i].b;\r\n            \
    \    int x = mbpos[b].first;\r\n                if (x >= 0 && g[x][mbpos[b].second].preference_b\
    \ > g[a][i].preference_b)\r\n                {\r\n                    g[x][mbpos[b].second].is_matched\
    \ = false;\r\n                    nx[x]++;\r\n                    que.push(x);\r\
    \n                    x = -1;\r\n                }\r\n                if (x ==\
    \ -1)\r\n                {\r\n                    g[a][i].is_matched = true;\r\
    \n                    mbpos[b] = std::pair<int, int>(a, i);\r\n              \
    \      break;\r\n                }\r\n            }\r\n        }\r\n    }\r\n\r\
    \n    edge<T> &get_edge(int id)\r\n    {\r\n        assert(id < m);\r\n      \
    \  return g[epos[id].first][epos[id].second];\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/other/stable_matching.hpp
  requiredBy: []
  timestamp: '2022-12-10 07:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/other/stable_matching.hpp
layout: document
redirect_from:
- /library/lib/graph/other/stable_matching.hpp
- /library/lib/graph/other/stable_matching.hpp.html
title: lib/graph/other/stable_matching.hpp
---
