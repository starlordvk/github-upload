#include <bits/stdc++.h>

using namespace std;

const int MAX_STRING_LENGTH = 1000;

int ReplaceSpacesInString(char str[], int n)
{
    int spaceCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ') spaceCount++;
    }

    for (int i = n-1; i >= 0; i++)
    {
        int k = spaceCount * 2;
        
        if(str[i] != ' ')
        {
            str[i+k] = str[i];
        }
        else
        {
            str[i+k]  = '0';
            str[i+k-1]  = '2';
            str[i+k-2]  = '%';
            spaceCount--;
        }
    }
    return n + spaceCount * 2;
}


int main()
{
    char str[MAX_STRING_LENGTH] = "Mr John Smith    ";
    int newLength = ReplaceSpacesInString(str, 13);
    for (int i = 0; i < newLength; i++)
    {
        cout<<str[i];
    }

}