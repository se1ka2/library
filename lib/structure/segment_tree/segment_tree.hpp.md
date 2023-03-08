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
  bundledCode: "#line 1 \"lib/structure/segment_tree/segment_tree.hpp\"\ntemplate\
    \ <typename M>\nstruct segment_tree\n{\n    using S = typename M::value_type;\n\
    \npublic:\n    segment_tree() {}\n\n    segment_tree(int n) : n(n)\n    {\n  \
    \      for (sz = 1; sz <= n; sz <<= 1)\n        {\n        }\n        dat.assign(sz\
    \ * 2, M::e());\n    }\n\n    segment_tree(std::vector<S> &a) : n(a.size())\n\
    \    {\n        for (sz = 1; sz <= n; sz <<= 1)\n        {\n        }\n      \
    \  dat.resize(sz * 2);\n        for (int i = 0; i < n; i++)\n        {\n     \
    \       dat[i + sz] = a[i];\n        }\n        for(int i = sz - 1; i > 0; i--)\n\
    \        {\n            dat[i] = M::op(dat[i * 2], dat[i * 2 + 1]);\n        }\n\
    \    }\n\n    void update(int i, S x)\n    {\n        assert(i >= 0 && i < sz);\n\
    \        int k = i + sz;\n        dat[k] = x;\n        while (k >>= 1)\n     \
    \   {\n            dat[k] = M::op(dat[k * 2], dat[k * 2 + 1]);\n        }\n  \
    \  }\n\n    S query(int l, int r)\n    {\n        assert(l >= 0 && l <= r && r\
    \ <= n);\n        l += sz, r += sz;\n        S x = M::e(), y = M::e();\n     \
    \   for (; l != r; l >>= 1, r >>= 1)\n        {\n            if (l % 2)\n    \
    \        {\n                x = M::op(x, dat[l++]);\n            }\n         \
    \   if (r % 2)\n            {\n                y = M::op(dat[--r], y);\n     \
    \       }\n        }\n        return M::op(x, y);\n    }\n\n    S operator[](const\
    \ int i) const\n    {\n        return dat[i + sz];\n    }\n\nprivate:\n    int\
    \ n, sz;\n    std::vector<S> dat;\n};\n"
  code: "template <typename M>\nstruct segment_tree\n{\n    using S = typename M::value_type;\n\
    \npublic:\n    segment_tree() {}\n\n    segment_tree(int n) : n(n)\n    {\n  \
    \      for (sz = 1; sz <= n; sz <<= 1)\n        {\n        }\n        dat.assign(sz\
    \ * 2, M::e());\n    }\n\n    segment_tree(std::vector<S> &a) : n(a.size())\n\
    \    {\n        for (sz = 1; sz <= n; sz <<= 1)\n        {\n        }\n      \
    \  dat.resize(sz * 2);\n        for (int i = 0; i < n; i++)\n        {\n     \
    \       dat[i + sz] = a[i];\n        }\n        for(int i = sz - 1; i > 0; i--)\n\
    \        {\n            dat[i] = M::op(dat[i * 2], dat[i * 2 + 1]);\n        }\n\
    \    }\n\n    void update(int i, S x)\n    {\n        assert(i >= 0 && i < sz);\n\
    \        int k = i + sz;\n        dat[k] = x;\n        while (k >>= 1)\n     \
    \   {\n            dat[k] = M::op(dat[k * 2], dat[k * 2 + 1]);\n        }\n  \
    \  }\n\n    S query(int l, int r)\n    {\n        assert(l >= 0 && l <= r && r\
    \ <= n);\n        l += sz, r += sz;\n        S x = M::e(), y = M::e();\n     \
    \   for (; l != r; l >>= 1, r >>= 1)\n        {\n            if (l % 2)\n    \
    \        {\n                x = M::op(x, dat[l++]);\n            }\n         \
    \   if (r % 2)\n            {\n                y = M::op(dat[--r], y);\n     \
    \       }\n        }\n        return M::op(x, y);\n    }\n\n    S operator[](const\
    \ int i) const\n    {\n        return dat[i + sz];\n    }\n\nprivate:\n    int\
    \ n, sz;\n    std::vector<S> dat;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/segment_tree/segment_tree.hpp
  requiredBy: []
  timestamp: '2023-01-28 03:21:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/structure/segment_tree/segment_tree.hpp
layout: document
redirect_from:
- /library/lib/structure/segment_tree/segment_tree.hpp
- /library/lib/structure/segment_tree/segment_tree.hpp.html
title: lib/structure/segment_tree/segment_tree.hpp
---
