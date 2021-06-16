// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        int reach(vector<vector<int>>& edges, int n, int s, int d, bool visited[])
        {
            if (s == d) return 1;
            if (visited[s]) return 0;
            visited[s] = 1;

            int count(0);
            for (auto i : edges[s]) {
                count += reach(edges, n, i, d, visited);
            }

            visited[s] = 0;
            return count;

        }
        // Here the edges are given as there is a directed edge from edges[i][0] -> edges[i][1] so convert this into adj list first
        // pre process the input.
        int possible_paths(vector<vector<int>>edges, int n, int s, int d){
            bool visited[n];
            vector<vector<int>> e(n);
            for (auto i: edges) {
                e[i[0]].push_back(i[1]);
            }

            memset(visited, 0, sizeof(visited));
            return reach(e, n, s, d, visited);
        }
};


/* The visited array is a must for undirected graph as 1->2 ad 2->1 edges are there have to skip going back to 1 again. Or we can use a parent vertex to skip the path back,
 * provided there are no cycles in the graph
 * For a Directed graph, visited is required if its not a DAG, if its a DAG visited is not required at all.
 * How to check if given graph is DAG? check for cycles using the 3 color algorithm

