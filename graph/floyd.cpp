/*
 * This solved all pairs shortest path - must know algorithm and is simple
 *
 *
 *  dp[i][j] is the shortest path between i ---> j
 *  dp[i][j] = wij if i->j
 *  dp[i][i] = 0;
 *  else all INT_MAX
 *  and then relax through each possible k vertex in between
 *
 *
 *  COmplexity V3 and space V2
 *  
 *
 *
 */


#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

void floyd(vector<vector<pair<int, int>>>& g, vector<vector<int>>& dp)
{
    int V = g.size();
    for (int i  = 0; i < V; i++) dp[i][i] = 0;

    for (int a = 0; a < V; a++) {
        for (auto b : g[a]) {
            dp[a][b.first] = b.second;
        }
    }


    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> g(V);
    vector<vector<int>> sp(V, vector<int>(V, INT_MAX));

    g[0].push_back(make_pair(1,-1));
    g[0].push_back(make_pair(2,4));

    g[1].push_back(make_pair(2,3));
    g[1].push_back(make_pair(3,2));
    g[1].push_back(make_pair(4,2));

    g[3].push_back(make_pair(1,1));
    g[3].push_back(make_pair(2,5));

    g[4].push_back(make_pair(3,-3));

    floyd(g, sp); // shortest path from 0 to all nodes
    for (int i  = 0; i < V; i++) {
        for (int j  = 0; j < V; j++) {
            cout << i << "->"  << j << ": " << sp[i][j] << endl;
        }
    }

    return 0;
}
  
