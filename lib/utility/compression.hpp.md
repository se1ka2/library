---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_5_D.test.cpp
    title: test/aoj/ALDS1_5_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/utility/compression.hpp\"\ntemplate <typename T>\nstd::vector<int>\
    \ compression(std::vector<T> &a, bool same_to_same)\n{\n    int n = a.size();\n\
    \    std::vector<std::pair<T, int>> p(n);\n    for (int i = 0; i < n; i++)\n \
    \   {\n        p[i] = std::pair<T, int>(a[i], i);\n    }\n    std::sort(p.begin(),\
    \ p.end());\n    std::vector<int> res(n);\n    int c = 0;\n    for (int i = 0;\
    \ i < n; i++)\n    {\n        c += (i && (!same_to_same || p[i].first != p[i -\
    \ 1].first));\n        res[p[i].second] = c;\n    }\n    return res;\n}\n"
  code: "template <typename T>\nstd::vector<int> compression(std::vector<T> &a, bool\
    \ same_to_same)\n{\n    int n = a.size();\n    std::vector<std::pair<T, int>>\
    \ p(n);\n    for (int i = 0; i < n; i++)\n    {\n        p[i] = std::pair<T, int>(a[i],\
    \ i);\n    }\n    std::sort(p.begin(), p.end());\n    std::vector<int> res(n);\n\
    \    int c = 0;\n    for (int i = 0; i < n; i++)\n    {\n        c += (i && (!same_to_same\
    \ || p[i].first != p[i - 1].first));\n        res[p[i].second] = c;\n    }\n \
    \   return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/compression.hpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_5_D.test.cpp
documentation_of: lib/utility/compression.hpp
layout: document
redirect_from:
- /library/lib/utility/compression.hpp
- /library/lib/utility/compression.hpp.html
title: lib/utility/compression.hpp
---
