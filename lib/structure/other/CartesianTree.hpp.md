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
  bundledCode: "#line 1 \"lib/structure/other/CartesianTree.hpp\"\ntemplate <typename\
    \ T>\nstruct CartesianTree\n{\npublic:\n    std::vector<int> par;\n    std::vector<int>\
    \ lc, rc;\n    std::vector<int> lp, rp;\n\n    CartesianTree() {}\n\n    CartesianTree(std::vector<T>\
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
    \        }\n        }\n\n        auto dfs = [&](auto self, int i) -> void\n  \
    \      {\n            if (lc[i] >= 0)\n            {\n                lp[lc[i]]\
    \ = lp[i];\n                rp[lc[i]] = i;\n                self(self, lc[i]);\n\
    \            }\n            if (rc[i] >= 0)\n            {\n                lp[rc[i]]\
    \ = i;\n                rp[rc[i]] = rp[i];\n                self(self, rc[i]);\n\
    \            }\n        };\n\n        dfs(dfs, r);\n    }\n\n    int root()\n\
    \    {\n        return r;\n    }\n\n    int size()\n    {\n        return n;\n\
    \    }\n\nprivate:\n    int n;\n    int r;\n};\n"
  code: "template <typename T>\nstruct CartesianTree\n{\npublic:\n    std::vector<int>\
    \ par;\n    std::vector<int> lc, rc;\n    std::vector<int> lp, rp;\n\n    CartesianTree()\
    \ {}\n\n    CartesianTree(std::vector<T> &a) : n(a.size()), par(a.size()), lc(a.size(),\
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
    \            {\n                r = i;\n            }\n        }\n\n        auto\
    \ dfs = [&](auto self, int i) -> void\n        {\n            if (lc[i] >= 0)\n\
    \            {\n                lp[lc[i]] = lp[i];\n                rp[lc[i]]\
    \ = i;\n                self(self, lc[i]);\n            }\n            if (rc[i]\
    \ >= 0)\n            {\n                lp[rc[i]] = i;\n                rp[rc[i]]\
    \ = rp[i];\n                self(self, rc[i]);\n            }\n        };\n\n\
    \        dfs(dfs, r);\n    }\n\n    int root()\n    {\n        return r;\n   \
    \ }\n\n    int size()\n    {\n        return n;\n    }\n\nprivate:\n    int n;\n\
    \    int r;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/other/CartesianTree.hpp
  requiredBy: []
  timestamp: '2023-03-08 20:02:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/cartesian_tree.test.cpp
documentation_of: lib/structure/other/CartesianTree.hpp
layout: document
redirect_from:
- /library/lib/structure/other/CartesianTree.hpp
- /library/lib/structure/other/CartesianTree.hpp.html
title: lib/structure/other/CartesianTree.hpp
---
