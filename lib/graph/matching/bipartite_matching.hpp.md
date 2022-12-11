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
  bundledCode: "#line 1 \"lib/graph/matching/bipartite_matching.hpp\"\nstruct bipartite_matching\r\
    \n{\r\n    int p, q;\r\n    mf_graph<int> g;\r\n    std::vector<int> ml, mr;\r\
    \n\r\n    bipartite_matching() {}\r\n\r\n    bipartite_matching(int p, int q)\
    \ : p(p), q(q), g(p + q + 2), ml(p, -1), mr(q, -1)\r\n    {\r\n        for (int\
    \ a = 0; a < p; a++)\r\n        {\r\n            g.add_directed_edge(p + q, a,\
    \ 1);\r\n        }\r\n        for (int b = 0; b < q; b++)\r\n        {\r\n   \
    \         g.add_directed_edge(b + p, p + q + 1, 1);\r\n        }\r\n    }\r\n\r\
    \n    void add_edge(int a, int b)\r\n    {\r\n        assert(0 <= a && a < p);\r\
    \n        assert(0 <= b && b < q);\r\n        g.add_directed_edge(a, b + p, 1);\r\
    \n    }\r\n\r\n    int get_maximum_matching()\r\n    {\r\n        int k = g.get_maximum_flow(p\
    \ + q, p + q + 1);\r\n        for (int i = p + q; i < g.edge_size(); i++)\r\n\
    \        {\r\n            edge<int> &e = g.get_edge(i);\r\n            if (e.flow)\r\
    \n            {\r\n                ml[e.from] = mr[e.to - p] = e.id;\r\n     \
    \       }\r\n        }\r\n        return k;\r\n    }\r\n\r\n    bool is_matched(int\
    \ edge_id)\r\n    {\r\n        return (bool)(g.get_edge(edge_id + (p + q)).flow);\r\
    \n    }\r\n\r\n    bool is_covered(int u, bool left)\r\n    {\r\n        return\
    \ left ? (ml[u] >= 0) : (mr[u] >= 0);\r\n    }\r\n\r\n    edge<int> &get_incident_edge(int\
    \ u, bool left)\r\n    {\r\n        assert(is_covered(u, left));\r\n        return\
    \ left ? g.get_edge(ml[u]) : g.get_edge(mr[u]);\r\n    }\r\n\r\n    int match_to(int\
    \ u, bool left)\r\n    {\r\n        if(!is_covered(u, left))\r\n        {\r\n\
    \            return -1;\r\n        }\r\n        return left ? g.get_edge(ml[u]).to\
    \ - p : g.get_edge(mr[u]).from;\r\n    }\r\n};\r\n"
  code: "struct bipartite_matching\r\n{\r\n    int p, q;\r\n    mf_graph<int> g;\r\
    \n    std::vector<int> ml, mr;\r\n\r\n    bipartite_matching() {}\r\n\r\n    bipartite_matching(int\
    \ p, int q) : p(p), q(q), g(p + q + 2), ml(p, -1), mr(q, -1)\r\n    {\r\n    \
    \    for (int a = 0; a < p; a++)\r\n        {\r\n            g.add_directed_edge(p\
    \ + q, a, 1);\r\n        }\r\n        for (int b = 0; b < q; b++)\r\n        {\r\
    \n            g.add_directed_edge(b + p, p + q + 1, 1);\r\n        }\r\n    }\r\
    \n\r\n    void add_edge(int a, int b)\r\n    {\r\n        assert(0 <= a && a <\
    \ p);\r\n        assert(0 <= b && b < q);\r\n        g.add_directed_edge(a, b\
    \ + p, 1);\r\n    }\r\n\r\n    int get_maximum_matching()\r\n    {\r\n       \
    \ int k = g.get_maximum_flow(p + q, p + q + 1);\r\n        for (int i = p + q;\
    \ i < g.edge_size(); i++)\r\n        {\r\n            edge<int> &e = g.get_edge(i);\r\
    \n            if (e.flow)\r\n            {\r\n                ml[e.from] = mr[e.to\
    \ - p] = e.id;\r\n            }\r\n        }\r\n        return k;\r\n    }\r\n\
    \r\n    bool is_matched(int edge_id)\r\n    {\r\n        return (bool)(g.get_edge(edge_id\
    \ + (p + q)).flow);\r\n    }\r\n\r\n    bool is_covered(int u, bool left)\r\n\
    \    {\r\n        return left ? (ml[u] >= 0) : (mr[u] >= 0);\r\n    }\r\n\r\n\
    \    edge<int> &get_incident_edge(int u, bool left)\r\n    {\r\n        assert(is_covered(u,\
    \ left));\r\n        return left ? g.get_edge(ml[u]) : g.get_edge(mr[u]);\r\n\
    \    }\r\n\r\n    int match_to(int u, bool left)\r\n    {\r\n        if(!is_covered(u,\
    \ left))\r\n        {\r\n            return -1;\r\n        }\r\n        return\
    \ left ? g.get_edge(ml[u]).to - p : g.get_edge(mr[u]).from;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/matching/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2022-12-12 07:03:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/matching/bipartite_matching.hpp
layout: document
redirect_from:
- /library/lib/graph/matching/bipartite_matching.hpp
- /library/lib/graph/matching/bipartite_matching.hpp.html
title: lib/graph/matching/bipartite_matching.hpp
---
