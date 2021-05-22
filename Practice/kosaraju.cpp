class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    
    void dfs(int v, vector<int> adj[], int visited[], stack<int>& nodes)
    {
        if (visited[v]) return;
        visited[v] = true;
       
        for (auto u : adj[v]) {
            dfs(u, adj, visited, nodes);
        }
        nodes.push(v);
    }
    
    void transpose(vector<int> adj[], vector<int> tran[], int v)
    {
        for (int i = 0; i < v; i++) {
            for (auto j : adj[i]) {
                tran[j].push_back(i);
            }
        }
    }
    
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> tran[V];
        transpose(adj, tran, V);
        
        int visited[V];
        memset(visited, 0, sizeof(visited));
    
        int rvisited[V];
        memset(rvisited, 0, sizeof(rvisited));
            
        int count(0);
        stack<int> s;
        for (int i = 0; i < V; i++) {
            dfs(i, adj, visited, s);
        }
         
            while (!s.empty()) {
                stack<int> ns;
                dfs(s.top(), tran, rvisited, ns);
                if (!ns.empty()) count++;
                while (!ns.empty()) ns.pop();
                s.pop();
            }
        
        
        return count;
            
    }
};