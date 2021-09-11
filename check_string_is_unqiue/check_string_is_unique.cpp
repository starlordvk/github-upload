#include <bits/stdc++.h>

using namespace std;

bool checkUnique(string str)
{
    bool charSet[256]{0};
    for (int i = 0; i < str.length(); i++)
    {
        if (charSet[str[i] - '0'] == 1) return false;
        
        charSet[str[i] - '0'] = 1;
    }
    return true;
}


int main()
{
    string str;
    cout<<"Enter a string\n";
    getline(cin, str);
    bool checkRes = checkUnique(str);
    cout<<"Result = "<<checkRes<<"\n";        
}