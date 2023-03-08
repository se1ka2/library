#define PROBLEM "https://yukicoder.me/problems/no/2095"

#include <iostream>
#include <cassert>
#include <queue>
#include "../../lib/graph/Graph.hpp"
#include "../../lib/graph/shortest_path/dijkstra.hpp"
using namespace std;
typedef long long ll;

int a[1005][1005];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    Graph<ll> g(n * m + n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            g.add_directed_edge(i * m + j, i + n * m, 0);
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            g.add_directed_edge(i + n * m, (i + 1) * m + j, a[i][j] + a[i + 1][j]);
            g.add_directed_edge(i * m + j, (i + 1) * m + j, a[i + 1][j]);
        }
    }
    vector<ll> d = dijkstra(g, n * m);
    cout << d[n * m + n - 1] << endl;
}
