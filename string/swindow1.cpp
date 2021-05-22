
/*
 *  Find minimum window in a string containing another string/ same chars of the string
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findSubString(string str)
    {
        int count[256] = {0};
        
        if (str.length() <= 1) return str;
        int wsize(0);
        for (int i = 0; i < str.length(); i++) {
            if (!count[str[i]]) {
                count[str[i]] = 1;
                wsize++;
            }
        }
        
        memset(count, 0, sizeof(count));
        
        int window(INT_MAX);
        int cw(0);
        int start(0);
        int s, e;
        for (int i = 0; i < str.length(); i++) {
            count[str[i]]++;
            
            if (count[str[i]] == 1) cw++;
            
            if (cw == wsize) {
                // got a window
                // try to shrink
                while (count[str[start]] > 1) {
                    count[str[start]]--;
                    start++;
                }
                
                if (i - start + 1 < window) {
                    window = i-start+1;
                    s = start;
                    e = i;
                }
            }
        }
        
        return str.substr(s, e-s+1);
    }
};

int main() {
    string str("aabcbcdbca");
    Solution ob;

    cout << ob.findSubString(str).size() << endl;
    return 0;
}  // } Driver Code Ends
