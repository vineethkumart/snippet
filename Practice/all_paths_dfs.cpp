
#include<iostream>
#include <set>
#include <vector>
using namespace std;

class graph_t {
public:
    graph_t(int v) {
        V = v;
        list = new set<int>[V];
    }
    
    ~graph_t() { delete[] list; list = 0; }
    
    void addEdge(int u, int v) {
        list[u].insert(v);
        list[v].insert(u);
    }
    
    void printPath(int u, int v) {
        int visited[V];
        vector<int> path;
        memset(visited, 0, sizeof(visited));
        printPath(u, v, visited, path);
    }

    void printPath(int u, int v, int visited[], vector<int>& path);
    
    template<typename lambda>
    void forEachNeighbour(int u, lambda f) {
        for (auto i : list[u]) {
            f(i);
        }
    }
    
private:
  int V;
  set<int>* list;
};

void graph_t::printPath(int u, int v, int visited[], vector<int>& path)
{
    if (visited[u]) return;
    
    // found a path
    if (u == v) {
        for (auto i : path) { cout << i << ", ";}
        cout << v << endl;
        return;
    }
    
    // visit
    visited[u] = true;
    path.push_back(u);
    
    forEachNeighbour(u, [&](int n) {
        printPath(n, v, visited, path);
    });
    
    // backtrack
    visited[u] = false;
    path.pop_back();
}

int main()
{
    graph_t g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.printPath(0,3);
    return 0;
}