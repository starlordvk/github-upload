#include <bits/stdc++.h>

using namespace std;

char* RunLengthEncoding(string s)
{
    int l = s.length();

    char * newString = new char[2 * l]();
    int count = 1, i =0, k=0;
    while(i < l-1)
    {
        if(s[i] == s[i+1]) 
        {
            count++;
        }
        else
        {
            newString[k++] = s[i];
            newString[k++] = '0' + count;
            cout<<s[i]<<count<<"\n";
            count = 1;
        }
        i++;
    }
    newString[k++] = s[i];
    newString[k++] = '0' + count;
    newString[k] = '\0';
    return newString;
}

int main()
{
    string s;
    cout<<"Enter string\n";
    getline(cin, s);
    char * newString = RunLengthEncoding(s);
    cout<<"Encoded string is = ";
    for (int i = 0; newString[i] != '\0'; i++ ) cout<<newString[i];
}