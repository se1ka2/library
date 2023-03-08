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
  bundledCode: "#line 1 \"lib/math/Prime.hpp\"\nstruct PrimeStructure\n{\npublic:\n\
    \    PrimeStructure(int max_n) : max_n(max_n), largest_prime_factor(max_n + 1,\
    \ -1)\n    {\n        for (int i = 2; i <= max_n; i++)\n        {\n          \
    \  if (largest_prime_factor[i] == -1)\n            {\n                prime_list.push_back(i);\n\
    \                for (int j = i; j <= max_n; j += i)\n                {\n    \
    \                largest_prime_factor[j] = i;\n                }\n           \
    \ }\n        }\n    }\n\n    bool is_prime(int n)\n    {\n        assert(n >=\
    \ 0 && n <= max_n);\n        return largest_prime_factor[n] == n;\n    }\n\n \
    \   std::vector<int> factorize(int n)\n    {\n        assert(n >= 1 && n <= max_n);\n\
    \        std::vector<int> res;\n        while (n > 1)\n        {\n           \
    \ int p = largest_prime_factor[n];\n            res.push_back(p);\n          \
    \  n /= p;\n        }\n        return res;\n    }\n\n    int size()\n    {\n \
    \       return prime_list.size();\n    }\n\n    const int operator[](int i) const\n\
    \    {\n        assert(i < (int)prime_list.size());\n        return prime_list[i];\n\
    \    }\n\n    std::vector<int>::const_iterator begin()\n    {\n        return\
    \ prime_list.begin();\n    }\n\n    std::vector<int>::const_iterator end()\n \
    \   {\n        return prime_list.end();\n    }\n\nprivate:\n    int max_n;\n \
    \   std::vector<int> largest_prime_factor;\n    std::vector<int> prime_list;\n\
    };\n"
  code: "struct PrimeStructure\n{\npublic:\n    PrimeStructure(int max_n) : max_n(max_n),\
    \ largest_prime_factor(max_n + 1, -1)\n    {\n        for (int i = 2; i <= max_n;\
    \ i++)\n        {\n            if (largest_prime_factor[i] == -1)\n          \
    \  {\n                prime_list.push_back(i);\n                for (int j = i;\
    \ j <= max_n; j += i)\n                {\n                    largest_prime_factor[j]\
    \ = i;\n                }\n            }\n        }\n    }\n\n    bool is_prime(int\
    \ n)\n    {\n        assert(n >= 0 && n <= max_n);\n        return largest_prime_factor[n]\
    \ == n;\n    }\n\n    std::vector<int> factorize(int n)\n    {\n        assert(n\
    \ >= 1 && n <= max_n);\n        std::vector<int> res;\n        while (n > 1)\n\
    \        {\n            int p = largest_prime_factor[n];\n            res.push_back(p);\n\
    \            n /= p;\n        }\n        return res;\n    }\n\n    int size()\n\
    \    {\n        return prime_list.size();\n    }\n\n    const int operator[](int\
    \ i) const\n    {\n        assert(i < (int)prime_list.size());\n        return\
    \ prime_list[i];\n    }\n\n    std::vector<int>::const_iterator begin()\n    {\n\
    \        return prime_list.begin();\n    }\n\n    std::vector<int>::const_iterator\
    \ end()\n    {\n        return prime_list.end();\n    }\n\nprivate:\n    int max_n;\n\
    \    std::vector<int> largest_prime_factor;\n    std::vector<int> prime_list;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Prime.hpp
  requiredBy: []
  timestamp: '2023-03-08 19:39:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/Prime.hpp
layout: document
redirect_from:
- /library/lib/math/Prime.hpp
- /library/lib/math/Prime.hpp.html
title: lib/math/Prime.hpp
---
