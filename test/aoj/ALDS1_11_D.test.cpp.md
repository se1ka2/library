---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/union_find/UnionFind.hpp
    title: lib/structure/union_find/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_11_D.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <vector>\n#line 1 \"lib/structure/union_find/UnionFind.hpp\"\
    \nstruct UnionFind\r\n{\r\npublic:\r\n    UnionFind(int n) : n(n), par(n), sz(n,\
    \ 1), num_of_components(n)\r\n    {\r\n        for (int i = 0; i < n; i++)\r\n\
    \        {\r\n            par[i] = i;\r\n        }\r\n    }\r\n\r\n    int find(int\
    \ i)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        return (i == par[i])\
    \ ? i : par[i] = find(par[i]);\r\n    }\r\n\r\n    bool same(int i, int j)\r\n\
    \    {\r\n        assert(0 <= i && i < n);\r\n        assert(0 <= j && j < n);\r\
    \n        return find(i) == find(j);\r\n    }\r\n\r\n    void unite(int i, int\
    \ j)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        assert(0 <= j &&\
    \ j < n);\r\n        i = find(i), j = find(j);\r\n        if (i == j)\r\n    \
    \    {\r\n            return;\r\n        }\r\n        if (sz[i] < sz[j])\r\n \
    \       {\r\n            std::swap(i, j);\r\n        }\r\n        par[j] = i;\r\
    \n        sz[i] += sz[j];\r\n        num_of_components--;\r\n    }\r\n\r\n   \
    \ int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    int size(int i)\r\
    \n    {\r\n        assert(0 <= i && i < n);\r\n        return sz[find(i)];\r\n\
    \    }\r\n\r\n    int count()\r\n    {\r\n        return num_of_components;\r\n\
    \    }\r\n\r\n    bool is_root(int i)\r\n    {\r\n        assert(0 <= i && i <\
    \ n);\r\n        return i == find(i);\r\n    }\r\n\r\n    int operator[](int i)\r\
    \n    {\r\n        return find(i);\r\n    }\r\n\r\nprivate:\r\n    int n;\r\n\
    \    std::vector<int> par;\r\n    std::vector<int> sz;\r\n    int num_of_components;\r\
    \n};\r\n#line 7 \"test/aoj/ALDS1_11_D.test.cpp\"\nusing namespace std;\n\nint\
    \ main()\n{\n    int n, m;\n    cin >> n >> m;\n    UnionFind uf(n);\n    for(int\
    \ i = 0; i < m; i++)\n    {\n        int u, v;\n        cin >> u >> v;\n     \
    \   uf.unite(u, v);\n    }\n    int q;\n    cin >> q;\n    while(q--)\n    {\n\
    \        int u, v;\n        cin >> u >> v;\n        cout << (uf.same(u, v) ? \"\
    yes\" : \"no\") << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <vector>\n#include \"../../lib/structure/union_find/UnionFind.hpp\"\
    \nusing namespace std;\n\nint main()\n{\n    int n, m;\n    cin >> n >> m;\n \
    \   UnionFind uf(n);\n    for(int i = 0; i < m; i++)\n    {\n        int u, v;\n\
    \        cin >> u >> v;\n        uf.unite(u, v);\n    }\n    int q;\n    cin >>\
    \ q;\n    while(q--)\n    {\n        int u, v;\n        cin >> u >> v;\n     \
    \   cout << (uf.same(u, v) ? \"yes\" : \"no\") << endl;\n    }\n}\n"
  dependsOn:
  - lib/structure/union_find/UnionFind.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_11_D.test.cpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_11_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_11_D.test.cpp
- /verify/test/aoj/ALDS1_11_D.test.cpp.html
title: test/aoj/ALDS1_11_D.test.cpp
---
