#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

/*
 * Bruteforce relaxation technique - exponential complexity
 * */

// dfs bruteforce approach
void sp_dfs(int i, vector<vector<pair<int, int>>>& g, vector<int>& sp, int weight/* weight bringing in*/)
{
    if (weight > sp[i]) return; // no need to relax
    //cout << "relaxing vertex " << i << "with weight: " << weight << endl;;
    sp[i] = weight;  // relax

    for (auto e : g[i]) {
        // relax neighbours
        sp_dfs(e.first, g, sp, (weight + e.second));
    }
}


int main()
{
    int V = 9;
    int graph[V][V] = 
        {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    vector<vector<pair<int,int>>> g(V); // weighted alist

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j])  g[i].push_back(make_pair(j, graph[i][j]));
        }
    }

    vector<int> sp(V, INT_MAX); // yet to relax
    sp_dfs(0, g, sp, 0/* brings 0 weight*/);

    for (int i  = 0; i < V; i++) {
        cout << i << ": " << sp[i] << endl;
    }

    return 0;
}
