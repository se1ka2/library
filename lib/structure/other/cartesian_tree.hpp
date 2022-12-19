template <typename T>
std::vector<int> cartesian_tree(std::vector<T> &a)
{
    int n = a.size();
    std::stack<T> st;
    std::vector<int> par(n);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        int last = -1;
        while (st.size())
        {
            if (a[i] >= a[st.top()])
            {
                par[i] = st.top();
                break;
            }
            last = st.top();
            st.pop();
        }
        if (last >= 0)
        {
            par[last] = i;
        }
        st.push(i);
    }
    return par;
}
