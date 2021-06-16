/*
 * For a DG we can use the 3 color approach to detect cycle
 * For a UG we have to skip visiting 2 way edges and hence have to remember the parent and skip the direct backedge from 2->1 when came from 1->2
 * so jut a parent is enough to detect cycle of UD
 */




#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool cycle(int i, int V, vector<int> adj[], int visited[])
	{
	    if (visited[i] == 2) return false;
	    if (visited[i] == 1) return true; // cycle
	    
	    visited[i] = 1; // visiting
	    
	    for (auto e : adj[i]) {
	        if (cycle(e, V, adj, visited)) return true;
	    }
	    
	    // backtrack
	    visited[i] = 2; // completely visited.
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    int visited[V];
	    memset(visited, 0, sizeof(visited));
	    
	    for (int i = 0; i < V; i++) {
	        if (!visited[i] && cycle(i, V, adj, visited)) return true;
	    }
	    
	    return false;
	}
};
