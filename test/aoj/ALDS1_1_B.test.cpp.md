---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/gcd.hpp
    title: lib/math/gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_1_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\
    \n\n#include <iostream>\n#line 1 \"lib/math/gcd.hpp\"\nlong long gcd(long long\
    \ n, long long m)\n{\n    return (m == 0 ? n : gcd(m, n % m));\n}\n#line 5 \"\
    test/aoj/ALDS1_1_B.test.cpp\"\nusing namespace std;\n\nint main()\n{\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << gcd(a, b) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\
    \n\n#include <iostream>\n#include \"../../lib/math/gcd.hpp\"\nusing namespace\
    \ std;\n\nint main()\n{\n    int a, b;\n    cin >> a >> b;\n    cout << gcd(a,\
    \ b) << endl;\n}\n"
  dependsOn:
  - lib/math/gcd.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-09 00:15:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_1_B.test.cpp
- /verify/test/aoj/ALDS1_1_B.test.cpp.html
title: test/aoj/ALDS1_1_B.test.cpp
---
