#include <iostream>
#include <string>

using namespace std;


bool match(string s, string p)
{
    if (s.empty() && p.empty()) return true;

    // match b with .*
    if (p.empty()) return false;

    bool m = s.size() && (s[0] == p[0] || p[0] == '.');

    // if next character is *, take 2 paths
    if (p.length() >= 2 && p[1] == '*') {
        return 
            ((m && match(s.substr(1), p)) ||
            match(s, p.substr(2)));
    }

    return m && match(s.substr(1), p.substr(1));
}


int main()
{

}
