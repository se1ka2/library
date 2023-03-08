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
  bundledCode: "#line 1 \"lib/graph/matching/StableMatching.hpp\"\ntemplate <typename\
    \ T = int>\r\nstruct stable_matching\r\n{\r\npublic:\r\n    struct Edge\r\n  \
    \  {\r\n        int a, b;\r\n        int preference_a, preference_b; // The smaller\
    \ the value, the higher the priority.\r\n        bool is_matched;\r\n        T\
    \ cost;\r\n        int id;\r\n\r\n        bool operator<(const Edge &e) const\r\
    \n        {\r\n            return preference_a < e.preference_a;\r\n        }\r\
    \n    };\r\n\r\n    stable_matching() {}\r\n\r\n    stable_matching(int p, int\
    \ q) : p(p), q(q), m(0)\r\n    {\r\n        g.resize(p);\r\n    }\r\n\r\n    void\
    \ add_directed_edge(int a, int b, int preference_a, int preference_b, T cost =\
    \ 1)\r\n    {\r\n        assert(0 <= a && a < p);\r\n        assert(0 <= b &&\
    \ b < q);\r\n        epos.push_back(std::pair<int, int>(a, (int)g[a].size()));\r\
    \n        g[a].push_back((Edge){a, b, preference_a, preference_b, false, cost,\
    \ m++});\r\n    }\r\n\r\n    void get_stable_matching()\r\n    {\r\n        for\
    \ (int a = 0; a < p; a++)\r\n        {\r\n            if (!std::is_sorted(g[a].begin(),\
    \ g[a].end()))\r\n            {\r\n                std::sort(g[a].begin(), g[a].end());\r\
    \n            }\r\n        }\r\n        std::vector<std::pair<int, int>> match(q,\
    \ std::pair<int, int>(-1, -1));\r\n        std::vector<int> nx(p, 0);\r\n    \
    \    std::queue<int> que;\r\n        for (int a = 0; a < p; a++)\r\n        {\r\
    \n            que.push(a);\r\n        }\r\n        while (que.size())\r\n    \
    \    {\r\n            int a = que.front();\r\n            que.pop();\r\n     \
    \       for (int &i = nx[a]; i < (int)g[a].size(); i++)\r\n            {\r\n \
    \               int b = g[a][i].b;\r\n                int x = match[b].first;\r\
    \n                int j = match[b].second;\r\n                if (x >= 0 && g[a][i].preference_b\
    \ < g[x][j].preference_b)\r\n                {\r\n                    g[x][j].is_matched\
    \ = false;\r\n                    nx[x]++;\r\n                    que.push(x);\r\
    \n                    x = -1;\r\n                }\r\n                if (x ==\
    \ -1)\r\n                {\r\n                    g[a][i].is_matched = true;\r\
    \n                    match[b] = std::pair<int, int>(a, i);\r\n              \
    \      break;\r\n                }\r\n            }\r\n        }\r\n    }\r\n\r\
    \n    std::vector<Edge> get_matching_edges()\r\n    {\r\n        std::vector<Edge>\
    \ res;\r\n        for (int i = 0; i < m; i++)\r\n        {\r\n            Edge\
    \ e = g[epos[i].first][epos[i].second];\r\n            if (e.is_matched)\r\n \
    \           {\r\n                res.push_back(e);\r\n            }\r\n      \
    \  }\r\n        return res;\r\n    }\r\n\r\n    Edge &get_edge(int id)\r\n   \
    \ {\r\n        assert(id < m);\r\n        return g[epos[id].first][epos[id].second];\r\
    \n    }\r\n\r\n    int get_size()\r\n    {\r\n        return p + q;\r\n    }\r\
    \n\r\n    int get_left_size()\r\n    {\r\n        return p;\r\n    }\r\n\r\n \
    \   int get_right_size()\r\n    {\r\n        return q;\r\n    }\r\n\r\n    int\
    \ get_edge_size()\r\n    {\r\n        return m;\r\n    }\r\n\r\nprivate:\r\n \
    \   int p, q, m;\r\n    std::vector<std::vector<Edge>> g;\r\n    std::vector<std::pair<int,\
    \ int>> epos;\r\n};\r\n"
  code: "template <typename T = int>\r\nstruct stable_matching\r\n{\r\npublic:\r\n\
    \    struct Edge\r\n    {\r\n        int a, b;\r\n        int preference_a, preference_b;\
    \ // The smaller the value, the higher the priority.\r\n        bool is_matched;\r\
    \n        T cost;\r\n        int id;\r\n\r\n        bool operator<(const Edge\
    \ &e) const\r\n        {\r\n            return preference_a < e.preference_a;\r\
    \n        }\r\n    };\r\n\r\n    stable_matching() {}\r\n\r\n    stable_matching(int\
    \ p, int q) : p(p), q(q), m(0)\r\n    {\r\n        g.resize(p);\r\n    }\r\n\r\
    \n    void add_directed_edge(int a, int b, int preference_a, int preference_b,\
    \ T cost = 1)\r\n    {\r\n        assert(0 <= a && a < p);\r\n        assert(0\
    \ <= b && b < q);\r\n        epos.push_back(std::pair<int, int>(a, (int)g[a].size()));\r\
    \n        g[a].push_back((Edge){a, b, preference_a, preference_b, false, cost,\
    \ m++});\r\n    }\r\n\r\n    void get_stable_matching()\r\n    {\r\n        for\
    \ (int a = 0; a < p; a++)\r\n        {\r\n            if (!std::is_sorted(g[a].begin(),\
    \ g[a].end()))\r\n            {\r\n                std::sort(g[a].begin(), g[a].end());\r\
    \n            }\r\n        }\r\n        std::vector<std::pair<int, int>> match(q,\
    \ std::pair<int, int>(-1, -1));\r\n        std::vector<int> nx(p, 0);\r\n    \
    \    std::queue<int> que;\r\n        for (int a = 0; a < p; a++)\r\n        {\r\
    \n            que.push(a);\r\n        }\r\n        while (que.size())\r\n    \
    \    {\r\n            int a = que.front();\r\n            que.pop();\r\n     \
    \       for (int &i = nx[a]; i < (int)g[a].size(); i++)\r\n            {\r\n \
    \               int b = g[a][i].b;\r\n                int x = match[b].first;\r\
    \n                int j = match[b].second;\r\n                if (x >= 0 && g[a][i].preference_b\
    \ < g[x][j].preference_b)\r\n                {\r\n                    g[x][j].is_matched\
    \ = false;\r\n                    nx[x]++;\r\n                    que.push(x);\r\
    \n                    x = -1;\r\n                }\r\n                if (x ==\
    \ -1)\r\n                {\r\n                    g[a][i].is_matched = true;\r\
    \n                    match[b] = std::pair<int, int>(a, i);\r\n              \
    \      break;\r\n                }\r\n            }\r\n        }\r\n    }\r\n\r\
    \n    std::vector<Edge> get_matching_edges()\r\n    {\r\n        std::vector<Edge>\
    \ res;\r\n        for (int i = 0; i < m; i++)\r\n        {\r\n            Edge\
    \ e = g[epos[i].first][epos[i].second];\r\n            if (e.is_matched)\r\n \
    \           {\r\n                res.push_back(e);\r\n            }\r\n      \
    \  }\r\n        return res;\r\n    }\r\n\r\n    Edge &get_edge(int id)\r\n   \
    \ {\r\n        assert(id < m);\r\n        return g[epos[id].first][epos[id].second];\r\
    \n    }\r\n\r\n    int get_size()\r\n    {\r\n        return p + q;\r\n    }\r\
    \n\r\n    int get_left_size()\r\n    {\r\n        return p;\r\n    }\r\n\r\n \
    \   int get_right_size()\r\n    {\r\n        return q;\r\n    }\r\n\r\n    int\
    \ get_edge_size()\r\n    {\r\n        return m;\r\n    }\r\n\r\nprivate:\r\n \
    \   int p, q, m;\r\n    std::vector<std::vector<Edge>> g;\r\n    std::vector<std::pair<int,\
    \ int>> epos;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/matching/StableMatching.hpp
  requiredBy: []
  timestamp: '2023-03-08 02:20:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/matching/StableMatching.hpp
layout: document
redirect_from:
- /library/lib/graph/matching/StableMatching.hpp
- /library/lib/graph/matching/StableMatching.hpp.html
title: lib/graph/matching/StableMatching.hpp
---
