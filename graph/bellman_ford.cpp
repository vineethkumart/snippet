/*
 * Single source shortest path on a graph with -ve edge weight - O(VE)
 * */


/* Dijkstra works in VlogV time like sorting as its greedy in nature. but works only on +ve edge weight graph
 * This is a greedy approach and local optimal solution leads to global optimal as there are no -ve edge weights */

/* Bellman Ford Algorithm
 * ----------------------
 *  Uses DP by considering paths from all neighbours and relaxes V-1 times. VE is the complexity
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

void bellman(vector<vector<pair<int, int>>>& g, vector<int>& sp, int s)
{
    int V = g.size();
    sp[s] = 0;

    for (int i = 1; i <= V-1; i++) {
        // relax the weight of all the edges
        for (int a = 0; a < V; a++) {
            for (auto b : g[a]) {
                if (sp[a] != INT_MAX)
                    sp[b.first] = min(sp[b.first], sp[a] + b.second);
            }
        }
    }

    // check for negative cycle if so report it
    for (int a = 0; a < V; a++) {
        for (auto b : g[a]) {
            if (sp[a] != INT_MAX)
                if (sp[a] + b.second < sp[b.first]) {
                    assert(0 && "neg cycle");
                }
        }
    }
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> g(V);
    vector<int> sp(V, INT_MAX);

    g[0].push_back(make_pair(1,-1));
    g[0].push_back(make_pair(2,4));

    g[1].push_back(make_pair(2,3));
    g[1].push_back(make_pair(3,2));
    g[1].push_back(make_pair(4,2));

    g[3].push_back(make_pair(1,1));
    g[3].push_back(make_pair(2,5));

    g[4].push_back(make_pair(3,-3));

    bellman(g, sp, 0); // shortest path from 0 to all nodes
    for (int i  = 0; i < V; i++) {
        cout << i << ": " << sp[i] << endl;
    }

    return 0;
}
