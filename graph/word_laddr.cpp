#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;


int ladderLength(string s, string e, vector<string>& words)
{
    // create a dict to store the words for constant lookup
    unordered_map<string, bool> dict;
    for (auto i : words) {
        dict[i] = false; // none visited
    }

    queue<string> q;
    q.push(s);

    auto push_adj = [&](string s)
    {
        for (int i = 0; i < s.size(); i++) {
            char o = s[i];
            for (char c = 'a'; c <= 'z'; c++) {
                s[i] = c;
                if (dict.find(s) != dict.end() && dict[s] == false) {
                    dict[s] = true;
                    q.push(s);
                }
            }
            s[i] = o;
        }
    };

    int level(1);

    while (!q.empty()) {
        for (int i = 0; i < q.size(); i++) {
            auto el = q.front(); q.pop();
            if (el == e) return level; // found
            push_adj(el);
        }
        level++;
    }

    return level;
}
int main()
{
    vector<string> l{"hot","dot","dog","lot","log","cog"};
    cout << ladderLength("hit", "cog", l);
    return 0;
}
