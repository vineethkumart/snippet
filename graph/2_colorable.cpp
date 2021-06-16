class Solution {
public:
    bool bp(int i, int V, vector<int>adj[], int color, int visited[])
    {
        if (visited[i]) return (visited[i] == color);
        visited[i] = color;
        if (color == 1) color = 2; else color = 1;
        
        for (auto e : adj[i]) {
            if (!bp(e, V, adj, color, visited)) return false;
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    int visited[V];
	    memset(visited, 0, sizeof(visited));
	    for (int i = 0; i < V; i++) {
	        if (!visited[i] && bp(i, V, adj, 1, visited) == false) return false;
	    }
	    return true;
	}
};


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

	bool isBipartite(int V, vector<int>adj[]){
	    int visited[V];
	    memset(visited, 0, sizeof(visited));

	    queue<int> q;
	    for (int i = 0; i < V; i++) {
	        if (visited[i]) continue;

    	    q.push(i);
    	    visited[i] = 1;
    	    int color = 2;
    	    while (!q.empty()) {
    	        auto size = q.size();
    	        for (int a = 0; a < size; a++) {
        	        auto e = q.front(); q.pop();
        	        for (auto p : adj[e]) {
        	            if (visited[p] && visited[p] != color) return false;
        	            if (!visited[p]) {
        	                visited[p] = color;
        	                q.push(p);
        	            }
        	        }
    	        }

    	        if (color ==1) color = 2; else color = 1;
    	    }
	    }


	   	return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);
		if(ans)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
