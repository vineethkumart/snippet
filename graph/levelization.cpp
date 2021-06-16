#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cassert>

using namespace std;

// assuming no cycles
int dfs(g, int i, int level[], int cl)
{
    if (cl > level[i]) level[i] = cl;
    else return; // no need to further relax

    for (auto e : g[i]) {
        dfs(g, e, level, cl+1);
    }
}

// DFS levelization is exponential as you are visiting the same node multiple times and traversing and levelizing neighbours
//
// BFS is linear in time - use bfs for levelization

/*
 *This dfs based approach is the bruteforce approach in graph theory where you are not memorizing/ keeping a visited flag
 *
 *
 *
 */

void bfs_levelize() // can be done using kahns algo, assign level when you are popping off the queue
int main()
{
    vector<vector<int>> g(4);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(2);
    g[2].push_back(3);

    int level[4];
    levelize(g, level);
}
