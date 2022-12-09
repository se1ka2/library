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
  bundledCode: "#line 1 \"lib/graph/tree/lca.hpp\"\ntemplate <typename T>\r\nstruct\
    \ lca_structure\r\n{\r\n    int n, l;\r\n    std::vector<int> dpt;\r\n    std::vector<std::vector<int>>\
    \ anc;\r\n\r\n    lca_structure() {}\r\n\r\n    lca_structure(T &t) : n(t.size()),\
    \ dpt(t.dpt)\r\n    {\r\n        for (l = 1; l <= n; l++)\r\n        {\r\n   \
    \         if ((1 << (l - 1)) >= n)\r\n            {\r\n                break;\r\
    \n            }\r\n        }\r\n        anc.assign(l, std::vector<int>(n));\r\n\
    \        for (int u = 0; u < n; u++)\r\n        {\r\n            anc[0][u] = t.par[u];\r\
    \n        }\r\n        for (int i = 1; i < l; i++)\r\n        {\r\n          \
    \  for (int u = 0; u < n; u++)\r\n            {\r\n                anc[i][u] =\
    \ (anc[i - 1][u] == -1) ? -1 : anc[i - 1][anc[i - 1][u]];\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    int ancestor(int u, int k)\r\n    {\r\n       \
    \ for (int j = 0; j < l; j++)\r\n        {\r\n            if ((k >> j) & 1)\r\n\
    \            {\r\n                u = anc[j][u];\r\n            }\r\n        \
    \    if (u == -1)\r\n            {\r\n                return u;\r\n          \
    \  }\r\n        }\r\n        return u;\r\n    }\r\n\r\n    int operator()(int\
    \ u, int v)\r\n    {\r\n        if (dpt[u] < dpt[v])\r\n        {\r\n        \
    \    std::swap(u, v);\r\n        }\r\n        u = ancestor(u, dpt[u] - dpt[v]);\r\
    \n        if (u == v)\r\n        {\r\n            return u;\r\n        }\r\n \
    \       for (int j = l - 1; j >= 0; j--)\r\n        {\r\n            if (anc[j][u]\
    \ != anc[j][v])\r\n            {\r\n                u = anc[j][u];\r\n       \
    \         v = anc[j][v];\r\n            }\r\n        }\r\n        return anc[0][u];\r\
    \n\r\n    }\r\n};\r\n"
  code: "template <typename T>\r\nstruct lca_structure\r\n{\r\n    int n, l;\r\n \
    \   std::vector<int> dpt;\r\n    std::vector<std::vector<int>> anc;\r\n\r\n  \
    \  lca_structure() {}\r\n\r\n    lca_structure(T &t) : n(t.size()), dpt(t.dpt)\r\
    \n    {\r\n        for (l = 1; l <= n; l++)\r\n        {\r\n            if ((1\
    \ << (l - 1)) >= n)\r\n            {\r\n                break;\r\n           \
    \ }\r\n        }\r\n        anc.assign(l, std::vector<int>(n));\r\n        for\
    \ (int u = 0; u < n; u++)\r\n        {\r\n            anc[0][u] = t.par[u];\r\n\
    \        }\r\n        for (int i = 1; i < l; i++)\r\n        {\r\n           \
    \ for (int u = 0; u < n; u++)\r\n            {\r\n                anc[i][u] =\
    \ (anc[i - 1][u] == -1) ? -1 : anc[i - 1][anc[i - 1][u]];\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    int ancestor(int u, int k)\r\n    {\r\n       \
    \ for (int j = 0; j < l; j++)\r\n        {\r\n            if ((k >> j) & 1)\r\n\
    \            {\r\n                u = anc[j][u];\r\n            }\r\n        \
    \    if (u == -1)\r\n            {\r\n                return u;\r\n          \
    \  }\r\n        }\r\n        return u;\r\n    }\r\n\r\n    int operator()(int\
    \ u, int v)\r\n    {\r\n        if (dpt[u] < dpt[v])\r\n        {\r\n        \
    \    std::swap(u, v);\r\n        }\r\n        u = ancestor(u, dpt[u] - dpt[v]);\r\
    \n        if (u == v)\r\n        {\r\n            return u;\r\n        }\r\n \
    \       for (int j = l - 1; j >= 0; j--)\r\n        {\r\n            if (anc[j][u]\
    \ != anc[j][v])\r\n            {\r\n                u = anc[j][u];\r\n       \
    \         v = anc[j][v];\r\n            }\r\n        }\r\n        return anc[0][u];\r\
    \n\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/tree/lca.hpp
  requiredBy: []
  timestamp: '2022-12-10 07:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/tree/lca.hpp
layout: document
redirect_from:
- /library/lib/graph/tree/lca.hpp
- /library/lib/graph/tree/lca.hpp.html
title: lib/graph/tree/lca.hpp
---
