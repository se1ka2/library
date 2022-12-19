---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/other/cartesian_tree.hpp
    title: lib/structure/other/cartesian_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/library_checker/cartesian_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include <iostream>\n\
    #include <cassert>\n#include <vector>\n#include <stack>\nusing namespace std;\n\
    \n#line 1 \"lib/structure/other/cartesian_tree.hpp\"\ntemplate <typename T>\n\
    std::vector<int> cartesian_tree(std::vector<T> &a)\n{\n    int n = a.size();\n\
    \    std::stack<T> st;\n    std::vector<int> par(n);\n    for (int i = 0; i <\
    \ n; i++)\n    {\n        par[i] = i;\n        int last = -1;\n        while (st.size())\n\
    \        {\n            if (a[i] >= a[st.top()])\n            {\n            \
    \    par[i] = st.top();\n                break;\n            }\n            last\
    \ = st.top();\n            st.pop();\n        }\n        if (last >= 0)\n    \
    \    {\n            par[last] = i;\n        }\n        st.push(i);\n    }\n  \
    \  return par;\n}\n#line 10 \"test/library_checker/cartesian_tree.test.cpp\"\n\
    \nint main()\n{\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for (int\
    \ i = 0; i < n; i++)\n    {\n        cin >> a[i];\n    }\n    vector<int> p =\
    \ cartesian_tree(a);\n    for (int i = 0; i < n; i++)\n    {\n        cout <<\
    \ p[i] << \" \";\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ <iostream>\n#include <cassert>\n#include <vector>\n#include <stack>\nusing namespace\
    \ std;\n\n#include \"../../lib/structure/other/cartesian_tree.hpp\"\n\nint main()\n\
    {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for (int i = 0; i < n;\
    \ i++)\n    {\n        cin >> a[i];\n    }\n    vector<int> p = cartesian_tree(a);\n\
    \    for (int i = 0; i < n; i++)\n    {\n        cout << p[i] << \" \";\n    }\n\
    \    cout << endl;\n}\n"
  dependsOn:
  - lib/structure/other/cartesian_tree.hpp
  isVerificationFile: true
  path: test/library_checker/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2022-12-20 03:27:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/cartesian_tree.test.cpp
- /verify/test/library_checker/cartesian_tree.test.cpp.html
title: test/library_checker/cartesian_tree.test.cpp
---
