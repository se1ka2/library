template <typename T>
struct BinaryIndexedTree
{
    int n;
    std::vector<T> bit;

    BinaryIndexedTree() {}

    BinaryIndexedTree(int n) : n(n)
    {
        bit.resize(n + 1);
    }

    T sum(int i) // sum of [0, i)
    {
        T res = 0;
        while (i)
        {
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }

    T sum(int l, int r)
    {
        return sum(r) - sum(l);
    }

    void add(int i, T x)
    {
        i++;
        while (i <= n)
        {
            bit[i] += x;
            i += (i & -i);
        }
    }
};
