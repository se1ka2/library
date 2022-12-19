template <typename T>
struct cartesian_tree
{
public:
    std::vector<int> par;
    std::vector<int> lc, rc;
    std::vector<int> lp, rp;

    cartesian_tree() {}

    cartesian_tree(std::vector<T> &a) : n(a.size()), par(a.size()), lc(a.size(), -1), rc(a.size(), -1), lp(a.size(), -1), rp(a.size(), a.size())
    {
        std::stack<int> st;
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
        for (int i = 0; i < n; i++)
        {
            if (par[i] > i)
            {
                lc[par[i]] = i;
            }
            else if (par[i] < i)
            {
                rc[par[i]] = i;
            }
            else
            {
                r = i;
            }
        }
        dfs(r);
    }

    int root()
    {
        return r;
    }

private:
    int n;
    int r;

    void dfs(int i)
    {
        if (lc[i] >= 0)
        {
            lp[lc[i]] = lp[i];
            rp[lc[i]] = i;
            dfs(lc[i]);
        }
        if (rc[i] >= 0)
        {
            lp[rc[i]] = i;
            rp[rc[i]] = rp[i];
            dfs(rc[i]);
        }
    }
};
