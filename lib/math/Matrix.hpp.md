---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/no_2156.test.cpp
    title: test/yukicoder/no_2156.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/Matrix.hpp\"\ntemplate <typename T>\nstruct Matrix\n\
    {\npublic:\n    Matrix() {}\n\n    Matrix(int n, int m) : n(n), m(m), a(n, std::vector<T>(m))\
    \ {}\n\n    Matrix(int n) : n(n), m(n), a(n, std::vector<T>(n)) {}\n\n    static\
    \ Matrix<T> I(int n)\n    {\n        Matrix<T> res(n);\n        for (int i = 0;\
    \ i < n; i++)\n        {\n            res[i][i] = 1;\n        }\n        return\
    \ res;\n    }\n\n    Matrix<T> &operator+=(const Matrix<T> &b)\n    {\n      \
    \  for (int i = 0; i < n; i++)\n        {\n            for (int j = 0; j < m;\
    \ j++)\n            {\n                (*this)[i][j] += b[i][j];\n           \
    \ }\n        }\n        return *this;\n    }\n\n    Matrix<T> &operator-=(const\
    \ Matrix<T> &b)\n    {\n        for (int i = 0; i < n; i++)\n        {\n     \
    \       for (int j = 0; j < m; j++)\n            {\n                (*this)[i][j]\
    \ -= b[i][j];\n            }\n        }\n        return *this;\n    }\n\n    Matrix<T>\
    \ &operator*=(const Matrix<T> &b)\n    {\n        assert(m == b.n);\n        std::vector<std::vector<T>>\
    \ c(n, std::vector<T>(b.m));\n        for (int i = 0; i < n; i++)\n        {\n\
    \            for (int j = 0; j < b.m; j++)\n            {\n                for\
    \ (int k = 0; k < m; k++)\n                {\n                    c[i][j] += (*this)[i][k]\
    \ * b[k][j];\n                }\n            }\n        }\n        m = b.m;\n\
    \        a.swap(c);\n        return *this;\n    }\n\n    Matrix<T> &operator^=(long\
    \ long k)\n    {\n        Matrix<T> b = Matrix<T>::I(n);\n        while (k)\n\
    \        {\n            if (k & 1)\n            {\n                b *= *this;\n\
    \            }\n            *this *= *this;\n            k >>= 1;\n        }\n\
    \        a.swap(b.a);\n        return *this;\n    }\n\n    Matrix<T> operator+(const\
    \ Matrix<T> &a)\n    {\n        return (Matrix<T>(*this) += a);\n    }\n\n   \
    \ Matrix<T> operator-(const Matrix<T> &a)\n    {\n        return (Matrix<T>(*this)\
    \ -= a);\n    }\n\n    Matrix<T> operator*(const Matrix<T> &a)\n    {\n      \
    \  return (Matrix<T>(*this) *= a);\n    }\n\n    Matrix<T> operator^(const Matrix<T>\
    \ &a)\n    {\n        return (Matrix<T>(*this) ^= a);\n    }\n\n    const std::vector<T>\
    \ &operator[](int i) const\n    {\n        return a[i];\n    }\n\n    std::vector<T>\
    \ &operator[](int i)\n    {\n        return a[i];\n    }\n\nprivate:\n    int\
    \ n, m;\n    std::vector<std::vector<T>> a;\n};\n"
  code: "template <typename T>\nstruct Matrix\n{\npublic:\n    Matrix() {}\n\n   \
    \ Matrix(int n, int m) : n(n), m(m), a(n, std::vector<T>(m)) {}\n\n    Matrix(int\
    \ n) : n(n), m(n), a(n, std::vector<T>(n)) {}\n\n    static Matrix<T> I(int n)\n\
    \    {\n        Matrix<T> res(n);\n        for (int i = 0; i < n; i++)\n     \
    \   {\n            res[i][i] = 1;\n        }\n        return res;\n    }\n\n \
    \   Matrix<T> &operator+=(const Matrix<T> &b)\n    {\n        for (int i = 0;\
    \ i < n; i++)\n        {\n            for (int j = 0; j < m; j++)\n          \
    \  {\n                (*this)[i][j] += b[i][j];\n            }\n        }\n  \
    \      return *this;\n    }\n\n    Matrix<T> &operator-=(const Matrix<T> &b)\n\
    \    {\n        for (int i = 0; i < n; i++)\n        {\n            for (int j\
    \ = 0; j < m; j++)\n            {\n                (*this)[i][j] -= b[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix<T> &operator*=(const\
    \ Matrix<T> &b)\n    {\n        assert(m == b.n);\n        std::vector<std::vector<T>>\
    \ c(n, std::vector<T>(b.m));\n        for (int i = 0; i < n; i++)\n        {\n\
    \            for (int j = 0; j < b.m; j++)\n            {\n                for\
    \ (int k = 0; k < m; k++)\n                {\n                    c[i][j] += (*this)[i][k]\
    \ * b[k][j];\n                }\n            }\n        }\n        m = b.m;\n\
    \        a.swap(c);\n        return *this;\n    }\n\n    Matrix<T> &operator^=(long\
    \ long k)\n    {\n        Matrix<T> b = Matrix<T>::I(n);\n        while (k)\n\
    \        {\n            if (k & 1)\n            {\n                b *= *this;\n\
    \            }\n            *this *= *this;\n            k >>= 1;\n        }\n\
    \        a.swap(b.a);\n        return *this;\n    }\n\n    Matrix<T> operator+(const\
    \ Matrix<T> &a)\n    {\n        return (Matrix<T>(*this) += a);\n    }\n\n   \
    \ Matrix<T> operator-(const Matrix<T> &a)\n    {\n        return (Matrix<T>(*this)\
    \ -= a);\n    }\n\n    Matrix<T> operator*(const Matrix<T> &a)\n    {\n      \
    \  return (Matrix<T>(*this) *= a);\n    }\n\n    Matrix<T> operator^(const Matrix<T>\
    \ &a)\n    {\n        return (Matrix<T>(*this) ^= a);\n    }\n\n    const std::vector<T>\
    \ &operator[](int i) const\n    {\n        return a[i];\n    }\n\n    std::vector<T>\
    \ &operator[](int i)\n    {\n        return a[i];\n    }\n\nprivate:\n    int\
    \ n, m;\n    std::vector<std::vector<T>> a;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Matrix.hpp
  requiredBy: []
  timestamp: '2023-03-08 19:41:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/no_2156.test.cpp
documentation_of: lib/math/Matrix.hpp
layout: document
redirect_from:
- /library/lib/math/Matrix.hpp
- /library/lib/math/Matrix.hpp.html
title: lib/math/Matrix.hpp
---
