#include <bits/stdc++.h>

using namespace std;

bool CheckIfStringsEditDistanceIsOne(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    
    if (abs(m - n) > 1) return false;

    int i = 0, j = 0, count = 0;   
    while (i < m && j < n)
    {
        if (s1[i] != s2[j])
        {
            count++;
            if (count > 1) return false;

            if (m > n) i++;
            else if (n < m) j++;
            else 
            {
                i++; j++;
            }
        }
        else
        {
            i++; 
            j++;
        }
    }
    
    return true;
}

int main ()
{
    string s1, s2;
    cout<<"Enter first string\n";
    getline(cin, s1);
    cout<<"Enter second string\n";
    getline(cin, s2);
    cout<<"Result = "<<CheckIfStringsEditDistanceIsOne(s1, s2);
}