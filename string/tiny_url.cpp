#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// Function to generate a short url from integer ID
string idToShortURL(long long int n) {
    int base = 62;
    string s;
    while (n) {
        int c = n % base;
        if (c < 26) {
            s.push_back('a' + c);
        } else if (c < 52) {
            s.push_back('A' + c-26);
        } else {
            s.push_back('0' + c-52);
        }
        n = n / base;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    long long int n;
    cin >> n;
    cout << idToShortURL(n);
}
