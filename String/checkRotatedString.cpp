#include <bits/stdc++.h>

using namespace std;

// strstr(); uses KMP for string matching
// Time : O(n1+n2);
//49.Check one string is rotation of another

bool rotatedStrings(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    string temp = s1 + s1;
    auto it = strstr(temp.c_str(), s2.c_str());
    return it != NULL;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (rotatedStrings(s1, s2))
        cout << "Strings are rotation of each other\n";
    else
        cout << "Strings are not rotation of each other\n";
}