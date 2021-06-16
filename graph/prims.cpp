/* Prims Minimum Spanning Tree Calculation using Prims
 * This works similar to dijkstra
 * VE and with fin heap VlogV
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;


void prims(vector<vector<int>>& g, vector<int>& parent)
{
    int V = g.size();
    vector<int> key(V, INT_MAX);
    vector<int> p(V, 0);
    key[0] = 0;

    int s = 0;
    parent[s] = -1;

    auto find_min = [&]() -> int {
        int m(INT_MAX);
        int j = -1;

        for (int i = 0; i < V; i++) {
            if (p[i]) continue;
            if (key[i] < m) {
                m = key[i];
                j = i;
            }
        }

        p[j] = true;
        assert(j != -1);
        return j;
    };

    for (int i = 1; i <= V-1; i++) { // V-1 more vertices to select
        int m = find_min();
        // relax neighbours
        for (int j = 0; j < V; j++) {
            if (g[m][j] && !p[j]) {
                if (g[m][j] < key[j]) {
                    parent[j] = m;
                    key[j] = g[m][j];
                }
            }
        }
    }
}

int main()
{
    int V = 5;
    vector<vector<int>>g { { 0, 2, 0, 6, 0 },
            { 2, 0, 3, 8, 5 },
            { 0, 3, 0, 0, 7 },
            { 6, 8, 0, 0, 9 },
            { 0, 5, 7, 9, 0 } };
    vector<int> parent(V);
    prims(g, parent);

    int w(0);
    for (int i = 1; i < V; i++) {
        cout << parent[i] << "->" << i << ": " << g[parent[i]][i] << endl;
        w += g[parent[i]][i];
    }

    cout << "min weight: " << w;
    return 0;
}
