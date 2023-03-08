---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/structure/other/BinaryIndexedTree.hpp
    title: lib/structure/other/BinaryIndexedTree.hpp
  - icon: ':x:'
    path: lib/structure/other/inversion_number.hpp
    title: lib/structure/other/inversion_number.hpp
  - icon: ':x:'
    path: lib/utility/compression.hpp
    title: lib/utility/compression.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_5_D.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <cassert>\n#include <vector>\n\
    #line 1 \"lib/structure/other/BinaryIndexedTree.hpp\"\ntemplate <typename T>\n\
    struct BinaryIndexedTree\n{\n    int n;\n    std::vector<T> bit;\n\n    BinaryIndexedTree()\
    \ {}\n\n    BinaryIndexedTree(int n) : n(n)\n    {\n        bit.resize(n + 1);\n\
    \    }\n\n    T sum(int i) // sum of [0, i)\n    {\n        T res = 0;\n     \
    \   while (i)\n        {\n            res += bit[i];\n            i -= (i & -i);\n\
    \        }\n        return res;\n    }\n\n    T sum(int l, int r)\n    {\n   \
    \     return sum(r) - sum(l);\n    }\n\n    void add(int i, T x)\n    {\n    \
    \    i++;\n        while (i <= n)\n        {\n            bit[i] += x;\n     \
    \       i += (i & -i);\n        }\n    }\n};\n#line 1 \"lib/utility/compression.hpp\"\
    \ntemplate <typename T>\nstd::vector<int> compression(std::vector<T> &a, bool\
    \ same_to_same)\n{\n    int n = a.size();\n    std::vector<std::pair<T, int>>\
    \ p(n);\n    for (int i = 0; i < n; i++)\n    {\n        p[i] = std::pair<T, int>(a[i],\
    \ i);\n    }\n    std::sort(p.begin(), p.end());\n    std::vector<int> res(n);\n\
    \    int c = 0;\n    for (int i = 0; i < n; i++)\n    {\n        c += (i && (!same_to_same\
    \ || p[i].first != p[i - 1].first));\n        res[p[i].second] = c;\n    }\n \
    \   return res;\n}\n#line 1 \"lib/structure/other/inversion_number.hpp\"\nlong\
    \ long inversion_number(std::vector<int> &a)\n{\n    int n = a.size();\n    std::vector<int>\
    \ q = compression(a, true);\n    int k = q.back() + 1;\n    BinaryIndexedTree<int>\
    \ bit(k);\n    long long res = 0;\n    for (int i = n - 1; i >= 0; i--)\n    {\n\
    \        res += bit.sum(q[i]);\n        bit.add(q[i], 1);\n    }\n    return res;\n\
    }\n#line 10 \"test/aoj/ALDS1_5_D.test.cpp\"\nusing namespace std;\n\nint main()\n\
    {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for(int i = 0; i < n;\
    \ i++)\n    {\n        cin >> a[i];\n    }\n    cout << inversion_number(a) <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <cassert>\n#include <vector>\n\
    #include \"../../lib/structure/other/BinaryIndexedTree.hpp\"\n#include \"../../lib/utility/compression.hpp\"\
    \n#include \"../../lib/structure/other/inversion_number.hpp\"\nusing namespace\
    \ std;\n\nint main()\n{\n    int n;\n    cin >> n;\n    vector<int> a(n);\n  \
    \  for(int i = 0; i < n; i++)\n    {\n        cin >> a[i];\n    }\n    cout <<\
    \ inversion_number(a) << endl;\n}\n"
  dependsOn:
  - lib/structure/other/BinaryIndexedTree.hpp
  - lib/utility/compression.hpp
  - lib/structure/other/inversion_number.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_5_D.test.cpp
- /verify/test/aoj/ALDS1_5_D.test.cpp.html
title: test/aoj/ALDS1_5_D.test.cpp
---
