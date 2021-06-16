
/* Finding strongly connected components of graph
 * Whats the idea?
 * Do a topo sort, get the result in a stack.
 * So you get a topo ordering, if its strongly connected, you should still be able to get a topo ordering in the transpose graph due to cyclic dependency
 * if you get same topo order, then its strongly connected
 * If you dont' then what all you are getting in one dfs is a SCC and take the next unvisited node
 * */

/* Also not that if given graph has only one SCC, then a dfs from any node will give you a tree with all nodes in it
 * but if it has more SCC, might produce a tree and forest based on from where you are doing DFS
 * */

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cassert>

using namespace std;

void dfs(int i, vector<vector<int>> &g, bool visited[], stack<int>* s)
{
    assert(!visited[i]);
    visited[i] = true;

    for (auto e : g[i]) {
        if (!visited[e]) dfs(e, g, visited, s);
    }

    if (s)
        s->push(i);
}

int sccs(vector<vector<int>>& g)
{
    stack<int> s;
    bool visited[g.size()];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < g.size(); i++) {
        if (!visited[i])
            dfs(i, g, visited, &s);
    }

    memset(visited, 0, sizeof(visited));
    int scc(0);

    // transpose the graph
    vector<vector<int>> g1(g.size());
    for (int i = 0; i < g.size(); i++) {
        for (auto e : g[i]) {
            g1[e].push_back(i);
        }
    }

    while (!s.empty()) {
        int el = s.top(); s.pop();

        if (!visited[el]) {
            scc++;
            dfs(el, g1, visited, 0);
        }

    }

    return scc;
}

int main()
{
    int n = 5;
    vector<vector<int>> g(n);
    g[0].push_back(2);
    g[0].push_back(3);
    g[1].push_back(0);
    g[2].push_back(1);
    g[3].push_back(4);
    //g[4].push_back(0);
    int s = sccs(g);

    cout << s;
    return 0;
}
