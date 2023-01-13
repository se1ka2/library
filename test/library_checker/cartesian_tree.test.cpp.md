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
    #include <cassert>\n#include <vector>\n#include <stack>\n#line 1 \"lib/structure/other/cartesian_tree.hpp\"\
    \ntemplate <typename T>\nstruct cartesian_tree\n{\npublic:\n    std::vector<int>\
    \ par;\n    std::vector<int> lc, rc;\n    std::vector<int> lp, rp;\n\n    cartesian_tree()\
    \ {}\n\n    cartesian_tree(std::vector<T> &a) : n(a.size()), par(a.size()), lc(a.size(),\
    \ -1), rc(a.size(), -1), lp(a.size(), -1), rp(a.size(), a.size())\n    {\n   \
    \     std::stack<int> st;\n        for (int i = 0; i < n; i++)\n        {\n  \
    \          par[i] = i;\n            int last = -1;\n            while (st.size())\n\
    \            {\n                if (a[i] >= a[st.top()])\n                {\n\
    \                    par[i] = st.top();\n                    break;\n        \
    \        }\n                last = st.top();\n                st.pop();\n    \
    \        }\n            if (last >= 0)\n            {\n                par[last]\
    \ = i;\n            }\n            st.push(i);\n        }\n        for (int i\
    \ = 0; i < n; i++)\n        {\n            if (par[i] > i)\n            {\n  \
    \              lc[par[i]] = i;\n            }\n            else if (par[i] < i)\n\
    \            {\n                rc[par[i]] = i;\n            }\n            else\n\
    \            {\n                r = i;\n            }\n        }\n        dfs(r);\n\
    \    }\n\n    int root()\n    {\n        return r;\n    }\n\nprivate:\n    int\
    \ n;\n    int r;\n\n    void dfs(int i)\n    {\n        if (lc[i] >= 0)\n    \
    \    {\n            lp[lc[i]] = lp[i];\n            rp[lc[i]] = i;\n         \
    \   dfs(lc[i]);\n        }\n        if (rc[i] >= 0)\n        {\n            lp[rc[i]]\
    \ = i;\n            rp[rc[i]] = rp[i];\n            dfs(rc[i]);\n        }\n \
    \   }\n};\n#line 8 \"test/library_checker/cartesian_tree.test.cpp\"\nusing namespace\
    \ std;\n\nint main()\n{\n    int n;\n    cin >> n;\n    vector<int> a(n);\n  \
    \  for (int i = 0; i < n; i++)\n    {\n        cin >> a[i];\n    }\n    cartesian_tree\
    \ ct(a);\n    for (int i = 0; i < n; i++)\n    {\n        cout << ct.par[i] <<\
    \ \" \";\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ <iostream>\n#include <cassert>\n#include <vector>\n#include <stack>\n#include\
    \ \"../../lib/structure/other/cartesian_tree.hpp\"\nusing namespace std;\n\nint\
    \ main()\n{\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for (int i\
    \ = 0; i < n; i++)\n    {\n        cin >> a[i];\n    }\n    cartesian_tree ct(a);\n\
    \    for (int i = 0; i < n; i++)\n    {\n        cout << ct.par[i] << \" \";\n\
    \    }\n    cout << endl;\n}\n"
  dependsOn:
  - lib/structure/other/cartesian_tree.hpp
  isVerificationFile: true
  path: test/library_checker/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2023-01-14 04:14:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/cartesian_tree.test.cpp
- /verify/test/library_checker/cartesian_tree.test.cpp.html
title: test/library_checker/cartesian_tree.test.cpp
---
