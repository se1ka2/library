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
  bundledCode: "#line 1 \"lib/graph/flow/min_cost_flow.hpp\"\ntemplate <typename S\
    \ = int, typename T = int>\r\nstruct edge\r\n{\r\n    int from, to;\r\n    S cap,\
    \ flow;\r\n    T cost;\r\n    int rev;\r\n    int id;\r\n\r\n    operator int()\
    \ const\r\n    {\r\n        return to;\r\n    }\r\n};\r\n\r\ntemplate <typename\
    \ S = int, typename T = int>\r\nstruct mcf_graph\r\n{\r\npublic:\r\n    mcf_graph()\
    \ {}\r\n\r\n    mcf_graph(int n) : n(n)\r\n    {\r\n        g.resize(n);\r\n \
    \       potential.resize(n);\r\n    }\r\n\r\n    void add_directed_edge(int from,\
    \ int to, S cap, T cost)\r\n    {\r\n        assert(0 <= from && from < n);\r\n\
    \        assert(0 <= to && to < n);\r\n        epos.push_back(std::pair<int, int>(from,\
    \ (int)g[from].size()));\r\n        g[from].push_back((edge<S, T>){from, to, cap,\
    \ 0, cost, (int)g[to].size(), m});\r\n        g[to].push_back((edge<S, T>){to,\
    \ from, 0, cap, -cost, (int)g[from].size() - 1, m++});\r\n    }\r\n\r\n    std::pair<S,\
    \ T> min_cost_flow(int source, int sink, S f = -1)\r\n    {\r\n        bool nonnegative\
    \ = true;\r\n        for (int u = 0; u < n; u++)\r\n        {\r\n            for\
    \ (edge<S, T> &e : g[u])\r\n            {\r\n                if (e.cap && e.cost\
    \ + potential[u] - potential[e.to] < 0)\r\n                {\r\n             \
    \       nonnegative = false;\r\n                }\r\n            }\r\n       \
    \ }\r\n        assert(nonnegative);\r\n        S sum_of_flow = 0;\r\n        T\
    \ sum_of_cost = 0;\r\n        using P = std::pair<T, int>;\r\n        std::vector<T>\
    \ dist(n);\r\n        std::vector<int> prevv(n);\r\n        std::vector<int> preve(n);\r\
    \n        while (f)\r\n        {\r\n            std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> que;\r\n            fill(dist.begin(), dist.end(), -1);\r\n\
    \            dist[source] = 0;\r\n            que.push(P(dist[source], source));\r\
    \n            while (!que.empty())\r\n            {\r\n                auto [x,\
    \ u] = que.top();\r\n                que.pop();\r\n                if (u == sink)\r\
    \n                {\r\n                    break;\r\n                }\r\n   \
    \             if (dist[u] < x)\r\n                {\r\n                    continue;\r\
    \n                }\r\n                for (int i = 0; i < (int)g[u].size(); i++)\r\
    \n                {\r\n                    edge<S, T> &e = g[u][i];\r\n      \
    \              if (e.cap == 0)\r\n                    {\r\n                  \
    \      continue;\r\n                    }\r\n                    int v = e.to;\r\
    \n                    T cost = e.cost + potential[u] - potential[v];\r\n     \
    \               if (dist[v] == -1 || dist[v] > dist[u] + cost)\r\n           \
    \         {\r\n                        dist[v] = dist[u] + cost;\r\n         \
    \               prevv[v] = u;\r\n                        preve[v] = i;\r\n   \
    \                     que.push(P(dist[v], v));\r\n                    }\r\n  \
    \              }\r\n            }\r\n            if (dist[sink] == -1)\r\n   \
    \         {\r\n                break;\r\n            }\r\n            for (int\
    \ u = 0; u < n; u++)\r\n            {\r\n                potential[u] += (dist[u]\
    \ == -1 || dist[u] > dist[sink]) ? dist[sink] : dist[u];\r\n            }\r\n\
    \            S flow = f;\r\n            for (int u = sink; u != source; u = prevv[u])\r\
    \n            {\r\n                flow = (flow < 0) ? g[prevv[u]][preve[u]].cap\
    \ : min(flow, g[prevv[u]][preve[u]].cap);\r\n            }\r\n            f -=\
    \ flow;\r\n            sum_of_flow += flow;\r\n            for (int u = sink;\
    \ u != source; u = prevv[u])\r\n            {\r\n                edge<S, T> &e\
    \ = g[prevv[u]][preve[u]];\r\n                e.cap -= flow;\r\n             \
    \   e.flow += flow;\r\n                g[u][e.rev].cap += flow;\r\n          \
    \      g[u][e.rev].flow -= flow;\r\n                sum_of_cost += e.cost * flow;\r\
    \n            }\r\n        }\r\n        return std::pair<S, T>(sum_of_flow, sum_of_cost);\r\
    \n    }\r\n\r\n    edge<S, T> &get_edge(int id)\r\n    {\r\n        assert(id\
    \ < m);\r\n        return g[epos[id].first][epos[id].second];\r\n    }\r\n\r\n\
    \    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    inline const\
    \ std::vector<edge<S, T>> &operator[](const int &u) const\r\n    {\r\n       \
    \ return g[u];\r\n    }\r\n\r\n    inline std::vector<edge<S, T>> &operator[](const\
    \ int &u)\r\n    {\r\n        return g[u];\r\n    }\r\n\r\nprivate:\r\n    int\
    \ n, m;\r\n    std::vector<std::vector<edge<S, T>>> g;\r\n    std::vector<T> potential;\r\
    \n    std::vector<std::pair<int, int>> epos;\r\n\r\n    void init_potential(bool\
    \ is_dag)\r\n    {\r\n        if (is_dag)\r\n        {\r\n            std::vector<int>\
    \ d(n);\r\n            for (int u = 0; u < n; u++)\r\n            {\r\n      \
    \          for (edge<S, T> &e : g[u])\r\n                {\r\n               \
    \     if (e.cap)\r\n                    {\r\n                        d[e.to]++;\r\
    \n                    }\r\n                }\r\n            }\r\n            std::queue<int>\
    \ que;\r\n            for (int u = 0; u < n; u++)\r\n            {\r\n       \
    \         if (!d[u])\r\n                {\r\n                    que.push(u);\r\
    \n                }\r\n            }\r\n            while (que.size())\r\n   \
    \         {\r\n                int u = que.front();\r\n                que.pop();\r\
    \n                for (edge<S, T> &e : g[u])\r\n                {\r\n        \
    \            if (!e.cap)\r\n                    {\r\n                        continue;\r\
    \n                    }\r\n                    int v = e.to;\r\n             \
    \       potential[v] = min(potential[v], potential[u] + e.cost);\r\n         \
    \           d[v]--;\r\n                    if (!d[v])\r\n                    {\r\
    \n                        que.push(v);\r\n                    }\r\n          \
    \      }\r\n            }\r\n        }\r\n        else\r\n        {\r\n      \
    \      for (int i = 0; i < n; i++)\r\n            {\r\n                bool flag\
    \ = false;\r\n                for (int u = 0; u < n; u++)\r\n                {\r\
    \n                    for (edge<S, T> &e : g[u])\r\n                    {\r\n\
    \                        if (e.cap == 0)\r\n                        {\r\n    \
    \                        continue;\r\n                        }\r\n          \
    \              int v = e.to;\r\n                        if (potential[v] > potential[u]\
    \ + e.cost)\r\n                        {\r\n                            potential[v]\
    \ = potential[u] + e.cost;\r\n                            flag = true;\r\n   \
    \                     }\r\n                    }\r\n                }\r\n    \
    \            if (!flag)\r\n                {\r\n                    break;\r\n\
    \                }\r\n            }\r\n        }\r\n    }\r\n};\r\n"
  code: "template <typename S = int, typename T = int>\r\nstruct edge\r\n{\r\n   \
    \ int from, to;\r\n    S cap, flow;\r\n    T cost;\r\n    int rev;\r\n    int\
    \ id;\r\n\r\n    operator int() const\r\n    {\r\n        return to;\r\n    }\r\
    \n};\r\n\r\ntemplate <typename S = int, typename T = int>\r\nstruct mcf_graph\r\
    \n{\r\npublic:\r\n    mcf_graph() {}\r\n\r\n    mcf_graph(int n) : n(n)\r\n  \
    \  {\r\n        g.resize(n);\r\n        potential.resize(n);\r\n    }\r\n\r\n\
    \    void add_directed_edge(int from, int to, S cap, T cost)\r\n    {\r\n    \
    \    assert(0 <= from && from < n);\r\n        assert(0 <= to && to < n);\r\n\
    \        epos.push_back(std::pair<int, int>(from, (int)g[from].size()));\r\n \
    \       g[from].push_back((edge<S, T>){from, to, cap, 0, cost, (int)g[to].size(),\
    \ m});\r\n        g[to].push_back((edge<S, T>){to, from, 0, cap, -cost, (int)g[from].size()\
    \ - 1, m++});\r\n    }\r\n\r\n    std::pair<S, T> min_cost_flow(int source, int\
    \ sink, S f = -1)\r\n    {\r\n        bool nonnegative = true;\r\n        for\
    \ (int u = 0; u < n; u++)\r\n        {\r\n            for (edge<S, T> &e : g[u])\r\
    \n            {\r\n                if (e.cap && e.cost + potential[u] - potential[e.to]\
    \ < 0)\r\n                {\r\n                    nonnegative = false;\r\n  \
    \              }\r\n            }\r\n        }\r\n        assert(nonnegative);\r\
    \n        S sum_of_flow = 0;\r\n        T sum_of_cost = 0;\r\n        using P\
    \ = std::pair<T, int>;\r\n        std::vector<T> dist(n);\r\n        std::vector<int>\
    \ prevv(n);\r\n        std::vector<int> preve(n);\r\n        while (f)\r\n   \
    \     {\r\n            std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ que;\r\n            fill(dist.begin(), dist.end(), -1);\r\n            dist[source]\
    \ = 0;\r\n            que.push(P(dist[source], source));\r\n            while\
    \ (!que.empty())\r\n            {\r\n                auto [x, u] = que.top();\r\
    \n                que.pop();\r\n                if (u == sink)\r\n           \
    \     {\r\n                    break;\r\n                }\r\n               \
    \ if (dist[u] < x)\r\n                {\r\n                    continue;\r\n \
    \               }\r\n                for (int i = 0; i < (int)g[u].size(); i++)\r\
    \n                {\r\n                    edge<S, T> &e = g[u][i];\r\n      \
    \              if (e.cap == 0)\r\n                    {\r\n                  \
    \      continue;\r\n                    }\r\n                    int v = e.to;\r\
    \n                    T cost = e.cost + potential[u] - potential[v];\r\n     \
    \               if (dist[v] == -1 || dist[v] > dist[u] + cost)\r\n           \
    \         {\r\n                        dist[v] = dist[u] + cost;\r\n         \
    \               prevv[v] = u;\r\n                        preve[v] = i;\r\n   \
    \                     que.push(P(dist[v], v));\r\n                    }\r\n  \
    \              }\r\n            }\r\n            if (dist[sink] == -1)\r\n   \
    \         {\r\n                break;\r\n            }\r\n            for (int\
    \ u = 0; u < n; u++)\r\n            {\r\n                potential[u] += (dist[u]\
    \ == -1 || dist[u] > dist[sink]) ? dist[sink] : dist[u];\r\n            }\r\n\
    \            S flow = f;\r\n            for (int u = sink; u != source; u = prevv[u])\r\
    \n            {\r\n                flow = (flow < 0) ? g[prevv[u]][preve[u]].cap\
    \ : min(flow, g[prevv[u]][preve[u]].cap);\r\n            }\r\n            f -=\
    \ flow;\r\n            sum_of_flow += flow;\r\n            for (int u = sink;\
    \ u != source; u = prevv[u])\r\n            {\r\n                edge<S, T> &e\
    \ = g[prevv[u]][preve[u]];\r\n                e.cap -= flow;\r\n             \
    \   e.flow += flow;\r\n                g[u][e.rev].cap += flow;\r\n          \
    \      g[u][e.rev].flow -= flow;\r\n                sum_of_cost += e.cost * flow;\r\
    \n            }\r\n        }\r\n        return std::pair<S, T>(sum_of_flow, sum_of_cost);\r\
    \n    }\r\n\r\n    edge<S, T> &get_edge(int id)\r\n    {\r\n        assert(id\
    \ < m);\r\n        return g[epos[id].first][epos[id].second];\r\n    }\r\n\r\n\
    \    int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    inline const\
    \ std::vector<edge<S, T>> &operator[](const int &u) const\r\n    {\r\n       \
    \ return g[u];\r\n    }\r\n\r\n    inline std::vector<edge<S, T>> &operator[](const\
    \ int &u)\r\n    {\r\n        return g[u];\r\n    }\r\n\r\nprivate:\r\n    int\
    \ n, m;\r\n    std::vector<std::vector<edge<S, T>>> g;\r\n    std::vector<T> potential;\r\
    \n    std::vector<std::pair<int, int>> epos;\r\n\r\n    void init_potential(bool\
    \ is_dag)\r\n    {\r\n        if (is_dag)\r\n        {\r\n            std::vector<int>\
    \ d(n);\r\n            for (int u = 0; u < n; u++)\r\n            {\r\n      \
    \          for (edge<S, T> &e : g[u])\r\n                {\r\n               \
    \     if (e.cap)\r\n                    {\r\n                        d[e.to]++;\r\
    \n                    }\r\n                }\r\n            }\r\n            std::queue<int>\
    \ que;\r\n            for (int u = 0; u < n; u++)\r\n            {\r\n       \
    \         if (!d[u])\r\n                {\r\n                    que.push(u);\r\
    \n                }\r\n            }\r\n            while (que.size())\r\n   \
    \         {\r\n                int u = que.front();\r\n                que.pop();\r\
    \n                for (edge<S, T> &e : g[u])\r\n                {\r\n        \
    \            if (!e.cap)\r\n                    {\r\n                        continue;\r\
    \n                    }\r\n                    int v = e.to;\r\n             \
    \       potential[v] = min(potential[v], potential[u] + e.cost);\r\n         \
    \           d[v]--;\r\n                    if (!d[v])\r\n                    {\r\
    \n                        que.push(v);\r\n                    }\r\n          \
    \      }\r\n            }\r\n        }\r\n        else\r\n        {\r\n      \
    \      for (int i = 0; i < n; i++)\r\n            {\r\n                bool flag\
    \ = false;\r\n                for (int u = 0; u < n; u++)\r\n                {\r\
    \n                    for (edge<S, T> &e : g[u])\r\n                    {\r\n\
    \                        if (e.cap == 0)\r\n                        {\r\n    \
    \                        continue;\r\n                        }\r\n          \
    \              int v = e.to;\r\n                        if (potential[v] > potential[u]\
    \ + e.cost)\r\n                        {\r\n                            potential[v]\
    \ = potential[u] + e.cost;\r\n                            flag = true;\r\n   \
    \                     }\r\n                    }\r\n                }\r\n    \
    \            if (!flag)\r\n                {\r\n                    break;\r\n\
    \                }\r\n            }\r\n        }\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/flow/min_cost_flow.hpp
  requiredBy: []
  timestamp: '2022-12-14 22:24:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/flow/min_cost_flow.hpp
layout: document
redirect_from:
- /library/lib/graph/flow/min_cost_flow.hpp
- /library/lib/graph/flow/min_cost_flow.hpp.html
title: lib/graph/flow/min_cost_flow.hpp
---
