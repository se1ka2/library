---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_B.test.cpp
    title: test/aoj/ALDS1_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/gcd.hpp\"\nlong long gcd(long long n, long long\
    \ m)\n{\n    return (m == 0 ? n : gcd(m, n % m));\n}\n"
  code: "long long gcd(long long n, long long m)\n{\n    return (m == 0 ? n : gcd(m,\
    \ n % m));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/gcd.hpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_B.test.cpp
documentation_of: lib/math/gcd.hpp
layout: document
redirect_from:
- /library/lib/math/gcd.hpp
- /library/lib/math/gcd.hpp.html
title: lib/math/gcd.hpp
---
