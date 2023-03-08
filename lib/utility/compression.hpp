template <typename T>
std::vector<int> compression(std::vector<T> &a, bool same_to_same)
{
    int n = a.size();
    std::vector<std::pair<T, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = std::pair<T, int>(a[i], i);
    }
    std::sort(p.begin(), p.end());
    std::vector<int> res(n);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        c += (i && (!same_to_same || p[i].first != p[i - 1].first));
        res[p[i].second] = c;
    }
    return res;
}
