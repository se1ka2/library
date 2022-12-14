template <typename T>
struct Matrix
{
public:
    Matrix() {}

    Matrix(int n, int m) : n(n), m(m), a(n, std::vector<T>(m)) {}

    Matrix(int n) : n(n), m(n), a(n, std::vector<T>(n)) {}

    static Matrix<T> I(int n)
    {
        Matrix<T> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i][i] = 1;
        }
        return res;
    }

    Matrix<T> &operator+=(const Matrix<T> &b)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                (*this)[i][j] += b[i][j];
            }
        }
        return *this;
    }

    Matrix<T> &operator-=(const Matrix<T> &b)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                (*this)[i][j] -= b[i][j];
            }
        }
        return *this;
    }

    Matrix<T> &operator*=(const Matrix<T> &b)
    {
        assert(m == b.n);
        std::vector<std::vector<T>> c(n, std::vector<T>(b.m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < b.m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    c[i][j] += (*this)[i][k] * b[k][j];
                }
            }
        }
        m = b.m;
        a.swap(c);
        return *this;
    }

    Matrix<T> &operator^=(long long k)
    {
        Matrix<T> b = Matrix<T>::I(n);
        while (k)
        {
            if (k & 1)
            {
                b *= *this;
            }
            *this *= *this;
            k >>= 1;
        }
        a.swap(b.a);
        return *this;
    }

    Matrix<T> operator+(const Matrix<T> &a)
    {
        return (Matrix<T>(*this) += a);
    }

    Matrix<T> operator-(const Matrix<T> &a)
    {
        return (Matrix<T>(*this) -= a);
    }

    Matrix<T> operator*(const Matrix<T> &a)
    {
        return (Matrix<T>(*this) *= a);
    }

    Matrix<T> operator^(const Matrix<T> &a)
    {
        return (Matrix<T>(*this) ^= a);
    }

    const std::vector<T> &operator[](int i) const
    {
        return a[i];
    }

    vector<T> &operator[](int i)
    {
        return a[i];
    }

private:
    int n, m;
    std::vector<std::vector<T>> a;
};
