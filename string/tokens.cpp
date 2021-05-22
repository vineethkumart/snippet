#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

void tokenize(string s, set<string>& dict, vector<string>& tok)
{
    if (s.empty()) { 
        for (auto i : tok) cout << i << ", ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= s.length(); i++) {
        if (dict.find(s.substr(0, i)) != dict.end()) {
            tok.push_back(s.substr(0, i));
            tokenize(s.substr(i), dict, tok);
            tok.pop_back();
        }
    }
}

int main()
{
    set<string> dict{"i", "love", "ilove", "sam", "sung", "samsung", "vineeth", "kumar", "vineethkumar"};

    for (auto in : dict) {
        vector<string> tok;
        tokenize(in, dict, tok);
    }
}

