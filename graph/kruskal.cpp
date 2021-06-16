/* Prims Minimum Spanning Tree Calculation using Prims
 * This works similar to dijkstra
 * initially start with empty set and keep adding vertex to it and stop when you have added all vertices.
 * You have to add V vertex and V-1 edge, In each iteration you will add an edge as well as a vertex
 * Use greedy and choose the min crossind edge from teh selected set to unselected set
 *
 * Complexity Normal DS: VE
 * Comlexity UF : VLogE
 * */


/*
 * dijkstra will work on directed as well as undirected graph as its based on a path and existance of path
 * dijkstra will not work with -ve edge weight case as its greedy wrt to a start node and its not MST its shortest path tree
 * MST algos will work with +ve and -ve edge weight as its greedy w.r.t choosing edge not a path
 * MST algow wont work with directed graph as it doesnt check for a continuous path. if it happens to choose a sinkless node, its stuck
 **/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

class uf_t {
public:
    uf_t(int size) {
        for (int i = 0; i < size; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void un(int i, int j) {
        int a = find(i);
        int b = find(j);
        if (rank[a] <= rank[b]) { //ubr
            parent[a] = b;
            rank[a]++;
        } else {
            parent[b] = a;
        }
    }

    int find(int i) {
        if (i == parent[i]) return i;
        int r = find(parent[i]);
        parent[i] = r; // pc

        return r;
    }
private:
    vector<int> parent;
    vector<int> rank;
};


void krus(vector<vector<int>>& g, vector<vector<int>>& mst)
{
    int V = g.size();

    typedef struct {
        int a;
        int b;
        int w;
    } e_t;

    uf_t uf(V);

    auto cmp = [](const e_t& l, const e_t& r) -> bool {
        return l.w > r.w;
    };

    priority_queue<e_t, deque<e_t>, decltype(cmp)> pq(cmp); // or can keep as sorted list as well

    // add all edges to the pq
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (g[i][j]) pq.push({i,j,g[i][j]});
        }
    }


    int i = 1;
    while (i <= V-1) // v-1 edges to choose
    {
        auto e = pq.top(); pq.pop();
        if (uf.find(e.a) == uf.find(e.b)) continue; // cycle
        uf.un(e.a, e.b);
        mst.push_back({e.a,e.b,e.w});
        i++;
    }
}

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

    vector<vector<int>> mst; //a, b, weigh
    krus(g, mst);

    int w(0);
    for (auto e: mst) {
        cout << e[0] << "->" << e[1] << ": " << e[2] << endl;
        w += e[2];
    }

    cout << "min weight: " << w;
    return 0;
}
