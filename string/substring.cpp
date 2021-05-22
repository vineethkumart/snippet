#include <iostream>
#include <string>

/*
 * For dp problems where you need solution of len-1 smaller substring, generate substrin this way only always.
 * */
using namespace std;
int main()
{
    string s = "abcde";
    auto const n = s.length();

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n-len; i++) {
            cout << s.substr(i, len) << endl;
        }
    }
    return 0;
}
