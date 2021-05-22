#include <iostream>
#include <string>
using namespace std;


void permute(string str, string perm)
{
    if (str.empty()) {
        cout << perm << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        // swap str[0] with str[i]
        std::swap(str[0], str[i]);
        perm.push_back(str[0]);
        permute(str.substr(1), perm);
        perm.pop_back();        //backtrack
    }
}


int main()
{
    char str[] = "abcdef";
    string perm = "";
    permute(str, perm);
}
