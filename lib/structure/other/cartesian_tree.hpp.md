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
    \ T>\nstruct cartesian_tree\n{\npublic:\n    std::vector<int> par;\n    std::vector<int>\
    \ lc, rc;\n    std::vector<int> lp, rp;\n\n    cartesian_tree() {}\n\n    cartesian_tree(std::vector<T>\
    \ &a) : n(a.size()), par(a.size()), lc(a.size(), -1), rc(a.size(), -1), lp(a.size(),\
    \ -1), rp(a.size(), a.size())\n    {\n        std::stack<int> st;\n        for\
    \ (int i = 0; i < n; i++)\n        {\n            par[i] = i;\n            int\
    \ last = -1;\n            while (st.size())\n            {\n                if\
    \ (a[i] >= a[st.top()])\n                {\n                    par[i] = st.top();\n\
    \                    break;\n                }\n                last = st.top();\n\
    \                st.pop();\n            }\n            if (last >= 0)\n      \
    \      {\n                par[last] = i;\n            }\n            st.push(i);\n\
    \        }\n        for (int i = 0; i < n; i++)\n        {\n            if (par[i]\
    \ > i)\n            {\n                lc[par[i]] = i;\n            }\n      \
    \      else if (par[i] < i)\n            {\n                rc[par[i]] = i;\n\
    \            }\n            else\n            {\n                r = i;\n    \
    \        }\n        }\n        dfs(r);\n    }\n\n    int root()\n    {\n     \
    \   return r;\n    }\n\nprivate:\n    int n;\n    int r;\n\n    void dfs(int i)\n\
    \    {\n        if (lc[i] >= 0)\n        {\n            lp[lc[i]] = lp[i];\n \
    \           rp[lc[i]] = i;\n            dfs(lc[i]);\n        }\n        if (rc[i]\
    \ >= 0)\n        {\n            lp[rc[i]] = i;\n            rp[rc[i]] = rp[i];\n\
    \            dfs(rc[i]);\n        }\n    }\n};\n"
  code: "template <typename T>\nstruct cartesian_tree\n{\npublic:\n    std::vector<int>\
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
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/other/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2022-12-20 06:00:30+09:00'
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
