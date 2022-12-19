---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/cartesian_tree.test.cpp
    title: test/library_checker/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/structure/other/cartesian_tree.hpp\"\ntemplate <typename\
    \ T>\nstd::vector<int> cartesian_tree(std::vector<T> &a)\n{\n    int n = a.size();\n\
    \    std::stack<T> st;\n    std::vector<int> par(n);\n    for (int i = 0; i <\
    \ n; i++)\n    {\n        par[i] = i;\n        int last = -1;\n        while (st.size())\n\
    \        {\n            if (a[i] >= a[st.top()])\n            {\n            \
    \    par[i] = st.top();\n                break;\n            }\n            last\
    \ = st.top();\n            st.pop();\n        }\n        if (last >= 0)\n    \
    \    {\n            par[last] = i;\n        }\n        st.push(i);\n    }\n  \
    \  return par;\n}\n"
  code: "template <typename T>\nstd::vector<int> cartesian_tree(std::vector<T> &a)\n\
    {\n    int n = a.size();\n    std::stack<T> st;\n    std::vector<int> par(n);\n\
    \    for (int i = 0; i < n; i++)\n    {\n        par[i] = i;\n        int last\
    \ = -1;\n        while (st.size())\n        {\n            if (a[i] >= a[st.top()])\n\
    \            {\n                par[i] = st.top();\n                break;\n \
    \           }\n            last = st.top();\n            st.pop();\n        }\n\
    \        if (last >= 0)\n        {\n            par[last] = i;\n        }\n  \
    \      st.push(i);\n    }\n    return par;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/other/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2022-12-20 03:27:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/cartesian_tree.test.cpp
documentation_of: lib/structure/other/cartesian_tree.hpp
layout: document
redirect_from:
- /library/lib/structure/other/cartesian_tree.hpp
- /library/lib/structure/other/cartesian_tree.hpp.html
title: lib/structure/other/cartesian_tree.hpp
---
