#include <iostream>
#include <string>
using namespace std;

bool anagram(string s1, string s2)
{
    int a[26] = {0};
    for (int i = 0; i < s1.length(); i++) {
        a[s1[i] - 'a']++;
    }

    for (int i = 0; i < s2.length(); i++) {
        if (a[s2[i] - 'a']) a[s2[i] - 'a']--;
        else return false;
    }

    for (int i = 0; i < 26; i++) if (a[i]) return false;

    return true;
}

int main()
{
    int a[26] = {0};
    string s1  = "aba";
    string s2  = "aab";
    string s3  = "aa";

    cout << anagram(s1,s2);
    //cout << anagram(s1,s3);
    cout << anagram(s2,s3);
    //cout << anagram(s3,s3);

    return 0;

}
