---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/union_find/union_find.hpp
    title: lib/structure/union_find/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library_checker/unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <iostream>\n#include\
    \ <cassert>\n#include <vector>\n#line 1 \"lib/structure/union_find/union_find.hpp\"\
    \nstruct union_find\r\n{\r\n    int n;\r\n    std::vector<int> par;\r\n    std::vector<int>\
    \ sz;\r\n    int num_of_components;\r\n\r\n    union_find(int n) : n(n)\r\n  \
    \  {\r\n        par.resize(n);\r\n        sz.resize(n);\r\n        for (int i\
    \ = 0; i < n; i++)\r\n        {\r\n            par[i] = i;\r\n            sz[i]\
    \ = 1;\r\n        }\r\n        num_of_components = n;\r\n    }\r\n\r\n    int\
    \ find(int i)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        return (i\
    \ == par[i]) ? i : par[i] = find(par[i]);\r\n    }\r\n\r\n    bool same(int i,\
    \ int j)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        assert(0 <= j\
    \ && j < n);\r\n        return find(i) == find(j);\r\n    }\r\n\r\n    void unite(int\
    \ i, int j)\r\n    {\r\n        assert(0 <= i && i < n);\r\n        assert(0 <=\
    \ j && j < n);\r\n        i = find(i), j = find(j);\r\n        if (i == j)\r\n\
    \        {\r\n            return;\r\n        }\r\n        if (sz[i] < sz[j])\r\
    \n        {\r\n            std::swap(i, j);\r\n        }\r\n        par[j] = i;\r\
    \n        sz[i] += sz[j];\r\n        num_of_components--;\r\n    }\r\n\r\n   \
    \ int size()\r\n    {\r\n        return n;\r\n    }\r\n\r\n    int size(int i)\r\
    \n    {\r\n        assert(0 <= i && i < n);\r\n        return sz[find(i)];\r\n\
    \    }\r\n\r\n    int count()\r\n    {\r\n        return num_of_components;\r\n\
    \    }\r\n\r\n    bool is_root(int i)\r\n    {\r\n        assert(0 <= i && i <\
    \ n);\r\n        return i == find(i);\r\n    }\r\n\r\n    int operator[](int i)\r\
    \n    {\r\n        return find(i);\r\n    }\r\n};\r\n#line 7 \"test/library_checker/unionfind.test.cpp\"\
    \nusing namespace std;\n\nint main()\n{\n    int n, q;\n    cin >> n >> q;\n \
    \   union_find uf(n);\n    while(q--)\n    {\n        int t, u, v;\n        cin\
    \ >> t >> u >> v;\n        if(t)\n        {\n            cout << (int)(uf.same(u,\
    \ v)) << endl;\n        }\n        else\n        {\n            uf.unite(u, v);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include <cassert>\n#include <vector>\n#include \"../../lib/structure/union_find/union_find.hpp\"\
    \nusing namespace std;\n\nint main()\n{\n    int n, q;\n    cin >> n >> q;\n \
    \   union_find uf(n);\n    while(q--)\n    {\n        int t, u, v;\n        cin\
    \ >> t >> u >> v;\n        if(t)\n        {\n            cout << (int)(uf.same(u,\
    \ v)) << endl;\n        }\n        else\n        {\n            uf.unite(u, v);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - lib/structure/union_find/union_find.hpp
  isVerificationFile: true
  path: test/library_checker/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-12-10 07:58:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/unionfind.test.cpp
- /verify/test/library_checker/unionfind.test.cpp.html
title: test/library_checker/unionfind.test.cpp
---
