// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string str){
        stack<pair<char, int>> s;  // stack of char, count
        s.push(make_pair(str[0], 1));
        
        for (int i = 1; i < str.length(); i++) {
            if (!s.empty() && str[i] == s.top().first) {
                int x= ++s.top().second;
                if (x == k) {
                    s.pop();
                }
            } else {
                // push to stack
                s.push(make_pair(str[i], 1));
            }
        }
    
        string ns;
        while (!s.empty()) {
            for (int i = 0; i < s.top().second; i++) 
                ns.push_back(s.top().first);
            s.pop();
        }
        
        reverse(ns.begin(), ns.end());
        return ns;
    }
};

// { Driver Code Starts.

int main() {
    
    int k = 2;
    string s = "geegsforgeeeks";
    Solution obj;
    cout<<obj.Reduced_String(k,s)<<"\n";
    return 0;
}  // } Driver Code Ends
