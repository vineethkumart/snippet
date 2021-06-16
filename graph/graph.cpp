
/*
 * Any given graph problem, first pre-process the inupt and convert to adjacency list
 * Different ways of giving input:
 *  vector<vector<int>> edges where edges[i][0] <-> edges[i][1]
 *  vector<int> e, f; where e[i] <-> f[i]
 *
 *  // If V is not given, traverse through edges and find max+1
 *  vector<vector<int>> graph(V);
 *  for (auto e : edges) graph[e[0]].push_back(e[1]); graph(e[1]).push_back(e[0]);
 *
 *  for (int i = 0; i < e.size(); i++) graph(e[i]).push_back(f[i]);
 */


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

enum color_t {
    UNV, // unvi
    VIS, // visiting
    VST  // visited
};


void bfs(vector<vector<int>>& g)
{
    queue<int> q;
    bool visited[5];
    memset(visited, 0, sizeof(visited));
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int e = q.front(); q.pop();
        cout << e << endl;
        // push neighbours
        for (auto i : g[e]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs_r(bool visited[], vector<vector<int>>& g, int i)
{
    if (visited[i]) return;
    visited[i] = true;
    cout << i << endl;

    for (auto e : g[i]) {
        dfs_r(visited, g, e);
    }
}

void dfs(vector<vector<int>>& g)
{
    bool visited[5];
    memset(visited, 0, sizeof(visited));
    dfs_r(visited, g, 0);
}

// three color algorithm
bool cycle_directed_r(vector<vector<int>>& g, color_t visited[], int i)
{
    if (visited[i] == VIS) return true;
    if (visited[i] == VST) return false;

    visited[i] = VIS; // visiting

    for (auto e : g[i]) {
        if (cycle_directed_r(g, visited, e)) {
            return true;
        }
    }

    visited[i] = VST;
    return false;
}

bool cycle_r(vector<vector<int>>& g, bool visited[], int i, int parent)
{
    if (visited[i]) return true; // cycle

    visited[i] = true;

    for (auto e : g[i]) {
        if (e != parent) {
            if (cycle_r(g, visited, e, i)) return true;
        }
    }

    return false;
}

bool cycle(vector<vector<int>>& g)
{
    bool visited[g.size()];
    memset(visited, 0, sizeof(visited));

    return cycle_r(g, visited, 0, -1);
}

int main()
{
    vector<vector<int>> g(5); // adj list of the graph
    vector<int> from{0, 0, 0, 2, 3};
    vector<int> to  {1, 2, 4, 3, 4};

    for (int i = 0; i < from.size(); i++) {
        g[from[i]].push_back(to[i]);
        g[to[i]].push_back(from[i]);
    }

    bfs(g);
    cout << endl;
    dfs(g);
    cout << endl;
    cout << cycle(g);

    return 0;
}

