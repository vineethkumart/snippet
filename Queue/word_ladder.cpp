/*
 * GIven a dictionary of words and begin word and end word. You can make one modification to a word at a time, one character
 * How many minimum state changes required to reach to end word */


class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_map<string, bool> dict;
            for (auto w : wordList) dict[w] = false;
            queue<string> q;
            q.push(beginWord);

            auto push_children = [&](string el) -> void
            {
                for (int i = 0; i < el.size(); i++) {
                    auto t = el[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        el[i] = c;
                        if ((dict.find(el) != dict.end()) && dict[el] == false) {
                            q.push(el);
                            dict[el] = true;
                        }
                    }
                    el[i] = t;
                }
            };

            int level(1);
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    auto el = q.front(); q.pop();
                    if (el == endWord) return level; // found.
                    push_children(el);
                }

                level++;
            }

            return 0;
        }
};
