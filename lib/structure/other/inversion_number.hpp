long long inversion_number(std::vector<int> &a)
{
    int n = a.size();
    std::vector<int> q = compression(a, true);
    int k = q.back() + 1;
    BinaryIndexedTree<int> bit(k);
    long long res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        res += bit.sum(q[i]);
        bit.add(q[i], 1);
    }
    return res;
}
