#include <bits/stdc++.h>

using namespace std;

bool CheckStringsAreRotation(string s1, string s2)
{
    s1.append(s1);
    size_t found = s1.find(s2);
    if (found != string::npos) return true;
    else return false;
}

int main()
{
    string s1, s2;
    cout<<"Enter string 1\n";
    getline(cin, s1);
    cout<<"Enter string 2\n";
    getline(cin, s2);
    bool res = CheckStringsAreRotation(s1, s2);
    cout<<"Result = "<<res;
}