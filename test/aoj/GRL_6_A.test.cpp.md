---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/flow/MaximumFlow.hpp
    title: lib/graph/flow/MaximumFlow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <queue>\n#line 1 \"lib/graph/flow/MaximumFlow.hpp\"\
    \ntemplate <typename T = int>\r\nstruct MaximumFlow\r\n{\r\npublic:\r\n    struct\
    \ Edge\r\n    {\r\n        int from, to;\r\n        T cap, flow;\r\n        int\
    \ rev;\r\n        int id;\r\n\r\n        operator int() const\r\n        {\r\n\
    \            return to;\r\n        }\r\n    };\r\n\r\n    MaximumFlow() {}\r\n\
    \r\n    MaximumFlow(int n) : n(n), m(0), g(n) {}\r\n\r\n    void add_directed_edge(int\
    \ from, int to, T cap)\r\n    {\r\n        assert(0 <= from && from < n);\r\n\
    \        assert(0 <= to && to < n);\r\n        epos.push_back(std::pair<int, int>(from,\
    \ (int)g[from].size()));\r\n        g[from].push_back((Edge){from, to, cap, 0,\
    \ (int)g[to].size(), m++});\r\n        g[to].push_back((Edge){to, from, 0, cap,\
    \ (int)g[from].size() - 1, -1});\r\n    }\r\n\r\n    T get_maximum_flow(int source,\
    \ int sink)\r\n    {\r\n        assert(0 <= source && source < n);\r\n       \
    \ assert(0 <= sink && sink < n);\r\n\r\n        std::vector<int> d(n);\r\n   \
    \     std::vector<int> nx(n);\r\n\r\n        auto bfs = [&]()\r\n        {\r\n\
    \            fill(d.begin(), d.end(), -1);\r\n            std::queue<int> que;\r\
    \n            d[sink] = 0;\r\n            que.push(sink);\r\n            while\
    \ (que.size())\r\n            {\r\n                int u = que.front();\r\n  \
    \              que.pop();\r\n                for (Edge &e : g[u])\r\n        \
    \        {\r\n                    int v = e.to;\r\n                    if (e.flow\
    \ > 0 && d[v] == -1)\r\n                    {\r\n                        d[v]\
    \ = d[u] + 1;\r\n                        que.push(v);\r\n                    }\r\
    \n                }\r\n            }\r\n        };\r\n\r\n        auto dfs = [&](auto\
    \ self, int u, T f)\r\n        {\r\n            if (u == sink)\r\n           \
    \ {\r\n                return f;\r\n            }\r\n            for (int &i =\
    \ nx[u]; i < (int)g[u].size(); i++)\r\n            {\r\n                Edge &e\
    \ = g[u][i];\r\n                int v = e.to;\r\n                if (d[v] >= d[u]\
    \ || e.cap == 0)\r\n                {\r\n                    continue;\r\n   \
    \             }\r\n                f = (f == -1) ? e.cap : std::min(f, e.cap);\r\
    \n                T fl = self(self, v, f);\r\n                if (fl > 0)\r\n\
    \                {\r\n                    e.cap -= fl;\r\n                   \
    \ e.flow += fl;\r\n                    g[e.to][e.rev].cap += fl;\r\n         \
    \           g[e.to][e.rev].flow -= fl;\r\n                    return fl;\r\n \
    \               }\r\n            }\r\n            return 0;\r\n        };\r\n\r\
    \n        T res = 0;\r\n        while (true)\r\n        {\r\n            bfs();\r\
    \n            if (d[source] == -1)\r\n            {\r\n                return\
    \ res;\r\n            }\r\n            fill(nx.begin(), nx.end(), 0);\r\n    \
    \        for (T f; (f = dfs(dfs, source, -1)) > 0;)\r\n            {\r\n     \
    \           res += f;\r\n            }\r\n        }\r\n    }\r\n\r\n    Edge &get_edge(int\
    \ id)\r\n    {\r\n        assert(0 <= id && id < m);\r\n        return g[epos[id].first][epos[id].second];\r\
    \n    }\r\n\r\n    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n \
    \   int edge_size()\r\n    {\r\n        return m;\r\n    }\r\n\r\n    inline const\
    \ std::vector<Edge> &operator[](const int &u) const\r\n    {\r\n        return\
    \ g[u];\r\n    }\r\n\r\n    inline std::vector<Edge> &operator[](const int &u)\r\
    \n    {\r\n        return g[u];\r\n    }\r\n\r\nprivate:\r\n    int n;\r\n   \
    \ int m;\r\n    std::vector<std::vector<Edge>> g;\r\n    std::vector<std::pair<int,\
    \ int>> epos;\r\n};\r\n#line 7 \"test/aoj/GRL_6_A.test.cpp\"\nusing namespace\
    \ std;\n\nint main()\n{\n    int n, m;\n    cin >> n >> m;\n    MaximumFlow<int>\
    \ g(n);\n    for (int i = 0; i < m; i++)\n    {\n        int u, v, c;\n      \
    \  cin >> u >> v >> c;\n        g.add_directed_edge(u, v, c);\n    }\n    cout\
    \ << g.get_maximum_flow(0, n - 1) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <queue>\n#include \"../../lib/graph/flow/MaximumFlow.hpp\"\
    \nusing namespace std;\n\nint main()\n{\n    int n, m;\n    cin >> n >> m;\n \
    \   MaximumFlow<int> g(n);\n    for (int i = 0; i < m; i++)\n    {\n        int\
    \ u, v, c;\n        cin >> u >> v >> c;\n        g.add_directed_edge(u, v, c);\n\
    \    }\n    cout << g.get_maximum_flow(0, n - 1) << endl;\n}\n"
  dependsOn:
  - lib/graph/flow/MaximumFlow.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 22:53:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---