int largest(int* arr, int n) 
{
	int small_on_right[n];
        int small_on_left[n];
        
        stack<int> s;
        s.push(0);
        for (int i = 1; i < n; i++) {
            while (!s.empty() && arr[i] < arr[s.top()]) {
                small_on_right[s.top()] = i;
                s.pop();
            }
            // push to stack
            s.push(i);
        }
        
        while (!s.empty()) {
            small_on_right[s.top()] = n;
            s.pop();
        }

        
        s.push(n-1);
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && arr[i] < arr[s.top()]) {
                small_on_left[s.top()] = i;
                s.pop();
            }
            // push to stack
            s.push(i);
        }
        
        
        while (!s.empty()) {
            small_on_left[s.top()] = -1;
            s.pop();
        }
    
        
        // now compute the max area possible
        long long maxa(0);
        for (int i = 0; i < n; i++) {
            long long area = arr[i] * (small_on_right[i] - small_on_left[i] - 1);
            maxa = max(maxa, area);
        }
        
        return maxa;
}
