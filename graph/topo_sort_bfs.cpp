
/* can be done using DFS as well, push to a vector, reverse and print. push after processing all the dependent children */

/*
Note: we can do this using a single Queue
and user a marker if we want to print the level number
of assign levels

If we just want to do topo sort, use a single queue and no marker also required

Kahn’s algorithm for Topological Sorting
*/	
	
// This assumes no cycle and its a DAG. we can enhance this to have visited flag and fail the topo sort or don't honour the backedge
// use a visited array for this
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int dep[V];
	    memset(dep, 0, sizeof(dep));
	    
	    vector<int> ret;
	    for (int i = 0; i < V; i++) {
	        for (auto j : adj[i]) {
	            dep[j]++;
	        }
	    }
	    
	    // Will use 2 queus and swap
	    queue<int> q1;
	    queue<int> q2;
	    
	    queue<int>* cur, *next;
	    cur  = &q1;
	    next = &q2;
	    
	    for (int i = 0; i < V; i++) {
	        if (dep[i] == 0) {
	            cur->push(i);
	        }
	    }
	    
	    while (!cur->empty()) {
	        // pop and print
	        ret.push_back(cur->front()); 
	        
	        // visit all neighbours, reduce dependency
	        for (auto n : adj[cur->front()]) {
	            if (dep[n] == 0) exit(1);
	            dep[n]--;
	            if (!dep[n]) next->push(n);
	        }
	        
	        cur->pop();
	        if (cur->empty()) swap(cur, next);
	    }

	    return ret;
	}
