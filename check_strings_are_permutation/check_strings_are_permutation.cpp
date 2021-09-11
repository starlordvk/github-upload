#include <bits/stdc++.h>

using namespace std;

bool checkStrings(string str1, string str2)
{
    int charset[256]{0};
    for(int i = 0; i < str1.length(); i++)
    {
        charset[str1[i] - '0']++;
    }
    for(int i = 0; i< str2.length(); i++)
    {
        charset[str2[i]-'0']--;
    }
    for (int x : charset)
    {
        if (x != 0) return false;
    }
    return true;
}

int main()

{
    string s1, s2;
    cout<<"Enter string 1\n";
    getline(cin, s1);
    cout<<"Enter string 2\n";
    getline(cin, s2);
    bool res = checkStrings(s1, s2);
    cout<<"Result = "<<res;
}