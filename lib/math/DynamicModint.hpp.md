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
  bundledCode: "#line 1 \"lib/math/DynamicModint.hpp\"\nstruct DynamicModint\n{\n\
    \    using mint = DynamicModint;\n\npublic:\n    int val;\n\n    DynamicModint()\
    \ : val(0) {}\n\n    DynamicModint(long long v)\n    {\n        if (std::abs(v)\
    \ >= mod())\n        {\n            v %= mod();\n        }\n        if (v < 0)\n\
    \        {\n            v += mod();\n        }\n        val = v;\n    }\n\n  \
    \  static void set_mod(int m)\n    {\n        MOD = m;\n    }\n\n    mint &operator++()\n\
    \    {\n        val++;\n        if (val == mod())\n        {\n            val\
    \ = 0;\n        }\n        return *this;\n    }\n\n    mint &operator--()\n  \
    \  {\n        if (val == 0)\n        {\n            val = mod();\n        }\n\
    \        val--;\n        return *this;\n    }\n\n    mint &operator+=(const mint\
    \ &x)\n    {\n        val += x.val;\n        if (val >= mod())\n        {\n  \
    \          val -= mod();\n        }\n        return *this;\n    }\n\n    mint\
    \ &operator-=(const mint &x)\n    {\n        val -= x.val;\n        if (val <\
    \ 0)\n        {\n            val += mod();\n        }\n        return *this;\n\
    \    }\n\n    mint &operator*=(const mint &x)\n    {\n        val = (int)((long\
    \ long)val * x.val % mod());\n        return *this;\n    }\n\n    mint &operator/=(const\
    \ mint &x)\n    {\n        *this *= x.inv();\n        return *this;\n    }\n\n\
    \    mint operator-()\n    {\n        return mint() - *this;\n    }\n\n    mint\
    \ pow(long long n) const\n    {\n        mint x = 1, r = *this;\n        while\
    \ (n)\n        {\n            if (n & 1)\n            {\n                x *=\
    \ r;\n            }\n            r *= r;\n            n >>= 1;\n        }\n  \
    \      return x;\n    }\n\n    mint inv() const\n    {\n        return pow(mod()\
    \ - 2);\n    }\n\n    friend mint operator+(const mint &x, const mint &y)\n  \
    \  {\n        return mint(x) += y;\n    }\n\n    friend mint operator-(const mint\
    \ &x, const mint &y)\n    {\n        return mint(x) -= y;\n    }\n\n    friend\
    \ mint operator*(const mint &x, const mint &y)\n    {\n        return mint(x)\
    \ *= y;\n    }\n\n    friend mint operator/(const mint &x, const mint &y)\n  \
    \  {\n        return mint(x) /= y;\n    }\n\n    friend bool operator==(const\
    \ mint &x, const mint &y)\n    {\n        return x.val == y.val;\n    }\n\n  \
    \  friend bool operator!=(const mint &x, const mint &y)\n    {\n        return\
    \ x.val != y.val;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const mint &x)\n    {\n        return os << x.val;\n    }\n\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &x)\n    {\n        long long v;\n      \
    \  is >> v;\n        x = mint(v);\n        return is;\n    }\n\nprivate:\n   \
    \ static int MOD;\n    static int mod()\n    {\n        return MOD;\n    }\n};\n\
    \nint DynamicModint::MOD = 998244353;\n"
  code: "struct DynamicModint\n{\n    using mint = DynamicModint;\n\npublic:\n   \
    \ int val;\n\n    DynamicModint() : val(0) {}\n\n    DynamicModint(long long v)\n\
    \    {\n        if (std::abs(v) >= mod())\n        {\n            v %= mod();\n\
    \        }\n        if (v < 0)\n        {\n            v += mod();\n        }\n\
    \        val = v;\n    }\n\n    static void set_mod(int m)\n    {\n        MOD\
    \ = m;\n    }\n\n    mint &operator++()\n    {\n        val++;\n        if (val\
    \ == mod())\n        {\n            val = 0;\n        }\n        return *this;\n\
    \    }\n\n    mint &operator--()\n    {\n        if (val == 0)\n        {\n  \
    \          val = mod();\n        }\n        val--;\n        return *this;\n  \
    \  }\n\n    mint &operator+=(const mint &x)\n    {\n        val += x.val;\n  \
    \      if (val >= mod())\n        {\n            val -= mod();\n        }\n  \
    \      return *this;\n    }\n\n    mint &operator-=(const mint &x)\n    {\n  \
    \      val -= x.val;\n        if (val < 0)\n        {\n            val += mod();\n\
    \        }\n        return *this;\n    }\n\n    mint &operator*=(const mint &x)\n\
    \    {\n        val = (int)((long long)val * x.val % mod());\n        return *this;\n\
    \    }\n\n    mint &operator/=(const mint &x)\n    {\n        *this *= x.inv();\n\
    \        return *this;\n    }\n\n    mint operator-()\n    {\n        return mint()\
    \ - *this;\n    }\n\n    mint pow(long long n) const\n    {\n        mint x =\
    \ 1, r = *this;\n        while (n)\n        {\n            if (n & 1)\n      \
    \      {\n                x *= r;\n            }\n            r *= r;\n      \
    \      n >>= 1;\n        }\n        return x;\n    }\n\n    mint inv() const\n\
    \    {\n        return pow(mod() - 2);\n    }\n\n    friend mint operator+(const\
    \ mint &x, const mint &y)\n    {\n        return mint(x) += y;\n    }\n\n    friend\
    \ mint operator-(const mint &x, const mint &y)\n    {\n        return mint(x)\
    \ -= y;\n    }\n\n    friend mint operator*(const mint &x, const mint &y)\n  \
    \  {\n        return mint(x) *= y;\n    }\n\n    friend mint operator/(const mint\
    \ &x, const mint &y)\n    {\n        return mint(x) /= y;\n    }\n\n    friend\
    \ bool operator==(const mint &x, const mint &y)\n    {\n        return x.val ==\
    \ y.val;\n    }\n\n    friend bool operator!=(const mint &x, const mint &y)\n\
    \    {\n        return x.val != y.val;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &x)\n    {\n        return os << x.val;\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, mint &x)\n    {\n        long long\
    \ v;\n        is >> v;\n        x = mint(v);\n        return is;\n    }\n\nprivate:\n\
    \    static int MOD;\n    static int mod()\n    {\n        return MOD;\n    }\n\
    };\n\nint DynamicModint::MOD = 998244353;\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/DynamicModint.hpp
  requiredBy: []
  timestamp: '2023-03-08 19:39:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/DynamicModint.hpp
layout: document
redirect_from:
- /library/lib/math/DynamicModint.hpp
- /library/lib/math/DynamicModint.hpp.html
title: lib/math/DynamicModint.hpp
---
