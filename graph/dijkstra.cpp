#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

void dijkstra(int i, vector<vector<int>>& g, vector<int>& sp)
{
    int V = sp.size();
    sp[0] = 0;
    bool p[V] = {0};
    
    auto find_min = [&]() -> int {
        int m(INT_MAX);
        int j(-1);
        for (int i = 0; i < V; i++) {
            if (!p[i] && sp[i] < m) {
                m = sp[i];
                j = i;
            }
        }

        //p[j] = true;
        assert(j != -1);
        return j;
    };

    for (int i = 0; i < V; i++) {
        int m = find_min();     // greedily choose the min vertex
        p[m] = true;

        // relax neighbours
        for (int j = 0; j < V; j++) {
            if (g[m][j]) {
                sp[j] = min(sp[j], g[m][j] + sp[m]); // relax weight, decrease key
            }
        }
    }
}
/* Complexity of dijkstra naive is V2 with ajd list representation  can be brought down to  (V+E) logV with a binary heap */

int main()
{
    int V = 9;
    vector<vector<int>>g 
        {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

    vector<int> sp(V, INT_MAX); // yet to relax
    dijkstra(0, g, sp);

    for (int i  = 0; i < V; i++) {
        cout << i << ": " << sp[i] << endl;
    }

    return 0;
}
